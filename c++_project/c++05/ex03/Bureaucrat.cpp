/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 12:57:09 by omghazi           #+#    #+#             */
/*   Updated: 2024/12/04 18:07:05 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( std::string name, int grade ) : name(name), grade(grade)
{
}

Bureaucrat::Bureaucrat( ) : name("omar"), grade(5)
{
}

Bureaucrat::~Bureaucrat( void )
{
}

Bureaucrat::Bureaucrat(Bureaucrat &obj)
{
        this->grade = obj.grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &obj)
{
        if (this != &obj)
                this->grade = obj.grade;
        return (*this);
}

std::string Bureaucrat::getName( void ) const 
{
        return (name);
}

int Bureaucrat::getGrade( void ) const 
{
        return (grade);
}

void    Bureaucrat::increment_grade()
{
        GradeTooHighException g;
        if (grade <= 1)
                throw g;
        grade--;
}

void    Bureaucrat::decrement_grade()
{
        GradeTooLowException f;
        if (grade >= 150)
                throw f;
        grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
        return ("Grade is to height");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
        return ("Grade is to low");
}

Bureaucrat::GradeTooHighException::GradeTooHighException()
{}

Bureaucrat::GradeTooLowException::GradeTooLowException()
{}

std::ostream&    operator << (std::ostream &os, const Bureaucrat &obj)
{
        os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
        return (os);
}

void    Bureaucrat::signForm(AForm &obj)
{
        try
        {
            obj.beSigned(*this);
            std::cout << this->getName() << " signed " << obj.getName() << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cout << this->getName() << " couldn’t sign " << obj.getName() << " because " << e.what() << std::endl;
        }
}

void    Bureaucrat::executeForm(const AForm &form) const
{
        try
        {
                form.execute(*this);
                std::cout << this->getName() << " executed " << form.getName() << std::endl;
        }
        catch(const std::exception & e)
        {
                std::cout << e.what() << std::endl;
                std::cout << this->getName() << " can't execute " << form.getName() << std::endl;
        }
}
