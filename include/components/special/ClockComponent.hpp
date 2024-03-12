#ifndef CLOCK_COMPONENT_HPP_
#define CLOCK_COMPONENT_HPP_

#include "../AComponent.hpp"
#include <string>
#include <unordered_map>

namespace nts
{
    class ClockComponent : virtual public AComponent
    {
      public:
        ClockComponent(const std::string& name);
        ~ClockComponent() final = default;
        nts::Tristate compute(std::size_t pin) final;
        void simulate(std::size_t tick) final;
        void setState(nts::Tristate state);

      private:
        std::size_t _currentTick;
        nts::Tristate _backUpState;
    };
} // namespace nts

#endif
