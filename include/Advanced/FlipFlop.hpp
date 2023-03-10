/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-tekspice-leo.dubosclard
** File description:
** FlipFlop
*/

#ifndef FLIPFLOP_HPP_
#define FLIPFLOP_HPP_

#include "Component.hpp"
#include "And.hpp"
#include "Not.hpp"

class FlipFlop: public Component {
    public:
        FlipFlop(const std::string &name, std::size_t nbPins = 6, nts::ComponentType type = nts::FlipFlop);
        ~FlipFlop();

        /**
         * @brief Return the computed value for the first output of FlipFlop (Q)
         *
         * @param isUp
         * @param reset
         * @param data
         * @param set
         * @return nts::Tristate
         */
        nts::Tristate truthTableQ(nts::Tristate isUp, nts::Tristate reset, nts::Tristate data, nts::Tristate set);

        /**
         * @brief Return the computed value for the second output of FlipFlop using the first output
         *
         * @param reset
         * @param set
         * @param q
         * @return nts::Tristate
         */
        nts::Tristate truthTableQBar(nts::Tristate reset, nts::Tristate set, nts::Tristate q);

        /**
         * @brief Return if the clock is Up, Down or constant
         *
         * @param current
         * @return nts::Tristate
         */
        nts::Tristate isUp(nts::Tristate current) const;

        /**
         * @brief Compute the FlipFlop component
         *
         * @param pin
         * @return nts::Tristate
         */
        nts::Tristate compute(std::size_t pin);

    private:
        nts::Tristate _cl;
        nts::Tristate _otherOldCl;
        nts::Tristate _againCl;
        nts::Tristate _qValue;
        nts::Tristate _qBarValue;
};

#endif /* !FLIPFLOP_HPP_ */
