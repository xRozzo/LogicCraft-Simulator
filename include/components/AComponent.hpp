#ifndef ACOMPONENT_HPP_
#define ACOMPONENT_HPP_

#include "./interfaces/IComponent.hpp"
#include <string>
#include <unordered_map>
#include <memory>

// FOR LINKING COMOMENTS
namespace nts
{
    class AComponent : virtual public IComponent
    {
      public:
        AComponent(const std::string& name) : _name(name) {}
        virtual ~AComponent() = default;
        virtual void simulate(std::size_t tick) override = 0;
        virtual nts::Tristate compute(std::size_t pin) override = 0 ;
        // set virutal to be overriden by the child if needed
        void setLink(std::size_t pin, nts::IComponent& other, std::size_t otherPin) override;
        std::pair<nts::IComponent*, std::size_t> getLink(std::size_t pin) const;
        nts::Tristate getState()  const override;
        std::size_t getPins() const override;
        std::string getType() const override;
        virtual void setState(nts::Tristate state) override;
        size_t _pins;

      protected:
        std::string _name;
        nts::Tristate _state;
        std::unordered_map<std::size_t, nts::Tristate> _pinStates;
        //std::unordered_map<std::size_t, std::pair<nts::IComponent&, std::size_t>> _links;
        std::unordered_map<std::size_t, std::pair<nts::IComponent*, std::size_t>> _links;
        // if pin is not valid, throw an exception (gratter than the number of pins or less than 1)
        virtual bool isValidPin(std::size_t pin, nts::IComponent &other, std::size_t otherPin) const;

        // logical numeric
        nts::Tristate operator_and(nts::Tristate a, nts::Tristate b);
        nts::Tristate operator_or(nts::Tristate a, nts::Tristate b);
        nts::Tristate operator_xor(nts::Tristate a, nts::Tristate b);
        nts::Tristate operator_not(nts::Tristate a);

    };

}; // namespace nts

#endif // ACOMPONENT_HPP_
