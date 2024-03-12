#ifndef AND_COMPONENT_HPP_
#define AND_COMPONENT_HPP_

#include "../AComponent.hpp"
#include <string>
#include <unordered_map>

// FOR LINKING COMOMENTS

namespace nts
{
    class AndComponent : virtual public AComponent
    {
      public:
        AndComponent(const std::string& name);
        ~AndComponent() final = default;
        nts::Tristate compute(std::size_t pin) final;
        void simulate(std::size_t tick) final;
    };

} // namespace nts

#endif
