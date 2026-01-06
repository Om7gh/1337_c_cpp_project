/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:05:36 by omghazi           #+#    #+#             */
/*   Updated: 2024/10/23 19:37:59 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
        std::string	input;
	PhoneBook	phonebook;

	system("clear");
        std::cout << "\n\t\033[1m\033[35m╔═══════════════════════ PHONEBOOK ═══════════════════════╗\033[0m" << std::endl;
        std::cout << "\t\033[1m\033[35m║\033[0m           \033[1m\033[36mWelcome to your digital contacts manager\033[0m\033[1m\033[35m\033[0m" << std::endl;
        std::cout << "\t\033[1m\033[35m╚═════════════════════════════════════════════════════════╝\033[0m" << std::endl << std::endl;
	phonebook.menu();
	do {
		std::getline(std::cin, input);
		if (std::cin.eof() || std::cin.fail())
			break ;
		else if (!input.compare("ADD"))
		{
			phonebook.add_contact();
			input.clear();
		}
		else if (!input.compare("SEARCH"))
		{
			phonebook.search_contact();
			input.clear();
		} 
	} while (input.compare("EXIT"));
	system("clear");
	std::cout << "\t\033[1m\033[33m████████████████████████ EXIT ████████████████████████\033[0m" << std::endl;
	return 0;
}
