/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 22:39:17 by omghazi           #+#    #+#             */
/*   Updated: 2024/11/01 10:53:51 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"


Brain::Brain()
{
        std::cout << "Brain created." << std::endl;
}

Brain::~Brain()
{
         std::cout << "Brain destroyed." << std::endl;
}

Brain::Brain(const Brain &obj)
{
        std::cout << "Brain copied.\n";
        for (int i = 0; i < 100; ++i)
            ideas[i] = obj.ideas[i];
}

Brain& Brain::operator=(const Brain& obj)
{
        std::cout << "Brain assigned.\n";
        if (this != &obj)
        {
            for (int i = 0; i < 100; ++i)
                ideas[i] = obj.ideas[i];
        }
        return *this;
}
