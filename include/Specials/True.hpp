/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-tekspice-leo.dubosclard
** File description:
** True
*/

#ifndef TRUE_HPP_
#define TRUE_HPP_

#include "Component.hpp"

class True: public Component {
    public:
        True(const std::string &name, std::size_t nbPins = 1, nts::ComponentType type = nts::TrueComponent);
        ~True();

        /**
         * @brief Compute the component (return True)
         *
         * @param pin
         * @return nts::Tristate
         */
        nts::Tristate compute(std::size_t pin);

    protected:
    private:
};

#endif /* !TRUE_HPP_ */
