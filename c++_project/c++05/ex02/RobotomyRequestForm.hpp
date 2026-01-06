/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:30:38 by omghazi           #+#    #+#             */
/*   Updated: 2024/12/04 18:23:58 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <ctime>
#include <cstdlib> 

class RobotomyRequestForm : public AForm
{
        private:
            std::string target;
        
        public:
            RobotomyRequestForm(std::string target);
            RobotomyRequestForm( void );
            RobotomyRequestForm(const RobotomyRequestForm &obj);
            ~RobotomyRequestForm( void );
            RobotomyRequestForm & operator=(const RobotomyRequestForm &obj);
            void execute(const Bureaucrat &executor) const;
};
