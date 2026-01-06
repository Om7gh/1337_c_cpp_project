/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 12:07:20 by omghazi           #+#    #+#             */
/*   Updated: 2024/12/04 17:15:00 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AForm.hpp"

class  Bureaucrat
{
        private:
                const std::string name;
                int     grade;
        public:
                Bureaucrat( std::string name , int grade);
                Bureaucrat( );
                ~Bureaucrat( void );
                Bureaucrat(Bureaucrat &obj);
                Bureaucrat& operator=(const Bureaucrat &obj);

                void            executeForm(const AForm &form) const;
                std::string     getName( void ) const;
                int             getGrade( void ) const;
                void            increment_grade();
                void            decrement_grade();
                void            signForm(AForm &obj);
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

std::ostream&    operator << (std::ostream &os, const Bureaucrat &obj);
