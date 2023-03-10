/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-tekspice-leo.dubosclard
** File description:
** testSplit
*/

#include <criterion/criterion.h>
#include "IComponent.hpp"
#include "Engine.hpp"

Test (empty, mySplit)
{
    Engine engine;

    auto tmp = engine.mySplit("", ' ');
    cr_assert_eq(tmp.size(), 0);
}

Test (not_empty, mySplit)
{
    Engine engine;

    auto tmp = engine.mySplit("toto tata", ' ');
    cr_assert_eq(tmp.size(), 2);
}
