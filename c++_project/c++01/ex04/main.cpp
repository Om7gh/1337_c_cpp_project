/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 20:41:45 by omghazi           #+#    #+#             */
/*   Updated: 2024/10/25 11:07:50 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

std::string replaceOccurrences(const std::string& content, const std::string& s1, const std::string& s2)
{
        std::size_t pos = 0;
        std::size_t found;
        std::string result;

        if (s1.empty())
                return content;
        while ((found = content.find(s1, pos)) != std::string::npos)
        {
            result.append(content, pos, found - pos);
            result.append(s2);
            pos = found + s1.length();
        }
        result.append(content, pos, std::string::npos);
        return (result);
}

int main(int argc, char **argv)
{
        std::string     file;
        std::string     str1;
        std::string     str2;
        std::string     output;
        std::string     line;
        std::string     result;

        if (argc != 4)
        {
                std::cerr << "Error:" ;
                std::cerr << " Invalid number of arguments" << std::endl;
                return (1);
        }
        file = argv[1];
        str1 = argv[2];
        str2 = argv[3];
        std::ifstream   read_from(file);
        if (!read_from.is_open())
                return (std::cout << "can't open the file", EXIT_FAILURE);
        std::ofstream   create_write(file + ".replace");
        if (!create_write.is_open())
                return (std::cout << "can't open the file", EXIT_FAILURE);
        while (std::getline(read_from, line))
        {
                if (!read_from.eof())
                        output += line + "\n";
                else
                        output += line;
        }
        result = replaceOccurrences(output, str1, str2);
        create_write << result;
        read_from.close();
        create_write.close();
        return (EXIT_SUCCESS);
}
