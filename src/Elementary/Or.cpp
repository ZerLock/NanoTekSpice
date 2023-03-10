/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-tekspice-leo.dubosclard
** File description:
** Or
*/

#include "Or.hpp"

Or::Or(const std::string &name, std::size_t nbPins, nts::ComponentType type)
    : Component(name, nbPins, type)
{}

Or::~Or() {}

nts::Tristate Or::truthTable(nts::Tristate in1, nts::Tristate in2)
{
    if (in1 == nts::True || in2 == nts::True) {
        return nts::True;
    }
    if (in1 == in2) {
        return in1;
    }
    return nts::Undefined;
}

nts::Tristate Or::compute(std::size_t pin)
{
    (void)pin;
    nts::Tristate res1 = nts::Undefined;
    nts::Tristate res2 = nts::Undefined;
    if (auto link = _links.find(1); link != _links.end()) {
        res1 = getBridgeCompute(link->first);
    }
    if (auto link = _links.find(2); link != _links.end()) {
        res2 = getBridgeCompute(link->first);
    }
    return truthTable(res1, res2);
}
