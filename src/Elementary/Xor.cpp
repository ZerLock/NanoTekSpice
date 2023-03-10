/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** Xor
*/

#include "Xor.hpp"

Xor::Xor(const std::string &name, std::size_t nbPins, nts::ComponentType type)
    : Component(name, nbPins, type)
{}

Xor::~Xor()
{
}

nts::Tristate Xor::truthTable(nts::Tristate in1, nts::Tristate in2)
{
    if (in1 == in2) {
        if (in1 == nts::True) {
            return nts::False;
        }
        return in1;
    }
    if ((in1 == nts::True && in2 == nts::False) || (in1 == nts::False && in2 == nts::True)) {
        return nts::True;
    }
    return nts::Undefined;
}

nts::Tristate Xor::compute(std::size_t pin)
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
