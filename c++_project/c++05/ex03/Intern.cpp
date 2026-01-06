/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:50:44 by omghazi           #+#    #+#             */
/*   Updated: 2024/12/04 20:05:29 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern( void )
{
}

Intern::~Intern( void )
{
}

Intern::Intern(const Intern &obj)
{
        (void)obj;
}

Intern & Intern::operator=(const Intern &obj)
{
        (void)obj;
        return (*this);
}

AForm  *Intern::makeForm(std::string formName, std::string target)
{
        try
        {
                typedef AForm* (*FormConstructor)(std::string target);
                struct FormMap
                {
                    std::string name;
                    FormConstructor constructor;
                };
                FormMap formList[] = {
                    {"shrubbery creation", &Intern::createShrubbery},
                    {"robotomy request", &Intern::createRobotomy},
                    {"presidential pardon", &Intern::createPardon}
                };
                for (int i = 0; i < 3; ++i)
                {
                    if (formName == formList[i].name) {
                        std::cout << "Intern creates " << formName << std::endl;
                        return formList[i].constructor(target);
                    }
                }
                throw std::invalid_argument("Invalid argument ");
        }
        catch(const std::exception &e)
        {
                std::cout << e.what() << "'" << formName << "'" << " not found" << std::endl;
        }
        return NULL;
}

AForm   *Intern::createRobotomy(std::string target)
{
        return (new RobotomyRequestForm(target));
}

AForm *Intern::createShrubbery(std::string target)
{
        return (new ShrubberyCreationForm(target));
}

AForm *Intern::createPardon(std::string target)
{
        return (new PresidentialPardonForm(target));
}
