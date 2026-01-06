/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 19:40:11 by omghazi           #+#    #+#             */
/*   Updated: 2024/11/01 20:17:29 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICharacter.hpp"

class Character : public ICharacter
{
        private:
                std::string name;
                AMateria* inventory[4];
        public:
                Character(std::string const & name);
                ~Character( void );
                std::string const & getName() const;
                void equip(AMateria* m);
                void unequip(int idx);
                void use(int idx, ICharacter& target);
};
