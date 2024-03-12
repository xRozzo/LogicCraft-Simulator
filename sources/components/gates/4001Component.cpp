#include "../../../include/components/gates/4001Component.hpp"
#include "../../../include/components/elementary/NorComponent.hpp"
#include "../../../include/exceptions/Errors.hpp"

nts::C4001Component::C4001Component(const std::string& name)
    : AComponent(name), _nor1(std::make_unique<NorComponent>("nor1")),
      _nor2(std::make_unique<NorComponent>("nor2")), _nor3(std::make_unique<NorComponent>("nor3")),
      _nor4(std::make_unique<NorComponent>("nor4"))
{
    _pins = 14;
    _state = nts::Tristate::Undefined;
}

nts::Tristate nts::C4001Component::compute(std::size_t pin)
{
    if (pin == 3) {
        std::pair<IComponent*, std::size_t> pin1Link = getLink(1);
        std::pair<IComponent*, std::size_t> pin2Link = getLink(2);
        return operator_not(operator_or(pin1Link.first->compute(pin1Link.second),
                                                 pin2Link.first->compute(pin2Link.second)));

    } else if (pin == 4) {
        std::pair<IComponent*, std::size_t> pin5Link = getLink(5);
        std::pair<IComponent*, std::size_t> pin6Link = getLink(6);
        return  operator_not(operator_or(pin5Link.first->compute(pin5Link.second),
                                                 pin6Link.first->compute(pin6Link.second)));

    } else if (pin == 10) {
        std::pair<IComponent*, std::size_t> pin8Link = getLink(8);
        std::pair<IComponent*, std::size_t> pin9Link = getLink(9);
        return  operator_not(operator_or(pin8Link.first->compute(pin8Link.second),
                                                 pin9Link.first->compute(pin9Link.second)));

    } else if (pin == 11) {
        std::pair<IComponent*, std::size_t> pin12Link = getLink(12);
        std::pair<IComponent*, std::size_t> pin13Link = getLink(13);
        return  operator_not(operator_or(pin12Link.first->compute(pin12Link.second),
                                                 pin13Link.first->compute(pin13Link.second)));

    } else {
        return getLink(pin).first->compute(getLink(pin).second);
    }
    throw nts::Errors::InvalidCompute();
}


void nts::C4001Component::simulate(std::size_t tick) { (void) tick; }
