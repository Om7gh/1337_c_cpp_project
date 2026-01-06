/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 19:40:06 by omghazi           #+#    #+#             */
/*   Updated: 2024/11/01 20:15:54 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class ICharacter;

class AMateria
{
        protected:
                std::string type;
        public:
                AMateria(std::string const & type);
                virtual ~AMateria();
                std::string const & getType() const;
                virtual AMateria* clone() const = 0;
                virtual void use(ICharacter& target) = 0;
};
