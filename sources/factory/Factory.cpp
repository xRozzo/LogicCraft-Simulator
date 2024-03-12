/*
** EPITECH PROJECT, 2024
** Factory.cpp
** File description:
** OOP_nanotekspice
*/

#include "../../include/factory/Factory.hpp"
#include "../../include/exceptions/Errors.hpp"
#include "../../include/components/interfaces/IComponent.hpp"
#include "../../include/components/elementary/AndComponent.hpp"
#include "../../include/components/elementary/NandComponent.hpp"
#include "../../include/components/elementary/NorComponent.hpp"
#include "../../include/components/elementary/NotComponent.hpp"
#include "../../include/components/elementary/OrComponent.hpp"
#include "../../include/components/elementary/XorComponent.hpp"
#include "../../include/components/special/InputComponent.hpp"
#include "../../include/components/special/OutputComponent.hpp"
#include "../../include/components/special/TrueComponent.hpp"
#include "../../include/components/special/FalseComponent.hpp"
#include "../../include/components/special/ClockComponent.hpp"
#include "../../include/components/gates/4001Component.hpp"
#include "../../include/components/gates/4011Component.hpp"
#include "../../include/components/gates/4030Component.hpp"
#include "../../include/components/gates/4069Component.hpp"
#include "../../include/components/gates/4071Component.hpp"
#include "../../include/components/gates/4081Component.hpp"

using namespace std;

std::unordered_map<std::string, std::function<std::unique_ptr<nts::IComponent>()>> nts::Factory::_componentFactory = {
        {"input", []() { return std::make_unique<InputComponent>("input"); }},
        {"output", []() { return std::make_unique<OutputComponent>("output"); }},
        {"clock", []() { return std::make_unique<ClockComponent>("clock"); }},
        {"true", []() { return std::make_unique<TrueComponent>("true"); }},
        {"false", []() { return std::make_unique<FalseComponent>("false"); }},
        {"and", []() { return std::make_unique<AndComponent>("and"); }},
        {"or", []() { return std::make_unique<OrComponent>("or"); }},
        {"xor", []() { return std::make_unique<XorComponent>("xor"); }},
        {"not", []() { return std::make_unique<NotComponent>("not"); }},
        {"4001", []() { return std::make_unique<C4001Component>("4001"); }},
        {"4011", []() { return std::make_unique<C4011Component>("4011"); }},
        {"4030", []() { return std::make_unique<C4030Component>("4030"); }},
        {"4069", []() { return std::make_unique<C4069Component>("4069"); }},
        {"4071", []() { return std::make_unique<C4071Component>("4071"); }},
        {"4081", []() { return std::make_unique<C4081Component>("4081"); }}
};

std::unordered_map<std::string, std::unique_ptr<nts::IComponent>> nts::Factory::_components;

nts::Factory::Factory() = default;

nts::Factory::~Factory() = default;

std::unique_ptr<nts::IComponent> nts::Factory::createComponent(const std::string &type)
{
    auto it = _componentFactory.find(type);
    if (it != _componentFactory.end())
        return it->second();
    throw nts::Errors::UnknownComponentType("Unknown component type: " + type);
}
