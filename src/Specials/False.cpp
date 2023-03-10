/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-tekspice-leo.dubosclard
** File description:
** False
*/

#include "False.hpp"

False::False(const std::string &name, std::size_t nbPins, nts::ComponentType type)
    : Component(name, nbPins, type)
{}

False::~False() {}

nts::Tristate False::compute(std::size_t pin)
{
    (void)pin;
    return nts::False;
}
