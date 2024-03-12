#include "../../../include/components/special/FalseComponent.hpp"
#include "../../../include/exceptions/Errors.hpp"

nts::FalseComponent::FalseComponent(const std::string& name) : AComponent(name)
{
    _pins = 1;
    _state = nts::Tristate::False;
}

nts::Tristate nts::FalseComponent::compute(std::size_t pin)
{
    if (pin != 1)
        throw nts::Errors::InvalidPinNumber("FalseComponent");
    _state = nts::Tristate::False;
    return _state;
}

void nts::FalseComponent::simulate(std::size_t tick) { (void) tick; }
