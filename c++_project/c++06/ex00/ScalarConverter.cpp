/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:32:05 by omghazi           #+#    #+#             */
/*   Updated: 2024/12/05 18:04:42 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"


ScalarConverter::ScalarConverter( void )
{
}

bool isPrintable(const std::string& input)
{
    for (size_t i = 0; i < input.size(); i++)
    {
        if (!std::isprint(input.at(i)))
            return false;
    }
    return true;
}

bool isCharacter(const std::string& input)
{
    return input.size() == 1 && std::isprint(input[0]) && !std::isdigit(input[0]);
}

bool isInteger(const std::string& input)
{
    size_t i = 0;
    if (input[i] == '+' || input[i] == '-') i++;
    for (; i < input.size(); i++) {
        if (!std::isdigit(input[i]))
            return false;
    }
    return !input.empty();
}

bool isDouble(const std::string& input)
{
    size_t i = 0;
    bool hasDot = false;

    if (input[i] == '+' || input[i] == '-') i++;
    for (; i < input.size(); i++) {
        if (input[i] == '.') {
            if (hasDot) return false;
            hasDot = true;
        } else if (!std::isdigit(input[i])) {
            return false;
        }
    }
    return hasDot;
}

bool isFloat(const std::string& input)
{
    return input.size() > 1 && input[input.size() - 1] == 'f' && isDouble(input.substr(0, input.size() - 1));
}

bool isPseudoLiteral(const std::string& input)
{
    return (input == "+inff" || input == "-inff" || input == "nanf" || input == "+inf" || input == "-inf" || input == "nan");
}

int     stringToInt(const std::string &input)
{
        std::stringstream ss(input);
        int n;

        ss >> n;
        if (ss.fail() || !ss.eof())
                throw "Invalid format for int.";
        return (n);
}

float     stringToFloat(const std::string &input)
{
        std::stringstream ss(input);
        float n;

        ss >> n;
        if (ss.fail() || !ss.eof())
                throw "Invalid format for float.";
        return (n);
}

double     stringToDouble(const std::string &input)
{
        std::stringstream ss(input);
        double n;

        ss >> n;
        if (ss.fail() || !ss.eof())
                throw "Invalid format for double.";
        return (n);
}

void ScalarConverter::convert(std::string input)
{
    try {
        if (!isPrintable(input))
            throw "Input contains non-printable characters.";

        if (isPseudoLiteral(input))
        {
            std::cout << "char: Impossible" << std::endl;
            std::cout << "int: Impossible" << std::endl;
            std::cout << "float: " << input << std::endl;
            std::cout << "double: " << input.substr(0, input.size() - 1) << std::endl;
            return;
        }

        if (isCharacter(input))
        {
            char c = input[0];
            std::cout << "char: '" << c << "'" << std::endl;
            std::cout << "int: " << static_cast<int>(c) << std::endl;
            std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
            std::cout << "double: " << static_cast<double>(c) << std::endl;
            return;
        }

        if (isInteger(input))
        {
            int value = stringToInt(input);
            std::cout << "char: " << (value >= 0 && value <= 127 && std::isprint(value) ? "'" + std::string(1, static_cast<char>(value)) + "'" : "Non displayable") << std::endl;
            std::cout << "int: " << value << std::endl;
            std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
            std::cout << "double: " << static_cast<double>(value) << std::endl;
            return;
        }

        if (isFloat(input))
        {
            float value = stringToFloat(input);
            std::cout << "char: " << (value >= 0 && value <= 127 && std::isprint(static_cast<int>(value)) ? "'" + std::string(1, static_cast<char>(value)) + "'" : "Non displayable") << std::endl;
            std::cout << "int: " << static_cast<int>(value) << std::endl;
            std::cout << "float: " << value << "f" << std::endl;
            std::cout << "double: " << static_cast<double>(value) << std::endl;
            return;
        }

        if (isDouble(input))
        {
            double value = stringToDouble(input);
            std::cout << "char: " << (value >= 0 && value <= 127 && std::isprint(static_cast<int>(value)) ? "'" + std::string(1, static_cast<char>(value)) + "'" : "Non displayable") << std::endl;
            std::cout << "int: " << static_cast<int>(value) << std::endl;
            std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
            std::cout << "double: " << value << std::endl;
            return;
        }
        throw "Invalid input format.";
    }
    catch (const char* err)
    {
        std::cerr << "Error: " << err << std::endl;
    }
}
