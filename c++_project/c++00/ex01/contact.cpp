/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:26:19 by omghazi           #+#    #+#             */
/*   Updated: 2024/10/24 18:10:09 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact( void )
{
	static int	k;

	__index = ++k;
}

Contact::~Contact( void )
{
}

void	Contact::set_index( int i )
{
	this->__index = i;
}

std::string	Contact::getFirstName( void )
{
	return (__firstName);
}

bool isNumber(const std::string& str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        if (!std::isdigit(str.at(i)))
	{
		std::cout << "\033[1;31mError: Phone number cannot have characters !\033[0m" << std::endl;
		return false;
	}
    }
    return true;
}

bool isTab(const std::string& str)
{
	int	j;

	j = 0;
    	for (size_t i = 0; i < str.length(); i++)
    	{
		if (str.at(i) == ' ')
			j++;
    	    	if (str.at(i) == '\t')
		{
			std::cout << "\033[1;31mError: Phone number cannot have tabs !\033[0m" << std::endl;
			return false;
		}
    	}
	if (str[j] == '\0')
	{
		std::cout << "\033[1;31mError: Phone number cannot have only space !\033[0m" << std::endl;
		return false;
	}
    	return true;
}

void	Contact::new_contact( void )
{
	do {
		std::cout << "first name\t: ";
		std::getline(std::cin, this->__firstName);
		if (std::cin.eof() || std::cin.fail())
			return ;
		if (this->__firstName.empty())
			std::cout << "\033[1;31mError: First name cannot be empty!\033[0m" << std::endl;
	} while (this->__firstName.empty() || !isTab(__firstName));
	do {
		std::cout << "last name\t: ";
		std::getline(std::cin, this->__lastName);
		if (std::cin.eof() || std::cin.fail())
			return ;
		if (this->__lastName.empty())
		std::cout << "\033[1;31mError: Last name cannot be empty!\033[0m" << std::endl;
	} while (this->__lastName.empty() || !isTab(__lastName));
	do {
		std::cout << "nick name\t: ";
		std::getline(std::cin, this->__nickName);
		if (std::cin.eof() || std::cin.fail())
			return ;
		if (this->__nickName.empty())
			std::cout << "\033[1;31mError: Nickname cannot be empty!\033[0m" << std::endl;
	} while (this->__nickName.empty() || !isTab(__nickName));
	do {
		std::cout << "phone number\t: ";
		std::getline(std::cin, this->__phoneNo);
		if (std::cin.eof() || std::cin.fail())
			return ;
		if (this->__phoneNo.empty())
			std::cout << "\033[1;31mError: Phone number cannot be empty!\033[0m" << std::endl;
	} while (this->__phoneNo.empty() || !isNumber(this->__phoneNo) || !isTab(__phoneNo));
	do {
		std::cout << "darkest secret\t: ";
		std::getline(std::cin, this->__darkestSecret);
		if (std::cin.eof() || std::cin.fail())
			return ;
		if (this->__darkestSecret.empty())
			std::cout << "\033[1;31mError: Darkest secret cannot be empty!\033[0m" << std::endl;
	} while (this->__darkestSecret.empty() || !isTab(__darkestSecret));
}

void	Contact::display_contacts( std::string contact_field )
{
	if (contact_field.length() <= 10)
	{
		for (size_t i = 0; i < 10 - contact_field.length(); i++)
			std::cout << " ";
		std::cout << contact_field;
	}
	else
	{
		for (size_t i = 0; i < 9; i++)
			std::cout << contact_field.at(i);
		std::cout << ".";
	}
}

void	Contact::display_info( void )
{
	std::cout << "\t[" << this->__index << "] | ";
	this->display_contacts(this->__firstName);
	std::cout << " | ";
	this->display_contacts(this->__lastName);
	std::cout << " | ";
	this->display_contacts(this->__nickName);
	std::cout << std::endl;
}

void	Contact::display_full_info( void )
{
	std::cout << "\t\033[1m\033[33m████████████████████████ CONTACT " << this->__index << " ████████████████████████\033[0m" << std::endl << std::endl;
	std::cout << std::endl << "\t\t\033[1m\033[36mfirst name\t: \033[1m\033[37m" << __firstName << std::endl \
				<< "\t\t\033[1m\033[36mlast name\t: \033[1m\033[37m" << __lastName << std::endl \
				<< "\t\t\033[1m\033[36mnick name\t: \033[1m\033[37m" << __nickName << std::endl \
				<< "\t\t\033[1m\033[36mphone number\t: \033[1m\033[37m" << __phoneNo << std::endl \
				<< "\t\t\033[1m\033[36mdarckest secret\t: \033[1m\033[37m" << __darkestSecret << std::endl \
				<< "\033[1m\033[36m" << std::endl << std::endl;
}
