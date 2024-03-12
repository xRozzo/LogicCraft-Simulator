#ifndef OR_COMPONENT_HPP_
#define OR_COMPONENT_HPP_

#include "../AComponent.hpp"
#include <string>
#include <unordered_map>

// FOR LINKING COMOMENTS

namespace nts
{
    class OrComponent : virtual public AComponent
    {
      public:
        OrComponent(const std::string& name);
        ~OrComponent() final = default;
        nts::Tristate compute(std::size_t pin) final;
        void simulate(std::size_t tick) final;
        
    };
} // namespace nts

#endif
