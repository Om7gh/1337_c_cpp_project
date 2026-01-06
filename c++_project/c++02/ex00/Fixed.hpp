/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:09:37 by omghazi           #+#    #+#             */
/*   Updated: 2024/10/10 18:58:45 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
        private:
                int     value;
                static const int bit;
        public:
                Fixed( void );
                Fixed(const Fixed &obj);
                Fixed& operator=(const Fixed& obj);
                ~Fixed( void );
                int getRawBits( void ) const;
                void setRawBits( int const raw );
};

#endif
