/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:12:47 by omghazi           #+#    #+#             */
/*   Updated: 2024/12/09 22:01:19 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "easyfind.hpp"

template <typename T>
typename T::iterator easyfind(T &data , int value)
{
        typename T::iterator it = std::find(data.begin(), data.end(), value);
        if (it == data.end())
                throw std::runtime_error(std::to_string(value) + " not found");
        return it;
}
