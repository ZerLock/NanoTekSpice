/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-tekspice-leo.dubosclard
** File description:
** DualFlipFlop
*/

#include "DualFlipFlop.hpp"

DualFlipFlop::DualFlipFlop(const std::string &name, std::size_t nbPins, nts::ComponentType type)
    : Component(name, nbPins, type)
{
    // Link first FlipFlop
    this->setLink(1, ff1, 1);
    this->setLink(2, ff1, 2);
    this->setLink(3, ff1, 3);
    this->setLink(4, ff1, 4);
    this->setLink(5, ff1, 5);
    this->setLink(6, ff1, 6);

    // Link first FlipFlop
    this->setLink(12, ff2, 2);
    this->setLink(13, ff2, 1);
    this->setLink(11, ff2, 3);
    this->setLink(10, ff2, 4);
    this->setLink(9, ff2, 5);
    this->setLink(8, ff2, 6);
}

DualFlipFlop::~DualFlipFlop() {}
