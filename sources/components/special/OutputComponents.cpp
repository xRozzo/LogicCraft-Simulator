#include "../../../include/components/special/OutputComponent.hpp"
#include "../../../include/exceptions/Errors.hpp"
#include <memory>

nts::OutputComponent::OutputComponent(const std::string& name) : AComponent(name)
{
    _pins = 1;
    _state = nts::Tristate::Undefined;
}

nts::Tristate nts::OutputComponent::compute(std::size_t pin)
{
    if (pin != 1)
        throw nts::Errors::InvalidPinNumber("OutputComponent");
    std::pair<IComponent*, std::size_t> link = getLink(pin);
    return _state = link.first->compute(link.second);
}

void nts::OutputComponent::simulate(std::size_t tick) { (void) tick; }
// FLAG OF IT'S COMPONENT -> MAP PIN TO BOOL TO SEE IF COMPUTED ALREADY OR NOT.
