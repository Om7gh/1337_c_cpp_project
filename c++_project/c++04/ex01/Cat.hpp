/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:25:31 by omghazi           #+#    #+#             */
/*   Updated: 2024/11/01 10:50:22 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
        private:
                Brain   *catBrain;
        public:
                Cat( void );
                Cat( const Cat &obj );
                Cat&    operator=(const Cat &obj);
                ~Cat( void );
                void    makeSound( void ) const;
};

#endif