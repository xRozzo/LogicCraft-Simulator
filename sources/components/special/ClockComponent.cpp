#include "../../../include/components/special/ClockComponent.hpp"
#include "../../../include/exceptions/Errors.hpp"
#include "../../../include/simulator/Simulator.hpp"
#include <memory>

nts::ClockComponent::ClockComponent(const std::string &name)
    : AComponent(name) {
  _pins = 1;
  _state = nts::Tristate::Undefined;
}

nts::Tristate nts::ClockComponent::compute(std::size_t pin) {
  if (pin != 1)
    throw nts::Errors::InvalidPinNumber("ClockComponent");
  return _state;
}

// if i change the state in middel of simulation
void nts::ClockComponent::simulate(std::size_t tick) {
  if (tick > _currentTick) {
    if (_state == nts::Tristate::Undefined) {
      _state = _backUpState;
    } else {
      _state = (_state == nts::Tristate::False) ? nts::Tristate::True
                                                : nts::Tristate::False;
      _currentTick = tick;
    }
  }
}

void nts::ClockComponent::setState(nts::Tristate state) {
  // if the state is not undefined we set the state to the new state
  if (_state != nts::Tristate::Undefined) {
    _state = state;
  }
  _backUpState = state;
}
