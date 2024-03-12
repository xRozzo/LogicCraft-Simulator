#include "../../include/components/AComponent.hpp"
#include "../../include/exceptions/Errors.hpp"
#include <utility>

void nts::AComponent::setLink(std::size_t pin, nts::IComponent& other, std::size_t otherPin) {
    // Check if the link already exists to prevent an infinite loop
    if (_links.find(pin) != _links.end() && _links[pin].first == &other && _links[pin].second == otherPin) {
        return;
    }
    
    if (isValidPin(pin, other, otherPin)) {
        _links[pin] = {&other, otherPin};
        other.setLink(otherPin, *this, pin); // SET LINK BACK
    } else {
        throw nts::Errors::LinkError("Invalid pin provided to AComponent::setLink");
    }
} // Link components: one pin of a component to another pin of another component

std::pair<nts::IComponent*, std::size_t> nts::AComponent::getLink(std::size_t pin) const
{
    if (_links.find(pin) == _links.end()) {
        throw std::runtime_error("Pin not linked");
    }
    return _links.at(pin);
} // get the link of a pin

nts::Tristate nts::AComponent::getState() const { return _state; }

std::size_t nts::AComponent::getPins() const { return _pins; }

bool nts::AComponent::isValidPin(std::size_t pin, nts::IComponent &other, std::size_t otherPin) const
{
    if (pin > _pins || otherPin > other.getPins())
        return false;
    return true;
} // check if the pin is valid

nts::Tristate nts::AComponent::operator_and(nts::Tristate a, nts::Tristate b)
{
    if (a == nts::Tristate::False || b == nts::Tristate::False) {
        return nts::Tristate::False;
    }
    if (a == nts::Tristate::Undefined || b == nts::Tristate::Undefined) {
        return nts::Tristate::Undefined;
    }
    return nts::Tristate::True;
}

nts::Tristate nts::AComponent::operator_or(nts::Tristate a, nts::Tristate b)
{
    if (a == nts::Tristate::True || b == nts::Tristate::True) {
        return nts::Tristate::True;
    }
    if (a == nts::Tristate::Undefined || b == nts::Tristate::Undefined) {
        return nts::Tristate::Undefined;
    }
    return nts::Tristate::False;
}


nts::Tristate nts::AComponent::operator_xor(nts::Tristate a, nts::Tristate b)
{
    if (a == nts::Tristate::Undefined || b == nts::Tristate::Undefined) {
        return nts::Tristate::Undefined;
    }

    if (a == nts::Tristate::True || b == nts::Tristate::True) {
        if (a == nts::Tristate::True && b == nts::Tristate::True) {
            return nts::Tristate::False;
        }
        return nts::Tristate::True;
    }

    return nts::Tristate::False;
}

nts::Tristate nts::AComponent::operator_not(nts::Tristate a)
{
    if (a == nts::Tristate::False) {
        return nts::Tristate::True;
    } else if (a == nts::Tristate::True) {
        return nts::Tristate::False;
    }
    return nts::Tristate::Undefined;
}

void nts::AComponent::setState(nts::Tristate state) {}

std::string nts::AComponent::getType() const { return _name; }

void nts::AComponent::simulate(std::size_t tick) { (void) tick; }
