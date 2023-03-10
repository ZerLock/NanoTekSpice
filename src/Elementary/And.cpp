/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** And
*/

#include "And.hpp"

And::And(const std::string &name)
    : Component(name, 3, nts::And)
{}

nts::Tristate And::truthTable(nts::Tristate in1, nts::Tristate in2)
{
    if (in1 == in2) {
        return in1;
    }
    if (in1 == nts::False || in2 == nts::False) {
        return nts::False;
    }
    return nts::Undefined;
}

nts::Tristate And::compute(std::size_t pin)
{
    (void)pin;
    nts::Tristate in1 = nts::Undefined;
    nts::Tristate in2 = nts::Undefined;
    if (auto link1 = _links.find(1); link1 != _links.end()) {
        in1 = getBridgeCompute(link1->first);
    }
    if (auto link2 = _links.find(2); link2 != _links.end()) {
        in2 = getBridgeCompute(link2->first);
    }
    _value = truthTable(in1, in2);
    return _value;
}

And::~And() {}
