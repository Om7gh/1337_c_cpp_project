/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 19:40:25 by omghazi           #+#    #+#             */
/*   Updated: 2024/11/01 20:17:58 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class ICharacter
{
        public:
                virtual ~ICharacter() {}
                virtual std::string const & getName() const = 0;
                virtual void equip(AMateria* m) = 0;
                virtual void unequip(int idx) = 0;
                virtual void use(int idx, ICharacter& target) = 0;
};
