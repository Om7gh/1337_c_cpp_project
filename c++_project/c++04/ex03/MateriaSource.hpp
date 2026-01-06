/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 19:40:35 by omghazi           #+#    #+#             */
/*   Updated: 2024/11/01 20:13:47 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
        private:
                AMateria* templates[4];

        public:
                MateriaSource();
                ~MateriaSource();
                void learnMateria(AMateria* m);
                AMateria* createMateria(std::string const & type);
};
