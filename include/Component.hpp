/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-tekspice-leo.dubosclard
** File description:
** Component
*/

#ifndef Component_HPP_
#define Component_HPP_

#include "IComponent.hpp"
#include <map>
#include <vector>

class Component: public nts::IComponent {
    public:
        Component(const std::string &name, std::size_t nbPins, nts::ComponentType type);
        ~Component();

        /**
         * @brief Simulate the component
         *
         * @param tick
         */
        void simulate(std::size_t tick);

        /**
         * @brief Compute the component, return the simulated value
         *
         * @param pin
         * @return nts::Tristate
         */
        nts::Tristate compute(std::size_t pin);

        /**
         * @brief Set link from it and another component passed in parameter
         *
         * @param pin
         * @param other
         * @param otherPin
         */
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);

        /**
         * @brief Get all links of the component
         *
         * @return std::map<std::size_t, Link>&
         */
        std::map<std::size_t, std::vector<nts::Link>> &getLinks();

        /**
         * @brief Get the name of the component
         *
         * @return std::string
         */
        std::string getName() const;

        /**
         * @brief Get the number of pins of the component
         *
         * @return std::size_t
         */
        std::size_t getNbPins() const;

        /**
         * @brief Get the type of the component
         *
         * @return nts::ComponentType
         */
        nts::ComponentType getType() const;

        /**
         * @brief Get the value of the component
         *
         * @return nts::Tristate
         */
        nts::Tristate getValue() const;

        /**
         * @brief Get the value of the compute of all links
         *
         * @return nts::Tristate
         */
        nts::Tristate getBridgeCompute(std::size_t pin) const;

    protected:
        std::string _name;
        std::size_t _nbPins;
        nts::ComponentType _type;
        std::size_t _currentTick;
        nts::Tristate _value;
        nts::Tristate _newValue;
        bool _isLocked;
        std::map<std::size_t, std::vector<nts::Link>> _links;
};

#endif /* !Component_HPP_ */
