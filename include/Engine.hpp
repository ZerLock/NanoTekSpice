/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-tekspice-leo.dubosclard
** File description:
** Engine
*/

#ifndef ENGINE_HPP_
#define ENGINE_HPP_

#include <string>
#include <map>
#include <iostream>
#include <functional>
#include <sstream>
#include <unistd.h>
#include <signal.h>

#include "NtsError.hpp"
#include "Circuit.hpp"

class Engine {
    public:
        Engine();
        ~Engine();

        /**
         * @brief Array of functions for NanoTekSpice shell
         */
        std::map<std::string, std::function<void(Circuit&)>> Commands;

        /**
         * @brief Start the NanoTekSpice shell
         *
         * @param circuit
         */
        void start(Circuit &circuit);

        /**
         * @brief Execute the good command from the user input (buffer)
         *
         * @param circuit
         * @param buffer
         */
        void execCommand(Circuit &circuit, const std::string buffer);

        /**
         * @brief Split a string at a char delemiter and by default <space>
         *
         * @param str
         * @param delim
         * @return std::vector<std::string>
         */
        std::vector<std::string> mySplit(const std::string str, char delim = ' ') const;

        /**
         * @brief [DEBUG] Print all links of all components
         *
         * @param circuit
         */
        void displayLinks(Circuit &circuit);

    private:
        std::size_t _tick;
        std::string _prompt = "> ";
        bool _isExiting = false;

        // Utils
        /**
         * @brief Get the nts::Tristate from the tristate string
         *
         * @param value
         * @return nts::Tristate
         */
        nts::Tristate _getTristate(std::string value);

        /**
         * @brief Get the tristate string from the nts::Tristate
         *
         * @param state
         * @return std::string
         */
        std::string _getStringTristate(nts::Tristate state);

        // Commands

        /**
         * @brief Exit the NanoTekSpice shell
         *
         * @param circuit
         */
        void _exitEngine(Circuit &circuit);

        /**
         * @brief Display inputs and outputs states
         *
         * @param circuit
         */
        void _display(Circuit &circuit);

        /**
         * @brief Set manually an input state
         *
         * @param circuit
         * @param inputName
         * @param value
         */
        void _setInput(Circuit &circuit, const std::string inputName, const std::string value);

        /**
         * @brief Simulate all outputs (Start the circuit simulation)
         *
         * @param circuit
         */
        void _simulate(Circuit &circuit);

        /**
         * @brief Infinity loop (while Ctrl-C) of simulates
         *
         * @param circuit
         */
        void _loop(Circuit &circuit);
};

#endif /* !ENGINE_HPP_ */
