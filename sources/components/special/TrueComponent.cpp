#include "../../../include/components/special/TrueComponent.hpp"
#include "../../../include/exceptions/Errors.hpp"

nts::TrueComponent::TrueComponent(const std::string& name) : AComponent(name)
{
    _pins = 1;
    _state = nts::Tristate::True;
}

// the first time that is computed set to true (true component)
nts::Tristate nts::TrueComponent::compute(std::size_t pin)
{
    if (pin != 1)
        throw nts::Errors::InvalidPinNumber("TrueComponent");
    _state = nts::Tristate::True;
    return _state;
}

// simulate (not sure if this is needed)
void nts::TrueComponent::simulate(std::size_t tick) { (void) tick; }

// error handling ivalid links -> ovverride the setLink function and see that pin is valid
// maybe need the getLink fucntion -> check for invalid link.
