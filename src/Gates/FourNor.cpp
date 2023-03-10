/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** FourAnd
*/

#include "FourNor.hpp"

FourNor::FourNor(const std::string &name, nts::ComponentType type)
    : fourGates(name, 14, type)
{}

FourNor::~FourNor()
{}
