/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 12:57:09 by omghazi           #+#    #+#             */
/*   Updated: 2024/12/03 15:05:12 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( std::string name, int grade ) : name(name), grade(grade)
{
        if (grade < 1)
                throw GradeTooHighException();
        if (grade > 150)
                throw GradeTooLowException();
}

Bureaucrat::Bureaucrat( ) : name("omar")
{
        grade = 150;
}

Bureaucrat::~Bureaucrat( void )
{}

Bureaucrat::Bureaucrat(Bureaucrat &obj) : name(obj.name)
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
