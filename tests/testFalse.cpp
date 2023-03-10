/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-tekspice-leo.dubosclard
** File description:
** testFalse
*/

#include <criterion/criterion.h>
#include "False.hpp"
#include "Factory.hpp"

Test (compute_false, compute)
{
    Factory f;
    auto comp = f.createComponent("false", "test");
    auto res = (*comp).compute(2);
    cr_assert_eq(res, nts::False);
}
