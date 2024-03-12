#include "../../../include/components/elementary/NotComponent.hpp"
#include "../../../include/exceptions/Errors.hpp"

nts::NotComponent::NotComponent(const std::string& name) : AComponent(name)
{
    _pins = 2;
    _state = nts::Tristate::Undefined;
}

nts::Tristate nts::NotComponent::compute(std::size_t pin)
{
    if (pin == 1) {
        return _state =  operator_not(getLink(1).first->compute(getLink(1).second));
    } else if (pin == 2) {
        //  call compute 1
        // std::cout << "link of pin 1 " << getLink(1).first->getType() << " that is linked to pin" << getLink(1).second << std::endl;
        // std::cout << "link of pin 2 " << getLink(2).first->getType() << " that is linked to pin" << getLink(2).second << std::endl;
        // return operator_not(getLink(1).first->compute(getLink(1).second)); // alsways pin 2
        // return _state =  operator_not(getLink(1).first->compute(getLink(1).second));
        // // need to compute teh think linked to the 1
        return _state =  operator_not(getLink(1).first->compute(getLink(1).second));
    }
    throw nts::Errors::InvalidCompute();
}

void nts::NotComponent::simulate(std::size_t tick) { (void) tick; } // not needed for this
