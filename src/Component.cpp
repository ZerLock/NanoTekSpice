/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-tekspice-leo.dubosclard
** File description:
** Component
*/

#include "Component.hpp"

/*
 ** Ctor & Dtor
 */
Component::Component(const std::string &name, std::size_t nbPins, nts::ComponentType type)
    : _name(name), _nbPins(nbPins), _type(type), _currentTick(0), _value(nts::Undefined), _newValue(nts::Undefined), _isLocked(false), _links()
{}

Component::~Component() {}

void Component::simulate(std::size_t tick)
{
    (void)tick;

    // If the component is already simulated at this tick, break the recursive
    if (_isLocked) {
        _currentTick = tick;
        return;
    }

    // Lock the component
    _isLocked = true;

    for (auto &tmp : _links) {
        for (auto &link : tmp.second) {
            // Call the simulate function of the linked component
            link.input.simulate(tick);
        }
        // Compute all the links and use the truth table of Bridge to get the component's pin value
        _value = getBridgeCompute(tmp.first);
    }

    // Unlock the component
    _isLocked = false;
}

nts::Tristate Component::compute(std::size_t pin)
{
    (void)pin;
    return _value;
}

void Component::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    nts::Link newLink = {
        other,
        otherPin,
    };
    if (auto tmp = _links.find(pin); tmp != _links.end()) {
        // The pin already exist
        (*tmp).second.push_back(newLink);
    } else {
        // Create the pin and init the vector of link with the new link
        _links.emplace(pin, std::vector<nts::Link>{newLink});
    }
}

std::map<std::size_t, std::vector<nts::Link>> &Component::getLinks()
{
    return _links;
}

/*
 ** Getters
 */

std::string Component::getName() const
{
    return _name;
}

std::size_t Component::getNbPins() const
{
    return _nbPins;
}

nts::ComponentType Component::getType() const
{
    return _type;
}

nts::Tristate Component::getValue() const
{
    return _value;
}

nts::Tristate Component::getBridgeCompute(std::size_t pin) const
{
    nts::Tristate newValue = nts::Undefined;
    for (auto &link : _links.at(pin)) {
        // Call the simulate function of the linked component
        auto tmpValue = link.input.compute(link.pin);
        if ((tmpValue == nts::False && newValue == nts::True) || (tmpValue == nts::True && newValue == nts::False)) {
            newValue = nts::Undefined;
            break;
        }
        if (newValue == nts::True || tmpValue == nts::True) {
            newValue = nts::True;
            continue;
        }
        if (newValue == nts::Undefined) {
            newValue = tmpValue;
            continue;
        }
    }
    return newValue;
}
