/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-tekspice-leo.dubosclard
** File description:
** Input
*/

#include "Input.hpp"

Input::Input(const std::string &name, std::size_t nbPins, nts::ComponentType type)
    : Component(name, nbPins, type), _oldValue(nts::Undefined), _hasChanged(false)
{}

Input::~Input() {}

void Input::setValue(nts::Tristate value)
{
    _hasChanged = true;
    _newValue = value;
}

void Input::simulate(std::size_t tick)
{
    (void)tick;

    _oldValue = _value;
    _value = _newValue;

    return;
}

nts::Tristate Input::getOldValue() const
{
    return _oldValue;
}