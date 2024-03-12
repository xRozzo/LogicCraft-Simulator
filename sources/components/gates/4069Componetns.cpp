#include "../../../include/components/elementary/NotComponent.hpp"
#include "../../../include/components/gates/4069Component.hpp"
#include "../../../include/exceptions/Errors.hpp"
#include <memory>

nts::C4069Component::C4069Component(const std::string& name) : AComponent(name)
{
    _pins = 14;
    _not1 = std::make_unique<NotComponent>("not1");
    _not2 = std::make_unique<NotComponent>("not2");
    _not3 = std::make_unique<NotComponent>("not3");
    _not4 = std::make_unique<NotComponent>("not4");
    _not5 = std::make_unique<NotComponent>("not5");
    _not6 = std::make_unique<NotComponent>("not6");
    _state = nts::Tristate::Undefined;
}

nts::Tristate nts::C4069Component::compute(std::size_t pin)
{
    if (pin == 2) {
        std::pair<IComponent*, std::size_t> pin1Link = getLink(1);
        return operator_not(pin1Link.first->compute(pin1Link.second));
    }

    if (pin == 4) {
        std::pair<IComponent*, std::size_t> pin4Link = getLink(3);
        return operator_not(pin4Link.first->compute(pin4Link.second));
    }

    if (pin == 6) {
        std::pair<IComponent*, std::size_t> pin5Link = getLink(5);
        return operator_not(pin5Link.first->compute(pin5Link.second));
    }

    if (pin == 8) {
        std::pair<IComponent*, std::size_t> pin9Link = getLink(9);
        return operator_not(pin9Link.first->compute(pin9Link.second));
    }

    if (pin == 10) {
        std::pair<IComponent*, std::size_t> pin11Link = getLink(11);
        return operator_not(pin11Link.first->compute(pin11Link.second));
    }

    if (pin == 12) {
        std::pair<IComponent*, std::size_t> pin13Link = getLink(13);
        return operator_not(pin13Link.first->compute(pin13Link.second));
    }

    return getLink(pin).first->compute(getLink(pin).second);
}

void nts::C4069Component::simulate(std::size_t tick) { (void) tick; }
