/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:32:03 by omghazi           #+#    #+#             */
/*   Updated: 2024/12/05 18:07:34 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
        try
        {
                if (ac != 2)
                        throw "Invalid argument";
                std::string input = av[1];
                ScalarConverter::convert(input);
        }
        catch(const char *s)
        {
                std::cout << s << std::endl;
        }
        return (0);
}
