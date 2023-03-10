/*
** EPITECH PROJECT, 2023
** *
** File description:
** DualFlipFlop
*/

#ifndef DUALFLIPFLOP_HPP_
#define DUALFLIPFLOP_HPP_

#include "Component.hpp"
#include "FlipFlop.hpp"

class DualFlipFlop: public Component {
    public:
        DualFlipFlop(const std::string &name, std::size_t nbPins = 14, nts::ComponentType type = nts::DualFlipFlop);
        ~DualFlipFlop();

    private:
        FlipFlop ff1 = FlipFlop("ff1");
        FlipFlop ff2 = FlipFlop("ff2");
};

#endif /* !DUALFLIPFLOP_HPP_ */
