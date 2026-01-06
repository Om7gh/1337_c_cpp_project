/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 22:43:11 by omghazi           #+#    #+#             */
/*   Updated: 2024/10/18 21:47:41 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main()
{
    Point a(0.0f, 0.0f);
    Point b(4.0f, 0.0f);
    Point c(2.0f, 3.0f);

    Point check(5.0f, 5.0f);

    if (Point::bsp(a, b, c, check))
        std::cout << "Inside the triangle" << std::endl;
    else
        std::cout << "Outside the triangle" << std::endl;

    return (EXIT_SUCCESS);
}
