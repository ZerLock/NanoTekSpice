/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-tekspice-leo.dubosclard
** File description:
** testAnd
*/

#include <criterion/criterion.h>
#include "Factory.hpp"
#include "And.hpp"

Test (and_component_with_undefined_and_undefined, compute)
{
    Factory f;
    auto tmp = f.createComponent("and", "test");
    auto res = (*tmp).compute(1);
    cr_assert_eq(res, nts::Undefined);
}
