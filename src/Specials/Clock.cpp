/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-tekspice-leo.dubosclard
** File description:
** Clock
*/

#include "Clock.hpp"

/**
 * @brief Clock is like an Input but its value change at each simulate
 *        ----
 *        U -> 0 -> 1 -> U
 */
Clock::Clock(const std::string &name, std::size_t nbPins, nts::ComponentType type)
    : Input(name, nbPins, type)
{}

Clock::~Clock()
{}

void Clock::simulate(std::size_t tick)
{
    (void)tick;

    if (_currentTick >= tick) {
        _currentTick = tick;
        return;
    }

    _currentTick++;

    _oldValue = _value;

    if (_value == _newValue && _hasChanged == false) {
        if (_value == nts::True) {
            _value = nts::False;
            _newValue = _value;
        } else if (_value == nts::False) {
            _value = nts::True;
            _newValue = _value;
        }
        return;
    }

    _value = _newValue;

    _hasChanged = false;

    return;
}
