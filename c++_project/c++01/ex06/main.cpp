/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:26:00 by omghazi           #+#    #+#             */
/*   Updated: 2024/10/25 12:05:34 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
        Harl    harl;
        std::string     level;

        if (argc != 2)
        {
                std::cout << "Error\nInvalid argument, enter a level" << std::endl;
                return (EXIT_FAILURE);
        }
        level = argv[1];
        harl.complain(level);
        return (EXIT_SUCCESS);
}
