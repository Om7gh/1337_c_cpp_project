/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 22:05:09 by omghazi           #+#    #+#             */
/*   Updated: 2024/12/10 12:26:41 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once


#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

class Span
{
    private:
        unsigned int N;
        std::vector<int> data;
    public:
        Span(unsigned int N);
        Span(void);
        Span(const Span &obj);
        ~Span( void );
        Span & operator=(const Span &obj);
        void    addNumber( int value );
        int     shortestSpan() const;
        int     longestSpan() const;
};
