/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 22:18:12 by omghazi           #+#    #+#             */
/*   Updated: 2024/12/10 12:36:19 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span( void ) : N(5)
{}

Span::Span(unsigned int N) : N(N)
{}

Span::~Span( void )
{}

Span::Span( const Span &obj) : N(obj.N), data(obj.data)
{}

Span & Span::operator=( const Span &obj )
{
        if (this != &obj)
        {
                this->N = obj.N;
                this->data = obj.data;
        }
        return (*this);
}

void    Span::addNumber( int value )
{
        if (data.size() >= this->N)
                throw std::overflow_error("container size doesnt handle the size allocated");
        std::vector<int>::iterator it = std::find(data.begin(), data.end(), value);
        if (it != data.end())
                throw std::runtime_error(std::to_string(value) + " aleady exist");
        data.push_back(value);
}

int     Span::shortestSpan( void ) const
{
        if (data.size() == 1)
            throw std::runtime_error("Not enough elements to find the shortest span");

        std::vector<int> sortedData = data;
        std::sort(sortedData.begin(), sortedData.end());
        
        int shortest = std::numeric_limits<int>::max();
        for (std::vector<int>::const_iterator it = sortedData.begin(); it + 1 != sortedData.end(); ++it)
        {
            int diff = *(it + 1) - *it;
            shortest = std::min(shortest, diff);
        }
        return shortest;
}

int     Span::longestSpan( void ) const
{
        if (data.size() == 1)
            throw std::runtime_error("Not enough elements to find the longest span");
        int     min = *std::min_element(data.begin(), data.end());
        int     max = *std::max_element(data.begin(), data.end());

        return (max - min);
}
