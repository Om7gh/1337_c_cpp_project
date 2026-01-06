/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:36:09 by omghazi           #+#    #+#             */
/*   Updated: 2024/10/25 14:33:27 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>

class Weapon
{
        private:
                std::string weapon;
        public:
                Weapon( std::string initalWeapon );
                const std::string       &getType( void ) const;
                void                    setType( std::string weapon );
                ~Weapon();
};

#endif
