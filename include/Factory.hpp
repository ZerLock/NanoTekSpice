/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-tekspice-leo.dubosclard
** File description:
** Factory
*/

#ifndef FACTORY_HPP_
#define FACTORY_HPP_

#include "IComponent.hpp"
#include "NtsError.hpp"
#include <map>
#include <functional>
#include <memory>

/*
 ** Specials
 */
#include "Input.hpp"
#include "Output.hpp"
#include "Clock.hpp"
#include "True.hpp"
#include "False.hpp"

/*
 ** Elementary
 */
#include "And.hpp"
#include "Or.hpp"
#include "Not.hpp"
#include "Xor.hpp"

/*
 ** Gates
 */
#include "FourAnd.hpp"
#include "FourNand.hpp"
#include "FourOr.hpp"
#include "FourNor.hpp"
#include "FourXor.hpp"
#include "SixNot.hpp"

/*
 ** Advanced
 */
#include "FlipFlop.hpp"
#include "DualFlipFlop.hpp"
#include "fullAdder.hpp"

class Factory {
    public:
        Factory();
        ~Factory();

        std::map<std::string, std::function<std::unique_ptr<nts::IComponent>(const std::string&)>> Factories;

        /**
         * @brief Create a Component object from a string (type)
         *
         * @param type
         * @param name
         * @return std::unique_ptr<nts::IComponent>
         */
        std::unique_ptr<nts::IComponent> createComponent(const std::string &type, const std::string &name);

        /**
         * @brief Template to create a component from it type and it name
         *
         * @tparam T
         * @param name
         * @return std::unique_ptr<T>
         */
        template <class T>
        static std::unique_ptr<T> create(const std::string &name)
        {
            return std::make_unique<T>(name);
        }
};

#endif /* !FACTORY_HPP_ */
