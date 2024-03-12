#ifndef OUTPUT_COMPONENT_HPP_
#define OUTPUT_COMPONENT_HPP_

#include "../AComponent.hpp"
#include <string>
#include <unordered_map>

namespace nts
{
    class OutputComponent : virtual public AComponent
    {
      public:
        OutputComponent(const std::string& name);
        ~OutputComponent() final = default;
        nts::Tristate compute(std::size_t pin) final;
        void simulate(std::size_t tick) final;
    };
} // namespace nts

#endif
