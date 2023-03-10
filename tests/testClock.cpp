// /*
// ** EPITECH PROJECT, 2023
// ** B-OOP-400-LYN-4-1-tekspice-leo.dubosclard
// ** File description:
// ** testClock
// */

// #include <criterion/criterion.h>
// #include "Clock.hpp"

// Test (set_clock_value, setValue)
// {
//     Input cl = Clock("test");

//     cl.setValue(nts::True);
//     cl.simulate(1);
//     cr_assert_eq(cl.getValue(), nts::True);
//     cr_assert_eq(cl.getOldValue(), nts::Undefined);
// }

// Test (simulate_clock_with_new_value, simulate)
// {
//     Clock cl = Clock("test");

//     cl.setValue(nts::True);
//     cl.simulate(1);
//     cl.simulate(2);
//     cl.simulate(3);
//     cl.setValue(nts::True);
//     cl.simulate(4);
//     cr_assert_eq(cl.getValue(), nts::True);
//     cr_assert_eq(cl.getOldValue(), nts::Undefined);
// }

// Test (simulate_classic_clock, simulate)
// {
//     Clock cl = Clock("test");

//     cl.setValue(nts::True);
//     cl.simulate(1);
//     cl.simulate(2);
//     cr_assert_eq(cl.getValue(), nts::False);
//     cr_assert_eq(cl.getOldValue(), nts::True);
// }
