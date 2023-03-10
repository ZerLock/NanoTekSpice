/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** SixNot
*/

#include "SixNot.hpp"

SixNot::SixNot(const std::string &name, std::size_t nbPins, nts::ComponentType type)
    : Component(name, 14, type)
{
    (void)nbPins;
}

SixNot::~SixNot()
{
}

nts::Tristate SixNot::compute(std::size_t pin)
{
    nts::Tristate res1 = nts::Undefined;
    std::size_t pin1 = pin;
    if (pin == 7 || pin == 14) {
        _value = nts::Undefined;
    } else if (pin < 8 && pin % 2 == 0) {
        pin1 = pin - 1;
    } else if (pin >=8 && pin % 2 == 0) {
        pin1 = ++pin;
    }
    Not no = Not("not");
    if (auto link = _links.find(pin1); link != _links.end()) {
        res1 = getBridgeCompute(link->first);
    }
    _value = no.truthTable(res1);
    return _value;
}