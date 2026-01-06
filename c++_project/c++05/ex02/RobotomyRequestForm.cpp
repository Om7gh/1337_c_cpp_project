/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:31:00 by omghazi           #+#    #+#             */
/*   Updated: 2024/12/04 18:39:52 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), target(target)
{
        std::srand(time(0));
}

RobotomyRequestForm::RobotomyRequestForm( void )
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other)
{
}

RobotomyRequestForm & RobotomyRequestForm::operator=( const RobotomyRequestForm &obj)
{
    if (this != &obj)
        AForm::operator=(obj);
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void    RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
        if (getSign() == 0)
            throw FormNotSignedException();
        if (executor.getGrade() > getGradeToExec())
            throw GradeTooLowException();
        std::cout << "Drilling noises..." << std::endl;
        if (std::rand() % 2)
                std::cout << target <<" has been robotomized successfully" << std::endl;
        else
                std::cout << "the robotomy failed." << std::endl;
}
