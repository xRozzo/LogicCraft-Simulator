#ifndef C_4030_COMPONENT_HPP_
#define C_4030_COMPONENT_HPP_

#include "../AComponent.hpp"
#include "../elementary/XorComponent.hpp"
#include <string>
#include <unordered_map>

namespace nts
{
    class C4030Component : virtual public nts::AComponent
    {
      public:
        C4030Component(const std::string& name); // initaiat ehte mapping
        ~C4030Component() final = default;
        nts::Tristate compute(std::size_t pin) final;
        void simulate(std::size_t tick) final;

      private:
        std::unique_ptr<XorComponent> _xor1;
        std::unique_ptr<XorComponent> _xor2;
        std::unique_ptr<XorComponent> _xor3;
        std::unique_ptr<XorComponent> _xor4;
    };

} // namespace nts

#endif // I_4030_COMPONENT_HPP_
