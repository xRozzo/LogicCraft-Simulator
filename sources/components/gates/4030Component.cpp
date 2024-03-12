#include "../../../include/components/gates/4030Component.hpp"
#include "../../../include/components/elementary/XorComponent.hpp"
#include "../../../include/exceptions/Errors.hpp"
#include <memory>

nts::C4030Component::C4030Component(const std::string& name) : AComponent(name)
{
    _xor1 = std::make_unique<XorComponent>("xor1");
    _xor2 = std::make_unique<XorComponent>("xor2");
    _xor3 = std::make_unique<XorComponent>("xor3");
    _xor4 = std::make_unique<XorComponent>("xor4");
    _pins = 14;
    _state = nts::Tristate::Undefined;
}

nts::Tristate nts::C4030Component::compute(std::size_t pin)
{
    if (pin == 3) {
        std::pair<IComponent*, std::size_t> pin1Link = getLink(1);
        std::pair<IComponent*, std::size_t> pin2Link = getLink(2);

        return operator_xor(pin1Link.first->compute(pin1Link.second),
                            pin2Link.first->compute(pin2Link.second));
    }

    if (pin == 4) {
        std::pair<IComponent*, std::size_t> pin5Link = getLink(5);
        std::pair<IComponent*, std::size_t> pin6Link = getLink(6);

        return operator_xor(pin5Link.first->compute(pin5Link.second),
                            pin6Link.first->compute(pin6Link.second));
    }

    if (pin == 10) {
        std::pair<IComponent*, std::size_t> pin8Link = getLink(8);
        std::pair<IComponent*, std::size_t> pin9Link = getLink(9);

        return operator_xor(pin8Link.first->compute(pin8Link.second),
                            pin9Link.first->compute(pin9Link.second));
    }

    if (pin == 11) {
        std::pair<IComponent*, std::size_t> pin12Link = getLink(12);
        std::pair<IComponent*, std::size_t> pin13Link = getLink(13);

        return operator_xor(pin12Link.first->compute(pin12Link.second),
                            pin13Link.first->compute(pin13Link.second));
    }

    return getLink(pin).first->compute(getLink(pin).second);
}

void nts::C4030Component::simulate(std::size_t tick) { (void) tick; }
