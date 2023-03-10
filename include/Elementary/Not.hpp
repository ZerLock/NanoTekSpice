/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-tekspice-leo.dubosclard
** File description:
** Not
*/

#ifndef NOT_HPP_
#define NOT_HPP_

#include "Component.hpp"

class Not: public Component {
    public:
        Not(const std::string &name, std::size_t nbPins = 2, nts::ComponentType type = nts::Not);
        ~Not();

        /**
         * @brief Compute the not component
         *
         * @param pin
         * @return nts::Tristate
         */
        nts::Tristate compute(const std::size_t pin);

        /**
         * @brief Return the computed value of Not between two states
         *
         * @param in
         * @return nts::Tristate
         */
        nts::Tristate truthTable(nts::Tristate in);

    protected:
    private:
};

#endif /* !NOT_HPP_ */
