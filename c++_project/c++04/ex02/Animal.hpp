/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:25:42 by omghazi           #+#    #+#             */
/*   Updated: 2024/11/01 11:38:38 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
        protected :
                std::string type;
        public:
                Animal( void );
                virtual ~Animal( void );
                virtual void makeSound( void ) const = 0;
                std::string     getType() const;
};

#endif
