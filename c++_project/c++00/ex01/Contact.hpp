/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 12:00:24 by omghazi           #+#    #+#             */
/*   Updated: 2024/10/23 19:55:36 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>

class Contact
{
        private:
                int             __index;
                std::string     __firstName;
                std::string     __lastName;
                std::string     __nickName;
                std::string     __phoneNo;
                std::string     __darkestSecret;
                void            display_contacts( std::string contact_field );
        public :
                Contact( void );
                ~Contact( void );
                void    set_index( int index );
                void    new_contact( void );
                void    display_info( void );
                void    display_full_info( void );
                std::string    getFirstName(void );
} ;

#endif
