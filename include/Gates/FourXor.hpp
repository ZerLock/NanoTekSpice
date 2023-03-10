/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** FourAnd
*/

#ifndef FOURXOR_HPP_
#define FOURXOR_HPP_

#include "GatesComponent.hpp"

class FourXor: public fourGates {
    public:
        FourXor(const std::string &name, nts::ComponentType type = nts::FourXor);
        ~FourXor();

    protected:
    private:
};

#endif /* !FOURXOR_HPP_ */
