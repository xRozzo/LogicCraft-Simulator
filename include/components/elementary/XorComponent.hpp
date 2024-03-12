#ifndef XOR_COMPONENT_HPP_
#define XOR_COMPONENT_HPP_

#include "../AComponent.hpp"
#include <string>
#include <unordered_map>

// FOR LINKING COMOMENTS
namespace nts
{
    class XorComponent : virtual public AComponent
    {
      public:
        XorComponent(const std::string& name);
        ~XorComponent() final = default;
        nts::Tristate compute(std::size_t pin) final;
        void simulate(std::size_t tick) final;
    };
} // namespace nts

#endif
