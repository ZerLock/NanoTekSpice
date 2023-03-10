/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** fullAdder
*/

#ifndef FULLADDER_HPP_
#define FULLADDER_HPP_

#include "Component.hpp"
#include "Xor.hpp"
#include "Or.hpp"
#include "And.hpp"

class fullAdder: public Component {

    public:
        fullAdder(const std::string &name, std::size_t nbPins = 16, nts::ComponentType type = nts::fullAdder);
        ~fullAdder();

        nts::Tristate getCarryOn() const;
        nts::Tristate compute(std::size_t pin);
    private:
        nts::Tristate _carryOn;
};


#endif /* !FULLADDER_HPP_ */
