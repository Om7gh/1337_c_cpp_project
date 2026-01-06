/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:30:05 by omghazi           #+#    #+#             */
/*   Updated: 2024/12/04 18:22:01 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
        private:
                std::string target;
        public:
                PresidentialPardonForm(std::string target);
                PresidentialPardonForm( void );
                PresidentialPardonForm(const PresidentialPardonForm &obj);
                ~PresidentialPardonForm( void );
                PresidentialPardonForm &operator=(const PresidentialPardonForm &obj);
                void execute(const Bureaucrat &executor) const;
};
