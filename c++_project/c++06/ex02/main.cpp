/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 21:04:15 by omghazi           #+#    #+#             */
/*   Updated: 2024/12/05 21:31:18 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

int main()
{
        std::srand(std::time(0));
        Base *instance = new Base();
        for (int i = 0; i < 3; ++i)
        {
                Base *p = instance->generate();
                instance->identify(p);
                instance->identify(*p);
                delete p;
        }
        delete instance;
    return 0;
}
