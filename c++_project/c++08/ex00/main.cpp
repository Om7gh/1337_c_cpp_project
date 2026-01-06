/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:12:16 by omghazi           #+#    #+#             */
/*   Updated: 2024/12/09 21:56:13 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
        std::vector<int> table;
        try
        {
                table.push_back(1);
                table.push_back(2);
                table.push_back(3);
                table.push_back(4);
                table.push_back(5);
                table.push_back(6);
                std::vector<int>::iterator it = easyfind(table, 5);
                std::cout << *it << std::endl;
        }
        catch (std::exception &e)
        {
                std::cout << e.what() << std::endl;
        }

        std::list<int> list;
        try
        {
                list.push_back(1);
                list.push_back(10);
                list.push_back(100);
                list.push_back(1000);
                std::list<int>::iterator it = easyfind(list, 10);
                std::cout << *it << std::endl;

        }
        catch (std::exception &e)
        {
                std::cout << e.what() << std::endl;
        }
}
