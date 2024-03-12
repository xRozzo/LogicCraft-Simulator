#ifndef NAND_COMPONENT_HPP_
#define NAND_COMPONENT_HPP_

#include "../AComponent.hpp"
#include <string>
#include <unordered_map>

// FOR LINKING COMOMENTS
namespace nts
{
    class NandComponent : virtual public AComponent
    {
      public:
        NandComponent(const std::string& name);
        ~NandComponent() final = default;
        nts::Tristate compute(std::size_t pin) final;
        void simulate(std::size_t tick) final;
    };

} // namespace nts

#endif
