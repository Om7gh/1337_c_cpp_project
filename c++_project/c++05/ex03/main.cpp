/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:17:19 by omghazi           #+#    #+#             */
/*   Updated: 2024/12/19 20:23:24 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    try
    {
        Intern someRandomIntern;
        AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        if (!rrf)
            throw std::runtime_error("can't create form");
        std::cout << "Form target: " << rrf->getName() << std::endl;
        Bureaucrat bureaucrat("omar", 5);
        bureaucrat.signForm(*rrf);
        rrf->execute(bureaucrat);
        delete rrf;
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << "------------------------\n";
    try
    {
        Intern someRandomIntern;
        AForm* rrf = someRandomIntern.makeForm("robost", "Bender");
        if (!rrf)
            throw std::runtime_error("can't create form");
        std::cout << "Form target: " << rrf->getName() << std::endl;
        Bureaucrat bureaucrat("omar", 5);
        bureaucrat.signForm(*rrf);
        rrf->execute(bureaucrat);
        delete rrf;
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    return 0;
}
