/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 11:58:30 by omghazi           #+#    #+#             */
/*   Updated: 2024/10/23 19:52:12 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
        private:
                Contact contacts[8];
        public :
                PhoneBook( void );
                ~PhoneBook( void );
                void            add_contact( void );
                void            search_contact( void );
                void            menu( void );
} ;

#endif
