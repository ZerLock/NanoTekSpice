/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-tekspice-leo.dubosclard
** File description:
** Output
*/

#ifndef OUTPUT_HPP_
#define OUTPUT_HPP_

#include "Component.hpp"

class Output: public Component {
    public:
        Output(const std::string &name, std::size_t nbPins = 1, nts::ComponentType type = nts::Output);
        ~Output();

    protected:
    private:
};

#endif /* !OUTPUT_HPP_ */
