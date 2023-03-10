/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** FourAnd
*/

#include "FourNand.hpp"

FourNand::FourNand(const std::string &name, nts::ComponentType type)
    : fourGates(name, 14, type)
{}

FourNand::~FourNand()
{}
