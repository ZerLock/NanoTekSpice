/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-tekspice-leo.dubosclard
** File description:
** Input
*/

#ifndef INPUT_HPP_
#define INPUT_HPP_

#include "Component.hpp"

class Input: public Component {
    public:
        Input(const std::string &name, std::size_t nbPins = 1, nts::ComponentType type = nts::Input);
        ~Input();

        /**
         * @brief Set the value of the component
         *
         * @param value
         */
        void setValue(nts::Tristate value);

        /**
         * @brief Override of the Component's simulate to break the recursive
         *
         * @param tick
         */
        void simulate(std::size_t tick);

        /**
         * @brief Get the old value of the input (for Clock)
         *
         * @return nts::Tristate
         */
        nts::Tristate getOldValue() const;

    protected:
        nts::Tristate _oldValue;
        bool _hasChanged;
};

#endif /* !INPUT_HPP_ */
