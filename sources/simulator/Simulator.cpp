/*
** EPITECH PROJECT, 2024
** Simulator.cpp
** File description:
** OOP_nanotekspice
*/

#include "../../include/simulator/Simulator.hpp"
#include "../../include/components/special/ClockComponent.hpp"
#include "../../include/components/special/InputComponent.hpp"
#include "../../include/components/special/OutputComponent.hpp"
#include "../../include/exceptions/Errors.hpp"
#include <algorithm>
#include <csignal>
#include <iostream>
#include <vector>

nts::Simulator *nts::Simulator::globalSimulatorInstance = nullptr;

nts::Simulator::Simulator(Factory *factory) : _factory(factory), _tick(0) {
  nts::Simulator::globalSimulatorInstance = this;
}

void nts::Simulator::init() {
  try {
    string _input;
    cout << "> ";
    while (getline(cin, _input)) {
      if (_input == "exit")
        exit(0);
      processInput(_input);
      cout << "> ";
    }
  } catch (const exception &e) {
    cout << e.what() << endl;
    exit(84);
  }
}

void signalHandler(int signum) {
  if (signum == SIGINT) {
    nts::Simulator::globalSimulatorInstance->init();
  }
}

void nts::Simulator::processInput(const string &_input) {
  if (_input == "display")
    display();
  else if (_input == "simulate")
    simulate();
  else if (_input == "loop") {
    signal(SIGINT, signalHandler);
    loop();
  } else if (isInput(_input))
    input(_input);
  else
    throw nts::Errors::UnkwnownCommand("Unknown command");
}

void nts::Simulator::display() {
  for (auto &comp : nts::Factory::_components) {
    if (comp.second->getType() == "output") {
      comp.second->compute(1);
    }
  }
  cout << "tick: " << _tick << endl;
  cout << "input(s):" << endl;
  vector<pair<string, string>> inputsInfo = sortByName(true);
  for (auto &info : inputsInfo)
    cout << "  " << info.first << ": " << info.second << endl;
  cout << "output(s):" << endl;
  vector<pair<string, string>> outputsInfo = sortByName(false);
  for (auto &info : outputsInfo)
    cout << "  " << info.first << ": " << info.second << endl;
}

// !FIX : factory not iterable seams that component is null
void nts::Simulator::simulate() {
  nts::OutputComponent *output = nullptr;
  _tick++;
  for (auto &comp : nts::Factory::_components) {
    if (comp.second == nullptr)
      continue;

    if (comp.second->getType() == "clock") {
      auto *clock = dynamic_cast<nts::ClockComponent *>(comp.second.get());
      if (clock)
        clock->simulate(_tick);
    }

    if (comp.second->getType() == "output") {
      output = dynamic_cast<nts::OutputComponent *>(
          comp.second.get()); // get the poineter of the output
    }
  }
  if (output)
    output->compute(1);
}

void nts::Simulator::loop() {
  while (true) {
    simulate();
    display();
  }
}

nts::Tristate stringToTristate(const string &value) {
  if (value == "0")
    return nts::Tristate::False;
  if (value == "1")
    return nts::Tristate::True;
  if (value == "U")
    return nts::Tristate::Undefined;
  return nts::Tristate::Undefined;
}

void nts::Simulator::input(const string &input) {
  size_t pos = input.find_first_of('=');

  if (pos == string::npos) {
    throw nts::Errors::InvalidInput("No '=' found");
  }

  string name = input.substr(0, pos);
  string value = input.substr(pos + 1);

  if (value != "0" && value != "1" && value != "U") {
    throw nts::Errors::InvalidInput("Invalid value");
  }

  try {
    string compType;
    if (nts::Factory::_components.find(name) !=
        nts::Factory::_components.end()) {
      nts::IComponent *compPtr = nts::Factory::_components[name].get();
      if (compPtr)
        compType = compPtr->getType();
      if (compType == "input" || compType == "output" || compType == "clock")
        compPtr->setState(stringToTristate(value));
    } else {
      throw nts::Errors::InvalidInput("Component not found");
    }
  } catch (const exception &e) {
    cout << e.what() << endl;
    exit(84);
  }
}

string nts::Simulator::tristateToString(nts::Tristate state) {
  switch (state) {
  case nts::Tristate::True:
    return "1";
  case nts::Tristate::False:
    return "0";
  case nts::Tristate::Undefined:
  default:
    return "U";
  }
}

vector<pair<string, string>> nts::Simulator::sortByName(bool isInput) {
  vector<pair<string, string>> info;
  for (auto &comp : nts::Factory::_components)
    if (isInput ? comp.second->getType() == "input" ||
                      comp.second->getType() == "clock"
                : comp.second->getType() == "output")
      info.emplace_back(comp.first, tristateToString(comp.second->getState()));
  sort(info.begin(), info.end());
  return info;
}

bool nts::Simulator::isInput(const string &input) {
  size_t pos = input.find_first_of('=');
  string name = input.substr(0, pos);
  string value = input.substr(pos + 1);

  if (nts::Factory::_components.find(name) == nts::Factory::_components.end()) {
    return false;
  }
  if (value != "0" && value != "1" && value != "U") {
    throw nts::Errors::InvalidInput("Invalid value");
  }
  return true;
}
