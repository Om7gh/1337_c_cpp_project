/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 18:16:04 by omghazi           #+#    #+#             */
/*   Updated: 2024/10/17 13:56:00 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
        std::string str;

        for (int i = 1; i < argc ; i++)
        {
            str = argv[i];
            for (size_t i = 0; i < str.length(); i++)
            {
                str.at(i) = toupper(str.at(i));
                std::cout << str.at(i);
            }
        }
        if (argc == 1)
            std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        else
            std::cout << "" << std::endl;
        return (EXIT_SUCCESS);
}
