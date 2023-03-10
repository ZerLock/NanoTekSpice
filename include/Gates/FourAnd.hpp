/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** FourAnd
*/

#ifndef FOURAND_HPP_
#define FOURAND_HPP_

#include "GatesComponent.hpp"

class FourAnd: public fourGates {
    public:
        FourAnd(const std::string &name, nts::ComponentType type = nts::FourAnd);
        ~FourAnd();

    protected:
    private:
};

#endif /* !FOURAND_HPP_ */
