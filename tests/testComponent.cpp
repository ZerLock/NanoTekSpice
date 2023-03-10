/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-tekspice-leo.dubosclard
** File description:
** testComponent
*/

#include <criterion/criterion.h>
#include "Component.hpp"

Test (get_name, getName)
{
    std::string customName = "lorem ipsum";
    Component comp = Component(customName, 2, nts::FalseComponent);

    cr_assert_eq(comp.getName(), customName);
}

Test (get_type, getType)
{
    nts::ComponentType customType = nts::FalseComponent;
    Component comp = Component("_", 2, customType);

    cr_assert_eq(comp.getType(), customType);
}

Test (get_number_of_pins, getNbPins)
{
    std::size_t nbPins = 2;
    Component comp = Component("_", nbPins, nts::FalseComponent);

    cr_assert_eq(comp.getNbPins(), nbPins);
}

Test (get_links_map, getLinks)
{
    Component comp = Component("_", 2, nts::FalseComponent);

    auto &tmp = comp.getLinks();
    cr_assert_eq(tmp.size(), 0);
}

Test (compute_component, compute)
{
    Component comp = Component("_", 2, nts::FalseComponent);

    cr_assert_eq(comp.compute(1), nts::Undefined);
}

Test (simulate_with_good_tick, simulate)
{
    Component comp = Component("_", 2, nts::FalseComponent);

    comp.simulate(1);
    cr_assert_eq(comp.compute(1), nts::Undefined);
}

Test (simulate_with_bad_tick, simulate)
{
    Component comp = Component("_", 2, nts::FalseComponent);

    comp.simulate(0);
    cr_assert_eq(comp.compute(1), nts::Undefined);
}

Test (simulate_with_links, simulate)
{
    Component comp1 = Component("1", 2, nts::FalseComponent);
    Component comp2 = Component("2", 2, nts::Output);

    comp1.setLink(1, comp2, 1);
    comp2.setLink(1, comp1, 1);

    comp1.simulate(0);
    cr_assert_eq(comp1.compute(1), nts::Undefined);
}

Test (set_link, setLinks)
{
    Component comp1 = Component("1", 2, nts::FalseComponent);
    Component comp2 = Component("2", 2, nts::Output);

    comp1.setLink(1, comp2, 1);
    comp2.setLink(1, comp1, 1);

    cr_assert_eq(comp1.getLinks().size(), 1);
    cr_assert_eq(comp2.getLinks().size(), 1);
}
