/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-tekspice-leo.dubosclard
** File description:
** NtsError
*/

#ifndef NTSERROR_HPP_
#define NTSERROR_HPP_

#include <exception>
#include <string>

class NtsError: public std::exception {
    public:
        NtsError(const std::string &msg) noexcept;
        ~NtsError();

        /**
         * @brief Return the std::string message by a char*
         *
         * @return const char*
         */
        const char *what() const noexcept override;

    protected:
    private:
        std::string _msg;
};

#endif /* !NTSERROR_HPP_ */
