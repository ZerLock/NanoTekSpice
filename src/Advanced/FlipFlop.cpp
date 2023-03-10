/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-tekspice-leo.dubosclard
** File description:
** FlipFlop
*/

#include "FlipFlop.hpp"

FlipFlop::FlipFlop(const std::string &name, std::size_t nbPins, nts::ComponentType type)
    : Component(name, nbPins, type), _cl(nts::Undefined), _otherOldCl(nts::Undefined), _againCl(nts::Undefined), _qValue(nts::Undefined), _qBarValue(nts::Undefined)
{}

FlipFlop::~FlipFlop() {}

nts::Tristate FlipFlop::truthTableQ(nts::Tristate isUp, nts::Tristate reset, nts::Tristate data, nts::Tristate set)
{
    if (isUp == nts::True && data == nts::False && reset == nts::False && set == nts::False) {
        return nts::False;
    }
    if (isUp == nts::True && data == nts::True && reset == nts::False && set == nts::False) {
        return nts::True;
    }
    if (isUp == nts::False && reset == nts::False && set == nts::False) {
        return _qValue;
    }
    if (reset == nts::True && set == nts::False) {
        return nts::False;
    }
    if (reset == nts::False && set == nts::True) {
        return nts::True;
    }
    if (reset == nts::True && set == nts::True) {
        return nts::True;
    }
    return nts::Undefined;
}

nts::Tristate FlipFlop::truthTableQBar(nts::Tristate reset, nts::Tristate set, nts::Tristate q)
{
    if (reset == nts::True && set == nts::True) {
        return q;
    }
    if (q == nts::True) {
        return nts::False;
    }
    if (q == nts::False) {
        return nts::True;
    }
    return nts::Undefined;
}

nts::Tristate FlipFlop::isUp(nts::Tristate current) const
{
    if (current == nts::False && (_againCl == nts::True || _againCl == nts::Undefined)) {
        return nts::False;
    }
    if (current == nts::True && (_againCl == nts::False || _againCl == nts::Undefined)) {
        return nts::True;
    }
    return nts::Undefined;
}

nts::Tristate FlipFlop::compute(std::size_t pin)
{
    // Compute all
    nts::Tristate cl = nts::Undefined;
    nts::Tristate reset = nts::Undefined;
    nts::Tristate data = nts::Undefined;
    nts::Tristate set = nts::Undefined;

    if (auto link = _links.find(3); link != _links.end()) {
        cl = getBridgeCompute(link->first);
    }
    if (auto link = _links.find(4); link != _links.end()) {
        reset = getBridgeCompute(link->first);
    }
    if (auto link = _links.find(5); link != _links.end()) {
        data = getBridgeCompute(link->first);
    }
    if (auto link = _links.find(6); link != _links.end()) {
        set = getBridgeCompute(link->first);
    }

    _qValue = truthTableQ(isUp(cl), reset, data, set);
    _qBarValue = truthTableQBar(reset, set, _qValue);

    if (pin == 2) {
        return _qValue;
    }

    _againCl = _otherOldCl;
    _otherOldCl = _cl;
    _cl = cl;

    return _qBarValue;
}
