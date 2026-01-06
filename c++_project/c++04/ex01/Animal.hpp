/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:25:42 by omghazi           #+#    #+#             */
/*   Updated: 2024/10/30 16:33:12 by omghazi          ###   ########.fr       */
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
                virtual void makeSound( void ) const;
                std::string     getType() const;
};

#endif
