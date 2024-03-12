/*
** EPITECH PROJECT, 2024
** Errors.hpp
** File description:
** OOP_nanotekspice
*/

#ifndef ERRORS_HPP_
#define ERRORS_HPP_

#include <exception>
#include <string>
#include <iostream>
#include <utility>

namespace nts::Errors
    {
        class FileError : public std::exception
        {
          public:
            FileError() : _message("File not found"){};
            [[nodiscard]] const char* what() const noexcept override { return _message.c_str(); };

          private:
            std::string _message;
        };

          class SimulationError : public std::exception
        {
          public:
            SimulationError() : _message("Simulation Error"){};
            [[nodiscard]] const char* what() const noexcept override { return _message.c_str(); };

          private:
            std::string _message;
        };

         class InvalidCompute : public std::exception
        {
          public:
            InvalidCompute() : _message("Invalid compute"){};
            [[nodiscard]] const char* what() const noexcept override { return _message.c_str(); };

          private:
            std::string _message;
        };
        class NamingError : public std::exception
        {
          public:
            explicit NamingError(std::string  message) : _message(std::move(message)){};
            [[nodiscard]] const char* what() const noexcept override
            {
                return ("Incorrect name: " + _message).c_str();
            };

          private:
            std::string _message;
        };

        class UnknownComponentType : public std::exception
        {
          public:
            explicit UnknownComponentType(std::string  message) : _message(std::move(message)){};
            [[nodiscard]] const char* what() const noexcept override
            {
                return ("Unknown component type: " + _message).c_str();
            }

          private:
            std::string _message;
        };

        class UnknownComponentName : public std::exception
        {
          public:
            explicit UnknownComponentName(std::string  message) : _message(std::move(message)){};
            [[nodiscard]] const char* what() const noexcept override
            {
                return ("Unknown component name: " + _message).c_str();
            }

          private:
            std::string _message;
        };

        class AlreadyExistingName : public std::exception
        {
          public:
            explicit AlreadyExistingName(std::string  message) : _message(std::move(message)){};
            [[nodiscard]] const char* what() const noexcept override
            {
                return ("Name already exists: " + _message).c_str();
            };

          private:
            std::string _message;
        };

        class NoChipsetsDeclared : public std::exception
        {
          public:
            explicit NoChipsetsDeclared(std::string  message) : _message(std::move(message)){};
            [[nodiscard]] const char* what() const noexcept override
            {
                return ("No chipsets declared: " + _message).c_str();
            };

          private:
            std::string _message;
        };

        class InvalidPinNumber : std::exception
        {
          public:
            explicit InvalidPinNumber(std::string  message) : _message(std::move(message)){};
            [[nodiscard]] const char* what() const noexcept override
            {
                return ("Invalid pin number: " + _message).c_str();
            }

          private:
            std::string _message;
        };

        class LinkError : std::exception
        {
          public:
            explicit LinkError(std::string  message) : _message(std::move(message)){};
            [[nodiscard]] const char* what() const noexcept override { return ("Link error: " + _message).c_str(); }

          private:
            std::string _message;
        };

        class InvalidInput : std::exception
        {
        public:
            explicit InvalidInput(std::string message) : _message(std::move(message)){};
            [[nodiscard]] const char* what() const noexcept override { return ("Invalid input: " + _message).c_str(); }

        private:
            std::string _message;
        };

        class UnkwnownCommand : std::exception
        {
        public:
            explicit UnkwnownCommand(std::string message) : _message(std::move(message)){};
            [[nodiscard]] const char* what() const noexcept override { return ("Unknown command: " + _message).c_str(); }

        private:
            std::string _message;
        };
    } // namespace nts

#endif // ERRORS_HPP_
