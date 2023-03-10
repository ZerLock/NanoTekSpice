/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-tekspice-leo.dubosclard
** File description:
** testInput
*/

#include <criterion/criterion.h>
#include "Input.hpp"

Test (set_new_value_and_simualate, setValue)
{
    Input input = Input("test");

    input.setValue(nts::True);
    input.simulate(1);
    cr_assert_eq(input.getValue(), nts::True);
    cr_assert_eq(input.getOldValue(), nts::Undefined);
}
