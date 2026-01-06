/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 11:25:53 by omghazi           #+#    #+#             */
/*   Updated: 2024/10/21 15:00:11 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_HPP
#define CLAP_TRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
        protected:
                std::string                     name;
                unsigned int                    hit_point;
                unsigned int                    energy_point;
                unsigned int                    attack_damage;
        public:
                ClapTrap( void );
                ClapTrap( std::string name );
                ~ClapTrap( void );
                void attack(const std::string& target);
                void takeDamage(unsigned int amount);
                void beRepaired(unsigned int amount);
};

#endif
