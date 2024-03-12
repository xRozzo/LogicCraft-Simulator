/*
** EPITECH PROJECT, 2024
** Factory.hpp
** File description:
** OOP_nanotekspice
*/

#ifndef FACTORY_HPP_
#define FACTORY_HPP_

#include <memory>
#include <string>
#include <functional>
#include <unordered_map>
#include "../../include/components/interfaces/IComponent.hpp"

namespace nts {
    class Factory {
    public:
        Factory();
        ~Factory();

        static std::unique_ptr<nts::IComponent>createComponent(const std::string &type);

        static std::unordered_map<std::string, std::function<std::unique_ptr<nts::IComponent>()>> _componentFactory;
        static std::unordered_map<std::string, std::unique_ptr<nts::IComponent>> _components;
    };


}

#endif //FACTORY_HPP_
