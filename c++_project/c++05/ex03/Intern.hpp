/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:47:52 by omghazi           #+#    #+#             */
/*   Updated: 2024/12/04 20:01:34 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
        private:
                static AForm* createRobotomy(std::string target);
                static AForm* createShrubbery(std::string target);
                static AForm* createPardon(std::string target);
        public:
                Intern();
                Intern(const Intern &obj);
                ~Intern();
                Intern & operator=(const Intern &obj);
                AForm *makeForm(std::string formName, std::string target);
};
