/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** GatesComponent
*/

#ifndef GATESCOMPONENT_HPP_
#define GATESCOMPONENT_HPP_

#include "Component.hpp"
#include "And.hpp"
#include "Not.hpp"
#include "Or.hpp"
#include "Xor.hpp"

class fourGates: public Component {
    public:
        fourGates(const std::string &name, std::size_t nbPins = 14, nts::ComponentType type = nts::Four);
        ~fourGates();
        nts::Tristate compute(std::size_t pin);
};

#endif /* !GATESCOMPONENT_HPP_ */
