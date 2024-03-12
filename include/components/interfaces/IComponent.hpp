
#ifndef ICOMPONENT_HPP_
#define ICOMPONENT_HPP_

#include <cstddef>
#include <ostream>

namespace nts
{
    enum Tristate { Undefined = (-true), True = true, False = false };

    class IComponent
    {
      public:
        virtual ~IComponent() = default;
        virtual void simulate(std::size_t tick) = 0;
        virtual nts::Tristate compute(std ::size_t pin) = 0;
        virtual void setLink(std::size_t pin, nts::IComponent &other, std ::size_t otherPin) = 0;
        // added here
        virtual std::string getType() const = 0;
        virtual std::size_t getPins() const = 0;
        virtual nts::Tristate getState() const = 0;
        virtual void setState(nts::Tristate state) = 0;
    };
};

// operator needed?? overloading the << operator to print the tristate
std::ostream& operator<<(std::ostream& s, nts::Tristate v);

#endif // ICOMPONENT_HPP_
