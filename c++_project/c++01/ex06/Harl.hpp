/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:24:06 by omghazi           #+#    #+#             */
/*   Updated: 2024/10/25 14:14:20 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

typedef enum    level
{
        DEBUG,
        INFO,
        WARNING,
        ERROR,
        UNKNOWN
} e_level;

class Harl
{
        private:
                void debug( void );
                void info( void );
                void warning( void );
                void error( void );
        public:
                Harl( void );
                void complain( std::string level );
                ~Harl( void );
};

#endif