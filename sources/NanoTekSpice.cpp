/*
** EPITECH PROJECT, 2024
** Factory.hpp
** File description:
** OOP_nanotekspice
*/

#include "../include/factory/Factory.hpp"
#include "../include/parser/Parser.hpp"
#include "../include/simulator/Simulator.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        return 84;
    try {
        nts::Factory *_factory;
        nts::Parser _parser(av, _factory);
        _parser.parseComponents();
        _parser.parseLinks();
        nts::Simulator _simulator(_factory);
        _simulator.init();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}
