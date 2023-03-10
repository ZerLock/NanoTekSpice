/*
** EPITECH PROJECT, 2023
** *
** File description:
** Not
*/

#include "Not.hpp"

Not::Not(const std::string &name, std::size_t nbPins, nts::ComponentType type)
    : Component(name, nbPins, type)
{}

Not::~Not() {}

nts::Tristate Not::truthTable(nts::Tristate in)
{
    if (in == nts::True) {
        return nts::False;
    }
    if (in == nts::False) {
        return nts::True;
    }
    return nts::Undefined;
}

nts::Tristate Not::compute(std::size_t pin)
{
    (void)pin;
    nts::Tristate in = nts::Undefined;
    if (auto link = _links.find(1); link != _links.end()) {
        in = getBridgeCompute(link->first);
    }
    _value = truthTable(in);
    return _value;
}
