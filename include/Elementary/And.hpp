/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** And
*/

#ifndef AND_HPP_
#define AND_HPP_

#include "Component.hpp"
#include "Input.hpp"
#include "Output.hpp"

class And: public Component {
    public:
        And(const std::string &name);
        ~And();

        /**
         * @brief Compute the and component
         *
         * @param pin
         * @return nts::Tristate
         */
        nts::Tristate compute(std::size_t pin);

        /**
         * @brief Return the computed value of And between two states
         *
         * @param in1
         * @param in2
         * @return nts::Tristate
         */
        nts::Tristate truthTable(nts::Tristate in1, nts::Tristate in2);

    protected:
    private:
};

#endif /* !AND_HPP_ */
