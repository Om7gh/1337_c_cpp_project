/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:26:13 by omghazi           #+#    #+#             */
/*   Updated: 2024/11/01 10:44:42 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
        private:
                Brain   *dogBrain;
        public:
                Dog( void );
                Dog( const Dog &obj );
                ~Dog( void );
                Dog     &operator=(const Dog &obj);
                void    makeSound( void ) const;
};

#endif
