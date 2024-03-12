#ifndef C_4071_COMPONENT_HPP_
#define C_4071_COMPONENT_HPP_

#include "../AComponent.hpp"
#include "../elementary/OrComponent.hpp"

namespace nts
{
    class C4071Component : virtual public nts::AComponent
    {
      public:
        C4071Component(const std::string& name);
        ~C4071Component() final = default;
        nts::Tristate compute(std::size_t pin) final;
        void simulate(std::size_t tick) final;

      private:
        std::unique_ptr<nts::OrComponent> _or1;
        std::unique_ptr<nts::OrComponent> _or2;
        std::unique_ptr<nts::OrComponent> _or3;
        std::unique_ptr<nts::OrComponent> _or4;
    };
} // namespace nts

#endif // I_4030_COMPONENT_HPP_
