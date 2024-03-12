#ifndef NOT_COMPONENT_HPP_
#define NOT_COMPONENT_HPP_

#include "../AComponent.hpp"
#include <string>
#include <unordered_map>

// FOR LINKING COMOMENTS
namespace nts
{
    class NotComponent : virtual public AComponent
    {
      public:
        NotComponent(const std::string& name);
        ~NotComponent() final = default;
        nts::Tristate compute(std::size_t pin) final;
        void simulate(std::size_t tick) final;
    };

} // namespace nts

#endif // ACOMPONENT_HPP_
