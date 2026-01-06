/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:35:17 by omghazi           #+#    #+#             */
/*   Updated: 2024/12/05 21:32:40 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base( void )
{
}

Base * Base::generate(void)
{
        int random;
        
        random = std::rand() % 3;
        if (random == 0)
            return (new A());
        if (random == 1)
            return (new B());
        return (new C());
}

void Base::identify(Base* p)
{
        if (dynamic_cast<A*>(p))
                std::cout << "Convert to A Successfully" << std::endl;
        else if (dynamic_cast<B*>(p))
                std::cout << "Convert to B Successfully" << std::endl;
        else if (dynamic_cast<C*>(p))
                std::cout << "Convert to C Successfully" << std::endl;
        else
                std::cout << "type not defined" << std::endl;

}

void Base::identify(Base& p)
{
        try
        {
                dynamic_cast<A&>(p);
                std::cout << "Convert to Reference to A Successfully" << std::endl;
        }
        catch(std::bad_cast &)
        {
                try
                {
                        dynamic_cast<B&>(p);
                        std::cout << "Convert to Reference to B Successfully" << std::endl;
                }
                catch(std::bad_cast &)
                {
                        try
                        {
                                dynamic_cast<C&>(p);
                                std::cout << "Convert to Reference to C Successfully" << std::endl;
                        }
                        catch(std::bad_cast &)
                        {
                                std::cout << "Type not defined" << std::endl;
                        }
                }
        }
}
