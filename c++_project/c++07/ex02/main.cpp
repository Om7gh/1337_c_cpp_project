/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 12:04:08 by omghazi           #+#    #+#             */
/*   Updated: 2024/12/08 14:11:06 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
        try
        {
                Array<int> empty;
                Array <int> allocated_arr(5);

                std::cout << "empty size : " << empty.size() << std::endl;
                std::cout << "allocated_arr size : " << allocated_arr.size() << std::endl;
                
                for (unsigned int i = 0; i < allocated_arr.size(); i++)
                        allocated_arr[i] = 10 * i;
                for (unsigned int i = 0; i < allocated_arr.size(); i++)
                        std::cout << "allocted_arr" << "[" << i + 1 << "] : " << allocated_arr[i] << std::endl;
                std::cout << "----------------------------------------" << std::endl;
                Array<float> float_arr(10);
                for (unsigned int i = 0; i < float_arr.size(); i++)
                        float_arr[i] = 10.3 * i;
                for (unsigned int i = 0; i < float_arr.size(); i++)
                        std::cout << "float_arr" << "[" << i + 1 << "] : " << float_arr[i] << std::endl;
                std::cout << "----------------------------------------" << std::endl;
                Array<std::string> string_arr(4);
                std::string name = "omar";
                for (unsigned int i = 0; i < string_arr.size(); i++)
                        string_arr[i] = name;
                for (unsigned int i = 0; i < string_arr.size(); i++)
                        std::cout << "string_arr" << "[" << i + 1 << "] : " << string_arr[i] << std::endl;
                
        }
        catch (const std::exception& e)
        {
                std::cerr << "Exception caught: " << e.what() << "\n";
        }

        return (0);
}
