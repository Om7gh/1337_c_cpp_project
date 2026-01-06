/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:38:28 by omghazi           #+#    #+#             */
/*   Updated: 2024/11/01 11:44:56 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"


int main()
{
    const int animalCount = 4;
    Animal* animals[animalCount];

    
    for (int i = 0; i < animalCount / 2; ++i)
        animals[i] = new Dog();
    for (int i = animalCount / 2; i < animalCount; ++i)
        animals[i] = new Cat();
    
    for (int i = 0; i < animalCount; ++i)
    {
        std::cout << animals[i]->getType() << " says: ";
        animals[i]->makeSound();
    }
    for (int i = 0; i < animalCount; ++i)
        delete animals[i];
    Dog originalDog;
    Dog copiedDog (originalDog);
    copiedDog = originalDog;
    
    Cat originalCat;
    Cat copiedCat (originalCat);
    copiedCat = originalCat;
    
    return (EXIT_SUCCESS);
}
