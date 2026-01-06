/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 12:16:54 by omghazi           #+#    #+#             */
/*   Updated: 2024/10/24 18:21:08 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook( void )
{
}

PhoneBook::~PhoneBook( void )
{
}

void	PhoneBook::menu( void )
{
	std::cout << "\t\033[1m\033[33m█████████████████████ PHONEBOOK █████████████████████\033[0m" << std::endl << std::endl;
	std::cout << "\t\tEnter \033[1m\033[36mADD\033[0m to add a new contact" << std::endl;
	std::cout << "\t\tEnter \033[1m\033[36mSEARCH\033[0m to search" << std::endl;
	std::cout << "\t\tEnter \033[1m\033[36mEXIT\033[0m to exit" << std::endl;
}

void	PhoneBook::add_contact( void )
{
	system("clear");
	std::cout << "\t\033[1m\033[33m████████████████████ NEW CONTACT ████████████████████\033[0m" << std::endl << std::endl;
	std::cout << std::endl;
	for (int i = 7; i > 0; i--)
		contacts[i] = contacts[i - 1];
	contacts[0].new_contact();
	for (int i = 0; i < 8; i++)
		contacts[i].set_index(i + 1);
	system("clear");
	this->menu();
}

int	valid_range(int idx)
{
	if (idx < 1 || idx > 8)
	{	
		std::cout << "Error : Index out of range" << std::endl;
		return (1);
	}
	return (0);
}

void	PhoneBook::search_contact( void )
{
	system("clear");
	std::cout << "\t\033[1m\033[33m███████████████████████ SEARCH ███████████████████████\033[0m" << std::endl << std::endl;
	std::cout << "select contact index" << std::endl << std::endl;
	for (int i = 0; i < 8; i++)
	{
		if ( this->contacts[i].getFirstName().empty())
		{
			if (i == 0)
			{	
				system("clear");
				this->menu();
				return ;
			}
			break ;
		}
		this->contacts[i].display_info();
	}
	std::string	index;
	int	idx = 0;
	do {
		std::cout << "_";
		std::cin >> index;
		if (std::cin.eof() || std::cin.fail())
		{
			std::cout << "Error : enter en integer" << std::endl;
			return ;			
		}
        	if (index.length() != 1)
        	{
			std::cout << "index out of range" << std::endl;
        	    	continue;
        	}
		idx = index[0] - 48;
	} while (valid_range(idx));
	system("clear");
	if ( this->contacts[idx - 1].getFirstName().empty() )
	{
		system("clear");
		this->menu();
		return ;
	}
	this->contacts[idx - 1].display_full_info();
	this->menu();
}
