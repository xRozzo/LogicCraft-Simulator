#include "../../../include/components/gates/4081Component.hpp"
#include "../../../include/components/elementary/AndComponent.hpp"
#include "../../../include/exceptions/Errors.hpp"

nts::C4081Component::C4081Component(const std::string& name) : AComponent(name)
{
    _pins = 14;
    _and1 = std::make_unique<AndComponent>("and1");
    _and2 = std::make_unique<AndComponent>("and2");
    _and3 = std::make_unique<AndComponent>("and3");
    _and4 = std::make_unique<AndComponent>("and4");
    _state = nts::Tristate::Undefined;
}

nts::Tristate nts::C4081Component::compute(std::size_t pin)
{
    if (pin == 3) {
        std::pair<IComponent*, std::size_t> pin1Link = getLink(1);
        std::pair<IComponent*, std::size_t> pin2Link = getLink(2);
        return operator_and(pin1Link.first->compute(pin1Link.second),
                            pin2Link.first->compute(pin2Link.second));
    }

    if (pin == 4) {
        std::pair<IComponent*, std::size_t> pin5Link = getLink(5);
        std::pair<IComponent*, std::size_t> pin6Link = getLink(6);
        return operator_and(pin5Link.first->compute(pin5Link.second),
                            pin6Link.first->compute(pin6Link.second));
    }

    if (pin == 10) {
        std::pair<IComponent*, std::size_t> pin8Link = getLink(8);
        std::pair<IComponent*, std::size_t> pin9Link = getLink(9);
        return operator_and(pin8Link.first->compute(pin8Link.second),
                            pin9Link.first->compute(pin9Link.second));
    }

    if (pin == 11) {
        std::pair<IComponent*, std::size_t> pin12Link = getLink(12);
        std::pair<IComponent*, std::size_t> pin13Link = getLink(13);
        return operator_and(pin12Link.first->compute(pin12Link.second),
                            pin13Link.first->compute(pin13Link.second));
    }

    return getLink(pin).first->compute(getLink(pin).second);
}

void nts::C4081Component::simulate(std::size_t tick) { (void) tick; }
