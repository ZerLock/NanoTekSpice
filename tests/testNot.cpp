/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-tekspice-leo.dubosclard
** File description:
** testNot
*/

#include <criterion/criterion.h>
#include "Factory.hpp"

Test (not_component_with_undefined_and_undefined, compute)
{
    Factory f;

    auto tmp = f.createComponent("not", "test");
    auto res = (*tmp).compute(1);
    cr_assert_eq(res, nts::Undefined);
}
