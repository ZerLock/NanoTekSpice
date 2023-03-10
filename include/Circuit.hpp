/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-tekspice-leo.dubosclard
** File description:
** Circuit
*/

#ifndef CIRCUIT_HPP_
#define CIRCUIT_HPP_

#include "NtsError.hpp"
#include "IComponent.hpp"
#include "Input.hpp"
#include "Clock.hpp"
#include "Factory.hpp"
#include <memory>

class Circuit {
    public:
        Circuit();
        ~Circuit();

        /**
         * @brief Get all the map of inputs
         *
         * @return std::map<std::string, std::unique_ptr<Input>>&
         */
        std::map<std::string, std::unique_ptr<Input>> &getInputs();

        /**
         * @brief Get all the map of components
         *
         * @return std::map<std::string, std::unique_ptr<nts::IComponent>>&
         */
        std::map<std::string, std::unique_ptr<nts::IComponent>> &getComponents();

        /**
         * @brief Add a component to the circuit using the factory
         *
         * @param type
         * @param name
         */
        void addComponent(const std::string &type, const std::string &name);

        /**
         * @brief Get a reference to a component using it name
         *
         * @param name
         * @return nts::IComponent&
         */
        nts::IComponent &getComponent(std::string name);

        /**
         * @brief Add all of the links in the circuit
         *
         * 0 = name of component
         * 1 = it pin number
         * 2 = name of the other component
         * 3 = other pin number
         *
         * @param linksList
         */
        void addLinks(std::vector< std::tuple<std::string, int, std::string, int> > linksList);

        /**
         * @brief Return if the circuit has True or False components
         *
         * @return true
         * @return false
         */
        bool hasTrueFalse() const;

    private:
        std::map<std::string, std::unique_ptr<Input>> _inputs;
        std::map<std::string, std::unique_ptr<nts::IComponent>> _componentList;
        Factory _factory;
};

#endif /* !CIRCUIT_HPP_ */
