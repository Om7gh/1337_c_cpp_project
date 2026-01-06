/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 12:56:31 by omghazi           #+#    #+#             */
/*   Updated: 2024/12/04 15:47:01 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat bureaucrat("Omar", 20);
        std::cout << bureaucrat << std::endl;

        Form form("form", 50, 50);
        std::cout << form << std::endl;

        bureaucrat.signForm(form);
        std::cout << "After signing: " << form << std::endl;

        Bureaucrat lowRank("Ali", 2);
        std::cout << lowRank << std::endl;

        lowRank.signForm(form);
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}
