/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** Parser
*/

#include "Parser.hpp"

Parser::Parser::Parser()
    : _chipsetList(), _linksList(), _state(none), _chipset(true)
{}

Parser::Parser::~Parser() {}

bool Parser::Parser::_checkComponent(std::string componentName) const
{
    const std::string componentList[] = {
        "and", "or", "xor", "not",
        "input", "output", "true", "false", "clock",
        "4001", "4011", "4030", "4069", "4071", "4081",
        "4008", "4013", "4017", "4040", "4094", "4512", "4514", "4801", "2716", "9999"
    };
    for (std::string tmp : componentList) {
        if (tmp == componentName) {
            return true;
        }
    }
    return false;
}

bool Parser::Parser::_verifyLinks(std::string link) const
{
    for (size_t i = 0; i < _chipsetList.size(); i++) {
        if (std::get<1>(_chipsetList[i]) == link)
            return true;
    }
    return false;
}

std::tuple<std::string, int, std::string, int> Parser::Parser::_buildTuple(std::vector<std::string> buffer)
{
    std::string link1;
    std::string link2;
    int pin1;
    int pin2;

    if (buffer[0].find(":") == std::string::npos)
        throw NtsError("Invalid syntax in links.");

    if (buffer[1].find(":") == std::string::npos)
        throw NtsError("Invalid syntax in links.");

    link1 = buffer[0].substr(0, buffer[0].find(":"));
    link2 = buffer[1].substr(0, buffer[1].find(":"));

    if (_verifyLinks(link1) == false) {
        throw NtsError("Component '" + link1 + "' does not exist and cannot be link.");
    } else if (_verifyLinks(link2) == false) {
        throw NtsError("Component '" + link2 + "' does not exist and cannot be link.");
    }

    try {
        pin1 = std::stoi(buffer[0].substr(buffer[0].find(":") + 1, buffer[0].length()));
    } catch(const std::invalid_argument &e) {
        throw NtsError("Invalid pin for component '" + link1 + "'");
    }

    try {
        pin2 = std::stoi(buffer[1].substr(buffer[1].find(":") + 1, buffer[1].length()));
    } catch (const std::invalid_argument &e) {
        throw NtsError("Invalid pin for component '" + link2 + "'");
    }
    return (make_tuple(link1, pin1, link2, pin2));
}

void Parser::Parser::_fillVector(std::string reader)
{
    std::stringstream ss(reader);
    std::string word;
    std::vector<std::string> buffer;

    while (ss >> word)
        buffer.push_back(word);

    if (buffer.size() == 2) {
        if (_state == chipsets) {
            if (_checkComponent(buffer[0]) == false)
                throw NtsError("Unknow component name '" + buffer[0] + "'.");
            if (_verifyLinks(buffer[1]) == true) {
                throw NtsError("Component '" + buffer[0] + ": " + buffer[1] + "' already exist.");
            } else
                _chipsetList.push_back(make_tuple(buffer[0], buffer[1]));
        } else if (_state == links)
            _linksList.push_back(_buildTuple(buffer));
    } else if (buffer.size() == 1) {
        throw NtsError("Component '" + buffer[0] + "' must have a name.");
    } else if (buffer.size() > 2)
        throw NtsError("Too many arguments for component '" + buffer[0] + "'.");
}

void Parser::Parser::_displayVector() const
{
    for (size_t i = 0; i < _chipsetList.size(); i++)
        std::cout << std::get<0>(_chipsetList[i]) << " " << std::get<1>(_chipsetList[i]) << std::endl;
    std::cout << std::endl;
    for (size_t i = 0; i < _linksList.size(); i++)
        std::cout << std::get<0>(_linksList[i]) << " " << std::get<1>(_linksList[i]) << " " << std::get<2>(_linksList[i]) << " " << std::get<3>(_linksList[i]) << std::endl;
}

void Parser::Parser::parseFile(std::string file, Circuit &circuit)
{
    if (file.length() < 4)
        throw NtsError("Bad file: File is not a .nts file.");
    if (file.substr(file.length() - 4, file.length()) != ".nts")
        throw NtsError("Bad file: File is not a .nts file.");
    std::ifstream ifs (file);
    std::string reader;
    if (!(ifs.good()))
        throw NtsError("Bad file: Please enter a file that does exist !");
    while (std::getline(ifs, reader)) {
        std::string formatedReader = reader.substr(0, reader.find('#'));
        if (reader[0] == '#' || reader[0] == '\n') {
            continue;
        } else if (formatedReader.substr(0, 7) == ".links:") {
            if (_chipset == false || _chipsetList.size() == 0)
                throw NtsError("Error: No chipset in nts file !");
            _state = links;
        } else if (formatedReader.substr(0, 10) == ".chipsets:") {
            _state = chipsets;
            _chipset = true;
        } else
            this->_fillVector(formatedReader);
    }

    for (size_t i = 0; i < _chipsetList.size(); i++) {
        circuit.addComponent(std::get<0>(_chipsetList[i]), std::get<1>(_chipsetList[i]));
    }
    circuit.addLinks(_linksList);

    if (_chipset == false || _chipsetList.size() == 0)
        throw NtsError("Error: No chipset in nts file !");
}
