/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:29:05 by omghazi           #+#    #+#             */
/*   Updated: 2024/12/05 21:21:21 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <ctime>
#include <typeinfo>
#include <cstdlib> 

class Base
{
        public:
                Base * generate(void);
                void identify(Base* p);
                void identify(Base& p);
                virtual ~Base( void );
};
