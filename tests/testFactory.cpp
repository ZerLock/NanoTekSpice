/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-tekspice-leo.dubosclard
** File description:
** testFactory
*/

#include <criterion/criterion.h>
#include "Factory.hpp"
#include "True.hpp"
#include "NtsError.hpp"

Test (create_good_component, create)
{
    Factory factory;
    std::string name = "test";

    auto tmp = factory.create<True>(name);
    cr_assert_eq((*tmp).getType(), nts::TrueComponent);
    cr_assert_eq((*tmp).getName(), name);
}

Test (create_good_component_global, createComponent)
{
    Factory factory;
    std::string name = "test";

    auto tmp = factory.createComponent("true", name);
    cr_assert_eq((*tmp).getType(), nts::TrueComponent);
    cr_assert_eq((*tmp).getName(), name);
}

Test (create_bad_component_global, createComponent)
{
    Factory factory;
    std::string name = "test";
    char *tmp = NULL;

    try {
        auto tmp = factory.createComponent("zebi", name);
    } catch (const NtsError &e) {
        tmp = strdup(e.what());
    }
    cr_assert_str_eq(tmp, "Zebi tu cherches la merde ou quoi ?");

    if (tmp) free(tmp);
}
