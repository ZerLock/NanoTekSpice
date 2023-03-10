/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-tekspice-leo.dubosclard
** File description:
** Or
*/

#ifndef OR_HPP_
#define OR_HPP_

#include "Component.hpp"

class Or: public Component {
    public:
        Or(const std::string &name, std::size_t nbPins = 3, nts::ComponentType type = nts::Or);
        ~Or();

        /**
         * @brief Compute the Or component
         *
         * @param pin
         * @return nts::Tristate
         */
        nts::Tristate compute(std::size_t pin);

        /**
         * @brief Return the computed value of Or between two states
         *
         * @param in1
         * @param in2
         * @return nts::Tristate
         */
        nts::Tristate truthTable(nts::Tristate in1, nts::Tristate in2);

    protected:
    private:
};

#endif /* !OR_HPP_ */
