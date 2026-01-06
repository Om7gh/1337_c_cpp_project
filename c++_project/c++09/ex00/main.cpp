/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meserghi <meserghi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:53:45 by meserghi          #+#    #+#             */
/*   Updated: 2024/12/28 13:13:08 by meserghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
        if (ac != 2)
                std::cout << "Error\nEnter input file" << std::endl;
        else
        {
	        try
                {
                        std::string data = "data.csv";
                        std::string input = av[1];
                        BitcoinExchange btc(data, input);
                }
                catch(const std::exception& e)
                {
                        std::cerr << e.what() << '\n';
                }
        }
        return (0);
}
