/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-tekspice-leo.dubosclard
** File description:
** True
*/

#include "True.hpp"

True::True(const std::string &name, std::size_t nbPins, nts::ComponentType type)
    : Component(name, nbPins, type)
{}

True::~True() {}

nts::Tristate True::compute(std::size_t pin)
{
    (void)pin;
    return nts::True;
}
