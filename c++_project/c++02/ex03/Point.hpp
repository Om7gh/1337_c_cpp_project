/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 22:43:19 by omghazi           #+#    #+#             */
/*   Updated: 2024/10/18 20:02:09 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
        private:
                Fixed const  x;
                Fixed const  y;
        public:
                Point ( void );
                Point ( const float x, const float y );
                Point (const Point &obj);
                Point& operator=(const Point& obj);
                ~Point ( void );
                Fixed getX() const;
                Fixed getY() const;
                static bool bsp( Point const a, Point const b, Point const c, Point const point);
};

#endif
