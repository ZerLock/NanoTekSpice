/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-tekspice-leo.dubosclard
** File description:
** testTrue
*/

#include <criterion/criterion.h>
#include "True.hpp"
#include "Factory.hpp"

Test (compute_true, compute)
{
    Factory factory;

    auto tmp = factory.createComponent("true", "test");
    auto res = (*tmp).compute(2);
    cr_assert_eq(res, nts::True);
}
