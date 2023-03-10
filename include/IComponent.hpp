/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-tekspice-leo.dubosclard
** File description:
** IComponent
*/

#ifndef ICOMPONENT_HPP_
#define ICOMPONENT_HPP_

#include <iostream>
#include <string>
#include <map>
#include <memory>
#include <vector>

namespace nts {

    enum Tristate {
        Undefined = (-true),
        True = true,
        False = false,
    };

    enum ComponentType {
        Input,
        Output,
        Clock,
        TrueComponent,
        FalseComponent,
        And,
        Or,
        Not,
        Xor,
        Four,
        FourAnd,
        FourOr,
        FourXor,
        FourNor,
        FourNand,
        SixNot,
        FlipFlop,
        DualFlipFlop,
        fullAdder,
    };

    struct Link;

    class IComponent {
        public:
            virtual ~IComponent() = default;

            /**
             * @brief Simulate the component
             *
             * @param tick
             */
            virtual void simulate(std::size_t tick) = 0;

            /**
             * @brief Compute the component, return the simulated value
             *
             * @param pin
             * @return nts::Tristate
             */
            virtual nts::Tristate compute(std::size_t pin) = 0;

            /**
             * @brief Set link from it and other component passed in parameter
             *
             * @param pin
             * @param other
             * @param otherPin
             */
            virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0;

            /**
             * @brief Get all links of the component
             *
             * @return std::map<std::size_t, std::vector<nts::Link>>&
             */
            virtual std::map<std::size_t, std::vector<nts::Link>> &getLinks() = 0;

            /**
             * @brief Get the name of the component
             *
             * @return std::string
             */
            virtual std::string getName() const = 0;

            /**
             * @brief Get the number of pins of the component
             *
             * @return std::size_t
             */
            virtual std::size_t getNbPins() const = 0;

            /**
             * @brief Get the type of the component
             *
             * @return ComponentType
             */
            virtual ComponentType getType() const = 0;

            /**
             * @brief Get the value of the component
             *
             * @return nts::Tristate
             */
            virtual nts::Tristate getValue() const = 0;
    };

    struct Link {
        nts::IComponent &input;
        std::size_t pin;
    };

}

#endif /* !ICOMPONENT_HPP_ */
