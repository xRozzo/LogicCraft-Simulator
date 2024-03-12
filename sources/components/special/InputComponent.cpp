#include "../../../include/components/special/InputComponent.hpp"
#include "../../../include/exceptions/Errors.hpp"

// input two pins

nts::InputComponent::InputComponent(const std::string& name) : AComponent(name)
{
    _pins = 1;
    _state = nts::Tristate::Undefined;
}

nts::Tristate nts::InputComponent::compute(std::size_t pin)
{
    if (pin != 1)
        throw nts::Errors::InvalidPinNumber("InputComponent");
    return _state;
}


void nts::InputComponent::setState(nts::Tristate state) { _state = state; }


void nts::InputComponent::simulate(std::size_t tick)
{
    (void) tick;
}
