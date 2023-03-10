/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-tekspice-leo.dubosclard
** File description:
** Output
*/

#include "Output.hpp"

Output::Output(const std::string &name, std::size_t nbPins, nts::ComponentType type)
    : Component(name, nbPins, type)
{}

Output::~Output() {}
