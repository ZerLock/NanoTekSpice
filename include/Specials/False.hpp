/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-tekspice-leo.dubosclard
** File description:
** False
*/

#ifndef FALSE_HPP_
#define FALSE_HPP_

#include "Component.hpp"

class False: public Component {
    public:
        False(const std::string &name, std::size_t nbPins = 1, nts::ComponentType type = nts::FalseComponent);
        ~False();

        /**
         * @brief Compute the False component (return False)
         *
         * @param pin
         * @return nts::Tristate
         */
        nts::Tristate compute(std::size_t pin);

    protected:
    private:
};

#endif /* !FALSE_HPP_ */
