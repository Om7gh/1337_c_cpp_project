/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 12:04:05 by omghazi           #+#    #+#             */
/*   Updated: 2024/12/08 13:37:39 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
template <typename T>

class Array
{
        private:
                T *data;
                unsigned int length;
        public:
                Array( void );
                ~Array( void );
                Array( unsigned int n);
                Array (const Array &obj);
                Array& operator=(const Array& other);
                T& operator[](unsigned int index);
                const T& operator[](unsigned int index) const;
                unsigned int size() const;
};

#include "Array.tpp"
