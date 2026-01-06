/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:17:19 by omghazi           #+#    #+#             */
/*   Updated: 2024/12/04 18:37:41 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
     try {
        Bureaucrat omar("Omar", 2);
        ShrubberyCreationForm shrubbery("Home");
        RobotomyRequestForm robotomy("Robot");
        PresidentialPardonForm pardon("Prisoner");

        omar.signForm(shrubbery);
        omar.executeForm(shrubbery);

        omar.signForm(robotomy);
        omar.executeForm(robotomy);

        omar.signForm(pardon);
        omar.executeForm(pardon);
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
