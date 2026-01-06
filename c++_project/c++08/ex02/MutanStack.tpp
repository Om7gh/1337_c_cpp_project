/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutanStack.tpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:56:56 by omghazi           #+#    #+#             */
/*   Updated: 2024/12/10 19:57:14 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once
#include "MutanStack.hpp"

template <typename T>
MutantStack<T>::MutantStack()
{
}

template <typename T>
MutantStack<T>::~MutantStack()
{
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &obj)
{
}

template <typename T>
MutantStack<T> & MutantStack<T>::operator=(const MutantStack &obj)
{
        if (this != &obj)
                std::stack<T>::operator=(obj);
        return (*this);
}

template <typename T>
typename std::deque<T>::iterator MutantStack<T>::begin() {
    return this->c.begin();
}

template <typename T>
typename std::deque<T>::iterator MutantStack<T>::end()
{
    return this->c.end();
}

template <typename T>
typename std::deque<T>::reverse_iterator MutantStack<T>::rend() {
    return this->c.rend();
}
