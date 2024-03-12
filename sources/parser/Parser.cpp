/*
** EPITECH PROJECT, 2024
** Parser.cpp
** File description:
** OOP_nanotekspice
*/

#include "../../include/parser/Parser.hpp"
#include "../../include/exceptions/Errors.hpp"
#include <iostream>
#include <utility>
#include <sstream>

nts::Parser::Parser(char **_path, nts::Factory *_factory) : _factory(_factory)
{
    try {
        string path(_path[1]);
        ifstream file(path, ifstream::in);

        if (!file || !file.is_open())
            throw nts::Errors::FileError();
        else
            _file = std::move(file);
    } catch (...) {
        exit(84);
    }
}

size_t nextInfoPos(string line)
{
    size_t pos = line.find_first_of("\t ");

    if (pos == string::npos)
        return 0;
    for (size_t i = pos + 1; i < line.length(); i++) {
        if (line[i] == '\t' || line[i] == ' ')
            pos++;
        else if (line[i] != '\t' && line[i] != ' ')
            break;
    }
    return pos + 1;
}

void nts::Parser::parseComponents()
{
    string line;
    size_t pos;
    while (getline(_file, line)) {
        if (line.rfind(".chipsets:", 0) == 0 || line[0] == '#' || line[0] == '\n')
            continue;
        if (line.rfind(".links:", 0) == 0)
            break;
        if ((pos = nextInfoPos(line)) == 0)
            continue;

        // cout << pos << endl;
        pair<string, string> nameType = getCompInfo(line, pos);
        if (nts::Factory::_components.find(nameType.first) == nts::Factory::_components.end())
            nts::Factory::_components[nameType.first] = nts::Factory::createComponent(nameType.second);
        else
            throw nts::Errors::NamingError(nameType.first);
    }
}

pair<string, string> nts::Parser::getCompInfo(const string &line, size_t pos)
{
    size_t initialPos = line.find_first_of("\t ");

    string type = line.substr(0, initialPos);
    // cout << type << endl;
    string name = line.substr(pos);
    // cout << name << endl;
    return make_pair(name, type);
}

void nts::Parser::parseLinks()
{
    string line;
    int linksFound = 0;
    nts::IComponent *firstComponent;
    nts::IComponent *secondComponent;

    while (getline(_file, line)) {
        size_t posMiddle = line.find_first_of("\t ");

        if (posMiddle != string::npos && line[0] != '#' && line[0] != '\n') {
            pair<string, string> firstLinkInfo = getLinkInfo(line, posMiddle);
            size_t infoEnd = line.find_last_not_of("\t \n");
            pair<string, string> secondLinkInfo = getLinkInfo(line.substr(posMiddle + 1), infoEnd);

            size_t firstPin = sToSize_t(firstLinkInfo.second);
            auto it = nts::Factory::_components.find(firstLinkInfo.first);
            if (it != nts::Factory::_components.end()) {
                firstComponent = it->second.get();
            } else {
                throw nts::Errors::NamingError(firstLinkInfo.first);
            }

            size_t secondPin = sToSize_t(secondLinkInfo.second);
            it = nts::Factory::_components.find(secondLinkInfo.first);
            if (it != nts::Factory::_components.end()) {
                secondComponent = it->second.get();
            } else {
                throw nts::Errors::NamingError(secondLinkInfo.first);
            }

            firstComponent->setLink(firstPin, *secondComponent, secondPin);
            linksFound++;
        }
    }
    if (linksFound == 0)
        throw nts::Errors::LinkError("No links found");
}

pair<string, string> nts::Parser::getLinkInfo(const string &line, size_t spacePos)
{
    size_t pos = line.find_first_of(':');
    string pin = line.substr(pos + 1, spacePos - pos);
    string name = line.substr(0, pos);

    return make_pair(name, pin);
}

size_t nts::Parser::sToSize_t(const string &str)
{
    size_t result;
    stringstream sstream(str);
    sstream >> result;
    return result;
}
