/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-tekspice-leo.dubosclard
** File description:
** Factory
*/

#include "Factory.hpp"

Factory::Factory() : Factories()
{
    Factories["input"] = &Factory::create<Input>;
    Factories["output"] = &Factory::create<Output>;
    Factories["clock"] = &Factory::create<Clock>;
    Factories["true"] = &Factory::create<True>;
    Factories["false"] = &Factory::create<False>;
    Factories["and"] = &Factory::create<And>;
    Factories["or"] = &Factory::create<Or>;
    Factories["not"] = &Factory::create<Not>;
    Factories["xor"] = &Factory::create<Xor>;
    Factories["4081"] = &Factory::create<FourAnd>;
    Factories["4011"] = &Factory::create<FourNand>;
    Factories["4071"] = &Factory::create<FourOr>;
    Factories["4001"] = &Factory::create<FourNor>;
    Factories["4030"] = &Factory::create<FourXor>;
    Factories["4069"] = &Factory::create<SixNot>;
    Factories["4013"] = &Factory::create<DualFlipFlop>;
    Factories["9999"] = &Factory::create<FlipFlop>;
    Factories["4008"] = &Factory::create<fullAdder>;
}

Factory::~Factory() {}

std::unique_ptr<nts::IComponent> Factory::createComponent(const std::string &type, const std::string &name)
{
    if (auto tmp = Factories.find(type); tmp != Factories.end()) {
        return tmp->second(name);
    }
    throw NtsError("Zebi tu cherches la merde ou quoi ?");
}
