/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:12:33 by omghazi           #+#    #+#             */
/*   Updated: 2024/10/26 20:29:47 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>


int main()
{
        std::string      str;
        str = "HI THIS IS BRAIN";
        std::string     *stringPTR = &str;
        std::string     &stringREF = str;

        std::cout << "address :" << std::endl;
        std::cout << &str << std::endl;
        std::cout << stringPTR << std::endl;
        std::cout << &stringREF << std::endl;
        std::cout << "value :" << std::endl;
        std::cout << str << std::endl;
        std::cout << *stringPTR << std::endl;
        std::cout << stringREF << std::endl;
        return (EXIT_SUCCESS);
}
