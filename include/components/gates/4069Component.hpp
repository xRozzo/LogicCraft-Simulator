#ifndef C_4069_COMPONENT_HPP_
#define C_4069_COMPONENT_HPP_

#include "../AComponent.hpp"
#include "../elementary/NotComponent.hpp"

namespace nts
{

    class C4069Component : virtual public nts::AComponent
    {
      public:
        C4069Component(const std::string& name);
        ~C4069Component() final = default;
        nts::Tristate compute(std::size_t pin) final;
        void simulate(std::size_t tick) final;

      private:
        std::unique_ptr<nts::NotComponent> _not1;
        std::unique_ptr<nts::NotComponent> _not2;
        std::unique_ptr<nts::NotComponent> _not3;
        std::unique_ptr<nts::NotComponent> _not4;
        std::unique_ptr<nts::NotComponent> _not5;
        std::unique_ptr<nts::NotComponent> _not6;
    };
} // namespace nts

#endif // I_4030_COMPONENT_HPP_
