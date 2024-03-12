#ifndef TRUE_COMPONENT_HPP_
#define TRUE_COMPONENT_HPP_

#include "../AComponent.hpp"
#include <string>
#include <unordered_map>

// FOR LINKING COMOMENTS
namespace nts
{
    class TrueComponent : virtual public AComponent
    {
      public:
        TrueComponent(const std::string& name);
        ~TrueComponent() final = default;
        nts::Tristate compute(std::size_t pin) final;
        void simulate(std::size_t tick) final;

      private:
        nts::Tristate _state;
    };

} // namespace nts

#endif // ACOMPONENT_HPP_
