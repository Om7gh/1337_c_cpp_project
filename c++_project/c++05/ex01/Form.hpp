/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:07:54 by omghazi           #+#    #+#             */
/*   Updated: 2024/12/04 11:06:41 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
class Bureaucrat;

class Form
{
        private:
                const           std::string name;
                bool            sign;
                const int       gradeToSign;
                const int       gradeToExec;
        public:
                Form( std::string name, int sign, int exec );
                Form( );
                Form(const Form &obj);
                ~Form();
                Form & operator=(const Form &obj);
                
                std::string     getName() const;
                bool            getSign() const;
                int             getGradeToSign() const;
                int             getGradeToExec() const;
                void            beSigned(Bureaucrat &b);
                class           GradeTooHighException : public std::exception
                {
                        public:
                                GradeTooHighException();
                                virtual const char* what() const throw();
                };
                class   GradeTooLowException : public std::exception
                {
                        public:
                                GradeTooLowException();
                                virtual const char* what() const throw();
                };
                
};

std::ostream&    operator << (std::ostream &os, const Form &obj);
