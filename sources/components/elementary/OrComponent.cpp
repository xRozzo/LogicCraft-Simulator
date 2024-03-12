#include "../../../include/components/elementary/OrComponent.hpp"
#include "../../../include/exceptions/Errors.hpp"

nts::OrComponent::OrComponent(const std::string& name) : AComponent(name)
{
    _pins = 3;
    _state = nts::Tristate::Undefined;
}

nts::Tristate nts::OrComponent::compute(std::size_t pin)
{
    if (pin == 3) {
        std::pair<IComponent*, std::size_t> pin1Link = getLink(1);
        std::pair<IComponent*, std::size_t> pin2Llink = getLink(2);
        return  _state = operator_or(pin1Link.first->compute(pin1Link.second),
                           pin2Llink.first->compute(pin2Llink.second));
    } else if (pin == 1 || pin == 2) {
        return getLink(pin).first->compute(getLink(pin).second);
    }
    throw nts::Errors::InvalidCompute();
}

void nts::OrComponent::simulate(std::size_t tick) { (void) tick; } // not needed for this

// true preponderant (1)
