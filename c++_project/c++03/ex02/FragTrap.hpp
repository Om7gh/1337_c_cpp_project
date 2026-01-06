/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 08:08:33 by omghazi           #+#    #+#             */
/*   Updated: 2024/10/21 10:22:50 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAG_TRAP_HPP
#define FRAG_TRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
        public:
                FragTrap( void );
                FragTrap( std::string name );
                ~FragTrap( void );
                void    highFivesGuys( void );
                void bot_attack(const std::string& target);
};

#endif
