/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** SixNot
*/

#ifndef SIXNOT_HPP_
#define SIXNOT_HPP_

#include "Component.hpp"
#include "Not.hpp"

class SixNot: public Component {
    public:
        SixNot(const std::string &name, std::size_t nbPins = 14, nts::ComponentType type = nts::SixNot);
        ~SixNot();
        nts::Tristate compute(std::size_t pin);

    protected:
    private:
};

#endif /* !SIXNOT_HPP_ */
