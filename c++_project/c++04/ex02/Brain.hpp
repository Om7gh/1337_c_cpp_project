/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:40:19 by omghazi           #+#    #+#             */
/*   Updated: 2024/11/01 10:53:48 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include "Animal.hpp"

class Brain 
{
        public:
                std::string ideas[100];
                Brain();
                ~Brain();
                Brain(const Brain &obj);
                Brain& operator=(const Brain& obj);
                
};

#endif