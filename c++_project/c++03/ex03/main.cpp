/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:17:19 by omghazi           #+#    #+#             */
/*   Updated: 2024/10/22 16:14:54 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
        DiamondTrap     diamond("omar");

        diamond.attack("karim");
        diamond.takeDamage(30);
        diamond.whoAmI();
        return (EXIT_SUCCESS);
}
