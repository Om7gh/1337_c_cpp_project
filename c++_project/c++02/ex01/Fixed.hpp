/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:09:37 by omghazi           #+#    #+#             */
/*   Updated: 2024/10/10 21:57:41 by omghazi          ###   ########.fr       */
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
                Fixed ( const int val );
                Fixed ( const float val );
                Fixed(const Fixed &obj);
                Fixed& operator=(const Fixed& obj);
                ~Fixed( void );
                float toFloat( void ) const;
                int toInt( void ) const;
};

std::ostream& operator<< (std::ostream& stream, const Fixed& fixed);

#endif
