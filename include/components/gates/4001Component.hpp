#ifndef C_4001_COMPONENT_HPP_
#define C_4001_COMPONENT_HPP_

#include "../AComponent.hpp"
#include "../elementary/NorComponent.hpp"
#include <string>
#include <unordered_map>
namespace nts
{
    class C4001Component : virtual public nts::AComponent
    {
      public:
        C4001Component(const std::string& name); // initaiat ehte mapping
        ~C4001Component() final = default;
        nts::Tristate compute(std::size_t pin) final;
        void simulate(std::size_t tick) final;

      private:
        std::unique_ptr<NorComponent> _nor1;
        std::unique_ptr<NorComponent> _nor2;
        std::unique_ptr<NorComponent> _nor3;
        std::unique_ptr<NorComponent> _nor4;
    };

} // namespace nts

#endif // I_4001_COMPONENT_HPP_
