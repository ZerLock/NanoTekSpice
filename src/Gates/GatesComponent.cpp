/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** GatesComponent
*/

#include "GatesComponent.hpp"
#include "Or.hpp"

fourGates::fourGates(const std::string &name, std::size_t nbPins, nts::ComponentType type)
    : Component(name, nbPins, type)
{}

fourGates::~fourGates()
{}

nts::Tristate fourGates::compute(std::size_t pin)
{
    nts::Tristate res1 = nts::Undefined;
    nts::Tristate res2 = nts::Undefined;
    std::size_t pin1;
    std::size_t pin2;
    if (pin == 3 || pin == 10) {
        pin1 = pin - 2;
        pin2 = pin - 1;
    } else if (pin == 4 || pin == 11) {
        pin1 = pin + 1;
        pin2 = pin + 2;
    } else if (pin == 7 || pin == 14)
        return nts::Undefined;
    if (auto link = _links.find(pin1); link != _links.end()) {
        res1 = getBridgeCompute(link->first);
    }
    if (auto link = _links.find(pin2); link != _links.end()) {
        res2= getBridgeCompute(link->first);
    }
    if (_type == nts::FourAnd) {
        And buffer = And("buffer");
        _value = buffer.truthTable(res1, res2);
    } else if (_type == nts::FourNand) {
        And buffer = And("buffer");
        Not no = Not("not");
        _value = no.truthTable(buffer.truthTable(res1, res2));
    } else if (_type == nts::FourOr) {
        Or buffer = Or("buffer");
        _value = buffer.truthTable(res1, res2);
    } else if (_type == nts::FourNor) {
        Or buffer = Or("buffer");
        Not no = Not("not");
        _value = no.truthTable(buffer.truthTable(res1, res2));
    } else if (_type == nts::FourXor) {
        Xor buffer = Xor("buffer");
        _value = buffer.truthTable(res1, res2);
    } else
        _value = nts::Undefined;
    return _value;
}
