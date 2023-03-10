/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** FourAnd
*/

#ifndef FOUROR_HPP_
#define FOUROR_HPP_

#include "GatesComponent.hpp"

class FourOr: public fourGates {
    public:
        FourOr(const std::string &name, nts::ComponentType type = nts::FourOr);
        ~FourOr();

    protected:
    private:
};

#endif /* !FOUROR_HPP_ */
