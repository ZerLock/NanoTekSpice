/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** main
*/

#include "Engine.hpp"
#include "Parser.hpp"

int main(int ac, char **av)
{
    Circuit circuit;
    Parser::Parser parser;
    Engine engine;

    if (ac != 2) {
        return 84;
    }
    try {
        parser.parseFile(av[1], circuit);
    } catch (const NtsError &e) {
        std::cout << e.what() << std::endl;
        return 84;
    }
    engine.start(circuit);
    return 0;
}
