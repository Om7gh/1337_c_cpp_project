/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:30:49 by omghazi           #+#    #+#             */
/*   Updated: 2024/12/08 10:10:06 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

void    f(int &i)
{
        i += 1;
}

void f(std::string& s)
{
        std::cout << s << " ";
}

int main()
{
        int arr[] = {1,2,3,4,5};
        iter(arr, 5, f);
        for (int i = 0; i < 5; i++)
               std::cout << arr[i] << std::endl;
        std::string s[] = {"salam", "kalam", "3alam"};
        iter(s, 3, f);
        return (0);
}
