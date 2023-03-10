/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-tekspice-leo.dubosclard
** File description:
** testCircuit
*/

#include <criterion/criterion.h>
#include "Circuit.hpp"

Test (get_circuit_inputs, getInputs)
{
    Circuit c = Circuit();

    auto &res = c.getInputs();
    cr_assert_eq(res.size(), 0);
}

Test (get_circuit_components, getInputs)
{
    Circuit c = Circuit();

    auto &res = c.getComponents();
    cr_assert_eq(res.size(), 0);
}

Test (add_input_to_circuit, addComponent)
{
    Circuit c = Circuit();

    c.addComponent("input", "test");

    auto &res = c.getComponent("test");
    cr_assert_eq(res.getName(), "test");
    cr_assert_eq(res.getType(), nts::Input);
}

Test (add_component_to_circuit, addComponent)
{
    Circuit c = Circuit();

    c.addComponent("and", "test");

    auto &res = c.getComponent("test");
    cr_assert_eq(res.getName(), "test");
    cr_assert_eq(res.getType(), nts::And);
}

Test (do_not_have_true_false_in_circuit, hasTrueFalse)
{
    Circuit c = Circuit();

    cr_assert_eq(c.hasTrueFalse(), false);
}

Test (do_have_true_false_in_circuit, hasTrueFalse)
{
    Circuit c = Circuit();

    c.addComponent("true", "test");

    cr_assert_eq(c.hasTrueFalse(), true);
}
