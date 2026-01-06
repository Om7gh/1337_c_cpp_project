/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:59:56 by omghazi           #+#    #+#             */
/*   Updated: 2024/10/07 17:21:01 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Zombie.hpp"

int main()
{
        Zombie *zombie_heap;

        zombie_heap = newZombie("Zombie heap:");
        zombie_heap->announce();
        delete zombie_heap;
        randomChump("Zombie stack:");
        return (0);
}
