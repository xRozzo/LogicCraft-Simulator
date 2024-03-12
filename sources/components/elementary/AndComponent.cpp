#include "../../../include/components/elementary/AndComponent.hpp"
#include "../../../include/exceptions/Errors.hpp"
#include <utility>

nts::AndComponent::AndComponent(const std::string& name) : AComponent(name)
{
    _pins = 3;
    _state = nts::Tristate::Undefined; // global state -> same as the 3rd pin (the relevatn pin of a
                                       // component)
}

nts::Tristate nts::AndComponent::compute(std::size_t pin)
{
    if (pin == 3) {
        std::pair<IComponent*, std::size_t> pin1Link = getLink(1);
        std::pair<IComponent*, std::size_t> pin2Llink = getLink(2);
        return _state = operator_and(pin1Link.first->compute(pin1Link.second),
                            pin2Llink.first->compute(pin2Llink.second));

    } else if (pin == 1 || pin == 2) {
        return getLink(pin).first->compute(getLink(pin).second);
    }
    throw nts::Errors::InvalidCompute();
}

void nts::AndComponent::simulate(std::size_t tick) { (void) tick; } // not needed for this

// false preponderant (0)
nts::Tristate operator_and(nts::Tristate a, nts::Tristate b)
{
    if (a == nts::Tristate::False || b == nts::Tristate::False) {
        return nts::Tristate::False;
    }
    if (a == nts::Tristate::Undefined || b == nts::Tristate::Undefined) {
        if (a != nts::Tristate::False || b != nts::Tristate::False) {
            return nts::Tristate::Undefined;
        }
        return nts::Tristate::False;
    }
    return nts::Tristate::True;
}
