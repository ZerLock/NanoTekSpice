/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** FourAnd
*/

#ifndef FOUNRAND_HPP_
#define FOUNRAND_HPP_

#include "GatesComponent.hpp"

class FourNand: public fourGates {
    public:
        FourNand(const std::string &name, nts::ComponentType type = nts::FourNand);
        ~FourNand();

    protected:
    private:
};

#endif /* !FOURNAND_HPP_ */
