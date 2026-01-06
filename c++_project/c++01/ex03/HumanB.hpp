/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:46:26 by omghazi           #+#    #+#             */
/*   Updated: 2024/10/07 20:28:43 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_H
#define HUMAN_B_H

#include "Weapon.hpp"

class HumanB
{
        private:
                std::string name;
                Weapon *weapon;
        public:
                HumanB( void );
                HumanB( std::string humaneName );
                void    setWeapon(Weapon &weapon) ;
                void    attack( void ) const;
                ~HumanB();
};

#endif
