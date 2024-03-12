#ifndef C_4081_COMPONENT_HPP_
#define C_4081_COMPONENT_HPP_

#include "../AComponent.hpp"
#include "../elementary/AndComponent.hpp"

namespace nts
{
    class C4081Component : virtual public nts::AComponent
    {
      public:
        C4081Component(const std::string& name);
        ~C4081Component() final = default;
        nts::Tristate compute(std::size_t pin) final;
        void simulate(std::size_t tick) final;

      private:
        std::unique_ptr<nts::AndComponent> _and1;
        std::unique_ptr<nts::AndComponent> _and2;
        std::unique_ptr<nts::AndComponent> _and3;
        std::unique_ptr<nts::AndComponent> _and4;
    };
} // namespace nts

#endif // I_4030_COMPONENT_HPP_
