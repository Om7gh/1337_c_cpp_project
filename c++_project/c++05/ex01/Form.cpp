/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:07:22 by omghazi           #+#    #+#             */
/*   Updated: 2024/12/04 14:25:03 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form( std::string name, int sign, int exec) : name(name), sign(false), gradeToSign(sign), gradeToExec(exec)
{
        if (sign > 150 || exec > 150)
                throw GradeTooLowException();
        if (sign < 1 || exec < 1)
                throw GradeTooHighException();
}

Form::Form( ) : name("omar"), sign(false), gradeToSign(50), gradeToExec(50)
{
}

Form::Form(const Form &obj) : name(obj.name), sign(obj.sign), gradeToSign(obj.gradeToSign), gradeToExec(obj.gradeToExec)
{
}

Form::~Form( )
{
}

Form & Form::operator=(const Form &obj)
{
        if (this != &obj)
                this->sign = obj.sign;
        return (*this);
}

std::string     Form::getName() const
{
        return (name);
}

bool    Form::getSign() const
{
        return (sign);
}

int     Form::getGradeToSign() const
{
        return (gradeToSign);
}

int     Form::getGradeToExec() const
{
        return (gradeToExec);
}

void    Form::beSigned(Bureaucrat &b)
{
        if (this->sign)
                throw std::runtime_error("form already signed");
        if (b.getGrade() > this->getGradeToSign())
                throw GradeTooLowException();
        this->sign = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
        return ("Grade is too heigh");
}

const char *Form::GradeTooLowException::what() const throw()
{
        return ("Grade is too low");
}

Form::GradeTooHighException::GradeTooHighException()
{}

Form::GradeTooLowException::GradeTooLowException()
{}

std::ostream&    operator << (std::ostream &os, const Form &obj)
{
        os << "Form: " << obj.getName()
        << ", Signed: " << (obj.getSign() ? "Yes" : "No")
        << ", Grade to Sign: " << obj.getGradeToSign()
        << ", Grade to Execute: " << obj.getGradeToExec();
        return (os);
}
