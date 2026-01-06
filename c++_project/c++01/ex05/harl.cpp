/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:22:48 by omghazi           #+#    #+#             */
/*   Updated: 2024/10/08 14:32:36 by omghazi          ###   ########.fr       */
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
        std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info( void )
{
        std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning( void )
{
        std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error( void )
{
        std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
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
                {
                        (this->*function[i])();
                        return;
                }
                i++;
        }
}
