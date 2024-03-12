#ifndef C_4011_COMPONENT_HPP_
#define C_4011_COMPONENT_HPP_

#include "../AComponent.hpp"
#include "../elementary/NandComponent.hpp"
#include <string>
#include <unordered_map>


namespace nts
{
    class C4011Component : virtual public nts::AComponent
    {
      public:
        C4011Component(const std::string& name); // initaiat ehte mapping
        ~C4011Component() final = default;
        nts::Tristate compute(std::size_t pin) final;
        void simulate(std::size_t tick) final;

      private:
        std::unique_ptr<NandComponent> _nand1;
        std::unique_ptr<NandComponent> _nand2;
        std::unique_ptr<NandComponent> _nand3;
        std::unique_ptr<NandComponent> _nand4;
    };

} // namespace nts

#endif // I_4001_COMPONENT_HPP_
