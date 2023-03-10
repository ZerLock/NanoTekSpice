/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** FourAnd
*/

#include "FourAnd.hpp"

FourAnd::FourAnd(const std::string &name, nts::ComponentType type)
    : fourGates(name, 14, type)
{}

FourAnd::~FourAnd()
{}
