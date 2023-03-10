/*
** EPITECH PROJECT, 2023
** NanoTekSpice
** File description:
** Parser
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <tuple>
#include <string>
#include "Circuit.hpp"
#include "Factory.hpp"
#include "NtsError.hpp"

namespace Parser {

    enum chipOrLink {
        chipsets,
        links,
        none
    };

    class Parser {
        public:
            Parser();
            ~Parser();

            void parseFile(std::string file, Circuit &circuit);

        protected:
        private:
            std::vector< std::tuple<std::string, std::string> > _chipsetList;
            std::vector< std::tuple<std::string, int, std::string, int> > _linksList;
            chipOrLink _state;
            bool _chipset;

            std::tuple<std::string, int, std::string, int> _buildTuple(std::vector<std::string> buffer);
            void _fillVector(std::string reader);
            void _displayVector() const;
            bool _checkComponent(std::string componentName) const;
            bool _verifyLinks(std::string link) const;
    };
}


#endif /* !PARSER_HPP_ */
