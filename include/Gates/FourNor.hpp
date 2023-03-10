/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** FourAnd
*/

#ifndef FOURNOR_HPP_
#define FOURNOR_HPP_

#include "GatesComponent.hpp"

class FourNor: public fourGates {
    public:
        FourNor(const std::string &name, nts::ComponentType type = nts::FourNor);
        ~FourNor();

    protected:
    private:
};

#endif /* !FOURNOR_HPP_ */
