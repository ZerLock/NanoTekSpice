/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-tekspice-leo.dubosclard
** File description:
** Circuit
*/

#include "Circuit.hpp"
#include <iostream>

Circuit::Circuit()
    : _inputs(), _componentList(), _factory()
{}

Circuit::~Circuit() {}


std::map<std::string, std::unique_ptr<Input>> &Circuit::getInputs()
{
    return _inputs;
}

std::map<std::string, std::unique_ptr<nts::IComponent>> &Circuit::getComponents()
{
    return _componentList;
}

void Circuit::addComponent(const std::string &type, const std::string &name)
{
    if (_componentList.find(name) != _componentList.end()) {
        throw NtsError("Compoenent already exists !");
    }
    if (type == "input") {
        _inputs.emplace(name, std::move(_factory.create<Input>(name)));
    } else if (type == "clock") {
        _inputs.emplace(name, std::move(_factory.create<Clock>(name)));
    } else {
        _componentList.emplace(name, std::move(_factory.createComponent(type, name)));
    }
}

nts::IComponent &Circuit::getComponent(std::string name)
{
    if (auto tmp = _componentList.find(name); tmp != _componentList.end()) {
        return (*tmp->second);
    }
    if (auto tmp = _inputs.find(name); tmp != _inputs.end()) {
        return (*tmp->second);
    }
    throw NtsError("Unknown component !");
}

void Circuit::addLinks(std::vector<std::tuple<std::string, int, std::string, int>> linksList)
{
    for (auto &tmp : linksList) {
        auto &me = getComponent(std::get<0>(tmp));
        auto &other = getComponent(std::get<2>(tmp));

        me.setLink(std::get<1>(tmp), other, std::get<3>(tmp));
        other.setLink(std::get<3>(tmp), me, std::get<1>(tmp));
    }
}

bool Circuit::hasTrueFalse() const
{
    for (auto &tmp : _componentList) {
        if (tmp.second->getType() == nts::TrueComponent || tmp.second->getType() == nts::FalseComponent) {
            return true;
        }
    }
    return false;
}
