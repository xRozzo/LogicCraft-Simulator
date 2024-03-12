#include "../../../include/components/elementary/NandComponent.hpp"
#include "../../../include/exceptions/Errors.hpp"

nts::NandComponent::NandComponent(const std::string& name) : AComponent(name)
{
    _pins = 3;
    _state = nts::Tristate::Undefined;
}

// compute nand is a not(and()) !and
nts::Tristate nts::NandComponent::compute(std::size_t pin)
{
    if (pin == 3) {
        std::pair<IComponent*, std::size_t> pin1Link = getLink(1);
        std::pair<IComponent*, std::size_t> pin2Llink = getLink(2);
        return _state = nts::AComponent::operator_not(operator_and(pin1Link.first->compute(pin1Link.second),
                                                  pin2Llink.first->compute(pin2Llink.second)));
    } else if (pin == 1 || pin == 2) {
        return getLink(pin).first->compute(getLink(pin).second);
    }
    throw nts::Errors::InvalidCompute();
}

void nts::NandComponent::simulate(std::size_t tick) { (void) tick; } // not needed for this

// false preponderant (0)
