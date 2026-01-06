/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:00:23 by omghazi           #+#    #+#             */
/*   Updated: 2024/10/07 17:11:49 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Zombie
{
        private:
                std::string     name;
        public:
                Zombie( std::string name );
                void announce( void );
                ~Zombie( void );
};

Zombie* newZombie( std::string name );
void    randomChump( std::string name );
