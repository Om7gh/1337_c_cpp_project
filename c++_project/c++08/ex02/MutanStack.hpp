/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutanStack.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:40:42 by omghazi           #+#    #+#             */
/*   Updated: 2024/12/10 19:55:45 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>
#include <deque>
#include <algorithm>

template <typename T>

class MutantStack : public std::stack<T>
{
        public:
                MutantStack();
                ~MutantStack();
                MutantStack(const MutantStack<T> &obj);
                MutantStack & operator=(const MutantStack<T> &obj);
                typedef typename std::deque<T>::iterator iterator;
                typedef typename std::deque<T>::reverse_iterator reverse_iterator;

                iterator begin();
                iterator end();
                reverse_iterator rend();
};

#include "MutanStack.tpp"