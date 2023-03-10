/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** fullAdder
*/

#include "fullAdder.hpp"

fullAdder::fullAdder(const std::string &name, std::size_t nbPins, nts::ComponentType type)
    : Component(name, nbPins, type)
{
    _carryOn = nts::Undefined;
}

nts::Tristate fullAdder::getCarryOn() const
{
    return _carryOn;
}

nts::Tristate fullAdder::compute(std::size_t pin)
{
    nts::Tristate res1 = nts::Undefined;
    nts::Tristate res2 = nts::Undefined;
    std::size_t pin1;
    std::size_t pin2;
    if (pin == 10) {
        pin1 = 7;
        pin2 = 6;
    } else if (pin == 11) {
        pin1 = 5;
        pin2 = 4;
    } else if (pin == 12) {
        pin1 = 3;
        pin2 = 2;
    } else if (pin == 13) {
        pin1 = 1;
        pin2 = 15;
    } else if (pin == 8 || pin == 16) {
        return nts::Undefined;
    }
    if (auto link = _links.find(pin1); link != _links.end()) {
        res1 = getBridgeCompute(link->first);
    }
    if (auto link = _links.find(pin2); link != _links.end()) {
        res2= getBridgeCompute(link->first);
    }
    if (auto link = _links.find(9); link != _links.end()) {
        _carryOn = getBridgeCompute(link->first);
    }
    Xor firstXor = Xor("firstXor");
    _value = firstXor.truthTable(res1, res2);
    Xor secondXor = Xor("secondXor");
    _value = secondXor.truthTable(_value, _carryOn);
    //printf("Res 1 : %d | Res 2 : %d | Carry : %d | Val : %d\n", res1, res2, _carryOn, _value);
    And secondAnd = And("secondAnd");
    nts::Tristate bufferCarry = secondAnd.truthTable(firstXor.truthTable(res1, res2), _carryOn);
    And firstAnd = And("firstAnd");
    _carryOn = firstAnd.truthTable(res1, res2);
    Or firstOr = Or("firstOr");
    _carryOn = firstOr.truthTable(bufferCarry, _carryOn);
    if (pin == 14) {
        this->compute(10);
        this->compute(11);
        this->compute(12);
        this->compute(13);
        return _carryOn;
    }
    return _value;
}

fullAdder::~fullAdder()
{}