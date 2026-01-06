/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 22:04:51 by omghazi           #+#    #+#             */
/*   Updated: 2024/12/10 12:37:13 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"


int main()
{
        try
        {
                Span sp = Span(3);
                sp.addNumber(6);
                sp.addNumber(18);
                sp.addNumber(3);
                std::cout << sp.shortestSpan() << std::endl;
                std::cout << sp.longestSpan() << std::endl;
        }
        catch(const std::exception& e)
        {
                std::cerr << "Caught error: " << e.what() << '\n';
        }
        

        return 0;
}
