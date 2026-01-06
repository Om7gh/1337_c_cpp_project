/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:28:26 by omghazi           #+#    #+#             */
/*   Updated: 2024/12/04 16:56:52 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
class Bureaucrat;

class AForm
{
        private:
                const           std::string name;
                bool            sign;
                const int       gradeToSign;
                const int       gradeToExec;
        public:
                AForm( std::string name , int sign, int exec);
                AForm( );
                AForm( const AForm &obj);
                AForm & operator=(const AForm &obj);
                
                std::string     getName() const;
                bool            getSign() const;
                int             getGradeToSign() const;
                int             getGradeToExec() const;
                void            beSigned(Bureaucrat &b);
                virtual         void execute(const Bureaucrat &executor) const = 0;

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
                class FormNotSignedException : public std::exception
                {
                        public:
                                FormNotSignedException();
                                const char *what() const throw();
                };
};

std::ostream&    operator << (std::ostream &os, const AForm &obj);
