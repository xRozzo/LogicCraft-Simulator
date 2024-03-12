#ifndef FALSE_COMPONENT_HPP_
#define FALSE_COMPONENT_HPP_

#include "../AComponent.hpp"
#include <string>
#include <unordered_map>

// FOR LINKING COMOMENTS
namespace nts
{
    class FalseComponent : virtual public AComponent
    {
      public:
        FalseComponent(const std::string& name);
        ~FalseComponent() final = default;
        nts::Tristate compute(std::size_t pin) final;
        void simulate(std::size_t tick) final;
    };

} // namespace nts

#endif // ACOMPONENT_HPP_
