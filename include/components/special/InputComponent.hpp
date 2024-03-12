#ifndef INPUT_COMPONENT_HPP_
#define INPUT_COMPONENT_HPP_

#include "../AComponent.hpp"
#include <string>
#include <unordered_map>

namespace nts {
    class InputComponent : virtual public AComponent
    {
      public:
        InputComponent(const std::string& name);
        ~InputComponent() final = default;
        nts::Tristate compute(std::size_t pin) final;
        void simulate(std::size_t tick) final;

        // new methods
        void setState(nts::Tristate state);
    };
}

#endif
