#ifndef NOR_COMPONENT_HPP_
#define NOR_COMPONENT_HPP_

#include "../AComponent.hpp"
#include <string>
#include <unordered_map>

// FOR LINKING COMOMENTS

namespace nts
{
    class NorComponent : virtual public AComponent
    {
      public:
        NorComponent(const std::string& name);
        ~NorComponent() final = default;
        nts::Tristate compute(std::size_t pin) final;
        void simulate(std::size_t tick) final;
    };

} // namespace nts

#endif
