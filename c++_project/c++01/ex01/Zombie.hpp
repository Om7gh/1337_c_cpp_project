/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:25:09 by omghazi           #+#    #+#             */
/*   Updated: 2024/10/26 20:31:09 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Zombie
{
        private:
                std::string     name;
        public:
                Zombie( const std::string& name );
                Zombie( void );
                void announce( void );
                ~Zombie( void );
};

Zombie* zombieHorde( int N, std::string name );