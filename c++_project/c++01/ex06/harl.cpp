/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:24:04 by omghazi           #+#    #+#             */
/*   Updated: 2024/10/25 14:16:05 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl( void )
{
}

Harl::~Harl( void)
{
}

void    Harl::debug( void )
{
        std::cout << "[ DEBUG ]" << std::endl;
        std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl << std::endl;
}

void Harl::info( void )
{
        std::cout << "[ INFO ]" << std::endl;
        std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl << std::endl;
}

void Harl::warning( void )
{
        std::cout << "[ WARNING ]" << std::endl;
        std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl << std::endl;
}

void Harl::error( void )
{
        std::cout << "[ ERROR ]" << std::endl;
        std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl << std::endl;
}

void    Harl::complain( std::string level )
{
        typedef void(Harl::*ptr)(void);
        int     i;
        std::string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR" };
        ptr function[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
        i = 0;
        while(i < 4)
        {
                if (levels[i] == level)
                        break ;
                i++;
        }
        switch (i)
        {
                case 0:
                        (this->*function[DEBUG])();
                case 1:
                        (this->*function[INFO])();
                case 2:
                        (this->*function[WARNING])();
                case 3:
                        (this->*function[ERROR])();
                break;
                default:
                        std::cout << "Error: Invalid level provided" << std::endl;
                return ;
        }
}
