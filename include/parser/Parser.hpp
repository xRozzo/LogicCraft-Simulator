/*
** EPITECH PROJECT, 2024
** Parser.hpp
** File description:
** OOP_nanotekspice
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <exception>
#include <string>
#include <fstream>
#include <iostream>
#include <unordered_map>
#include "../components/interfaces/IComponent.hpp"
#include "../factory/Factory.hpp"

using namespace std;

// Open file
// Chipset classification -> unsortered_map

namespace nts {
    class Parser {
    public:
        explicit Parser(char **path, nts::Factory *_factory); // Open file
        ~Parser() = default; // Close file

        // Interacts with factory for each line
        void parseComponents(); // Parse file

        // Sets link between components
        void parseLinks();

    protected:
        static pair<string, string> getCompInfo(const string &line, size_t pos);
        static pair<string, string> getLinkInfo(const string &line, size_t spacePos);

    private:
        static size_t sToSize_t(const string &str);

        Factory *_factory;
        ifstream _file;
    };
}

#endif //PARSER_HPP_