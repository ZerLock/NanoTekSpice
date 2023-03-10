/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** Xor
*/

#ifndef XOR_HPP_
#define XOR_HPP_

#include "Component.hpp"

class Xor: public Component {
    public:
        Xor(const std::string &name, std::size_t nbPins = 3, nts::ComponentType = nts::Xor);
        ~Xor();

        /**
         * @brief Compute the Xor component
         *
         * @param pin
         * @return nts::Tristate
         */
        nts::Tristate compute(std::size_t pin);

        /**
         * @brief Return the computed value of Xor between two states
         *
         * @param in1
         * @param in2
         * @return nts::Tristate
         */
        nts::Tristate truthTable(nts::Tristate in1, nts::Tristate in2);

    protected:
    private:
};

#endif /* !XOR_HPP_ */
