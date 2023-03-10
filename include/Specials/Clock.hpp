/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-tekspice-leo.dubosclard
** File description:
** Clock
*/

#ifndef CLOCK_HPP_
#define CLOCK_HPP_

#include "Input.hpp"

class Clock: public Input {
    public:
        Clock(const std::string &name, std::size_t nbPins = 1, nts::ComponentType type = nts::Clock);
        ~Clock();

        /**
         * @brief Set the value of the component
         *
         * @param value
         */
        void setValue(nts::Tristate value);

        /**
         * @brief Override of the component's simulate (change clock value at simulate)
         *
         * @param tick
         */
        void simulate(std::size_t tick);

    protected:
    private:
};

#endif /* !CLOCK_HPP_ */
