/*
** EPITECH PROJECT, 2024
** Simulator.hpp
** File description:
** OOP_nanotekspice
*/

#ifndef SIMULATOR_HPP_
#define SIMULATOR_HPP_

#include <exception>
#include <string>
#include <iostream>
#include "../../include/factory/Factory.hpp"

using namespace std;

namespace nts {
    class Simulator {
    public:
        static Simulator *globalSimulatorInstance;

        Simulator(Factory *factory);
        ~Simulator() = default;

        void init();
        static string tristateToString(nts::Tristate state);

    protected:
        void processInput(const string &input); // done
        void display(); // done
        void simulate();
        void loop();
        void input(const string &input); // done

    private:
        static bool isInput(const string &input);
        static vector<pair<string, string>> sortByName(bool isInput);

        size_t _tick;
        Factory *_factory;
    };
}

#endif //SIMULATOR_HPP_
