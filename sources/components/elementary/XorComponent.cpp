#include "../../../include/components/elementary/XorComponent.hpp"
#include "../../../include/exceptions/Errors.hpp"

nts::XorComponent::XorComponent(const std::string& name) : AComponent(name)
{
    _pins = 3;
    _state = nts::Tristate::Undefined;
}

nts::Tristate nts::XorComponent::compute(std::size_t pin)
{
    // remembe that wiith getLink we get the component linked to the pin and the pin linked to
    if (pin == 3) {
        std::pair<IComponent*, std::size_t> pin1Link = getLink(1);
        std::pair<IComponent*, std::size_t> pin2Llink = getLink(2);
        return  _state = operator_xor(pin1Link.first->compute(pin1Link.second),
                            pin2Llink.first->compute(pin2Llink.second));
        // TODO : see if update the state here... (global state + relevant pin state)
    } else if (pin == 1 || pin == 2) {
        return getLink(pin).first->compute(getLink(pin).second);
    }
    throw nts::Errors::InvalidCompute();
}

void nts::XorComponent::simulate(std::size_t tick) { (void) tick; } // not needed for this

// opearator xor -> see if like this is okay

