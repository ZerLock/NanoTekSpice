/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** FourAnd
*/

#include "FourOr.hpp"

FourOr::FourOr(const std::string &name, nts::ComponentType type)
    : fourGates(name, 14, type)
{}

FourOr::~FourOr()
{}
