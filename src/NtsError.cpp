/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-tekspice-leo.dubosclard
** File description:
** NtsError
*/

#include "NtsError.hpp"

NtsError::NtsError(const std::string &msg) noexcept
    : _msg(msg)
{}

NtsError::~NtsError() {}

const char *NtsError::what() const noexcept
{
    return _msg.c_str();
}
