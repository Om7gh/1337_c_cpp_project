/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:30:27 by omghazi           #+#    #+#             */
/*   Updated: 2024/12/04 18:22:21 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm( void )
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other)
{
}

PresidentialPardonForm & PresidentialPardonForm::operator=( const PresidentialPardonForm &obj)
{
    if (this != &obj)
        AForm::operator=(obj);
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
        if (getSign() == 0)
            throw FormNotSignedException();
        if (executor.getGrade() > getGradeToExec())
            throw GradeTooLowException();
        std::cout << getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
