/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 19:50:34 by omghazi           #+#    #+#             */
/*   Updated: 2024/12/05 20:19:02 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer( void )
{}

unsigned long int Serializer::serialize(Data* ptr)
{
        return (reinterpret_cast<unsigned long int>(ptr));
}

Data*Serializer:: deserialize(unsigned long int raw)
{
        return (reinterpret_cast<Data*>(raw));
}
