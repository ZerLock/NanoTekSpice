/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-tekspice-leo.dubosclard
** File description:
** Engine
*/

#include "Engine.hpp"

/*
 ** Signal handler
 */
static bool isLoopRunning;

static void signalHandler(int signum)
{
    (void)signum;
    if (isLoopRunning == false) {
        exit(0);
    }
    isLoopRunning = false;
}

Engine::Engine()
    : _tick(0)
{
    Commands["exit"] = [this](Circuit &circuit) { _exitEngine(circuit); };
    Commands["display"] = [this](Circuit &circuit) { _display(circuit); };
    Commands["simulate"] = [this](Circuit &circuit) { _simulate(circuit); };
    Commands["loop"] = [this](Circuit &circuit) { _loop(circuit); };

    // Debug command
    Commands["debug"] = [this](Circuit &circuit) { displayLinks(circuit); };

    isLoopRunning = false;
    signal(SIGINT, signalHandler);
}

Engine::~Engine() {}

void Engine::start(Circuit &circuit)
{
    std::string buffer = "";

    // Check if there is True or False component to simulate a first time
    if (circuit.hasTrueFalse() == true) {
        _simulate(circuit);
        _tick--;
    }

    std::cout << _prompt;
    while (std::getline(std::cin, buffer)) {
        try {
            execCommand(circuit, buffer);
        } catch (const NtsError &e) {
            std::cout << e.what() << std::endl;
        }
        if (_isExiting) {
            break;
        }
        std::cout << _prompt;
    }
}

void Engine::execCommand(Circuit &circuit, const std::string buffer)
{
    std::function<void(Circuit&)> function = Commands[buffer];
    if (function) {
        function(circuit);
    } else {
        std::vector<std::string> command = mySplit(buffer, '=');
        if (command.size() != 2 || (command[1] != "0" && command[1] != "1" && command[1] != "U")) {
            throw NtsError("Bad command");
        }
        _setInput(circuit, command[0], command[1].c_str());
    }
}

void Engine::displayLinks(Circuit &circuit)
{
    std::cout << "display links:" << std::endl;
    for (auto &tmp : circuit.getInputs()) {
        std::cout << "component:" << tmp.first << std::endl;
        std::cout << tmp.second->getLinks().size() << std::endl;
        for (auto &tmp : tmp.second->getLinks()) {
            for (auto &link : tmp.second) {
                std::cout << "pin: " << tmp.first << ", comp:" << link.input.getName() << " - " << link.pin << std::endl;
            }
        }
    }
    for (auto &tmp : circuit.getComponents()) {
        std::cout << "component:" << tmp.first << std::endl;
        std::cout << tmp.second->getLinks().size() << std::endl;
        for (auto &tmp : tmp.second->getLinks()) {
            for (auto &link : tmp.second) {
                std::cout << "pin: " << tmp.first << ", comp:" << link.input.getName() << " - " << link.pin << std::endl;
            }
        }
    }
}

/*
 ** Commands functions
 */
void Engine::_exitEngine(Circuit &circuit)
{
    (void)circuit;
    _isExiting = true;
}

void Engine::_display(Circuit &circuit)
{
    // Tick
    std::cout << "tick: " << _tick << std::endl;

    // Inputs
    std::cout << "input(s):" << std::endl;
    for (auto &tmp : circuit.getInputs()) {
        if ((*tmp.second).getType() == nts::TrueComponent || (*tmp.second).getType() == nts::FalseComponent) {
            continue;
        }
        std::cout << "  " << tmp.first << ": " << _getStringTristate(tmp.second->compute(1)) << std::endl;
    }

    // Outputs
    std::cout << "output(s):" << std::endl;
    for (auto &tmp : circuit.getComponents()) {
        if (tmp.second->getType() == nts::Output) {
            std::cout << "  " << tmp.first << ": " << _getStringTristate(tmp.second->compute(1)) << std::endl;
        }
    }
}

void Engine::_setInput(Circuit &circuit, const std::string inputName, const std::string value)
{
    for (auto &tmp : circuit.getInputs()) {
        if (tmp.first == inputName) {
            tmp.second->setValue(_getTristate(value));
            return;
        }
    }
    std::cout << "Unknown input '" << inputName << "'" << std::endl;
}

void Engine::_simulate(Circuit &circuit)
{
    _tick++;
    for (auto &tmp : circuit.getComponents()) {
        if ((*tmp.second).getType() == nts::Output) {
            (*tmp.second).simulate(_tick);
        }
    }
}

void Engine::_loop(Circuit &circuit)
{
    isLoopRunning = true;
    while (isLoopRunning == true) {
        _simulate(circuit);
        _display(circuit);
    }
    std::cout << std::endl;
}

/*
 ** Annexes functions
 */
std::vector<std::string> Engine::mySplit(const std::string str, char delim) const
{
    std::istringstream ss (str);
    std::string token;
    std::vector<std::string> res = {};

    while (std::getline(ss, token, delim)) {
        res.push_back(token);
    }
    return res;
}

nts::Tristate Engine::_getTristate(std::string value)
{
    if (value == "1") {
        return nts::True;
    }
    if (value == "0") {
        return nts::False;
    }
    return nts::Undefined;
}

std::string Engine::_getStringTristate(nts::Tristate state)
{
    if (state == nts::True) {
        return "1";
    }
    if (state == nts::False) {
        return "0";
    }
    return "U";
}
