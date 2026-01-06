/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:31:19 by omghazi           #+#    #+#             */
/*   Updated: 2024/12/04 18:09:59 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
    if (this != &other) {
        AForm::operator=(other);
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
        if (getSign() == 0)
            throw FormNotSignedException();
        if (executor.getGrade() > getGradeToExec())
            throw GradeTooLowException();
        std::ofstream outfile((getName() + "_shrubbery").c_str());
        if (!outfile)
            throw std::ios_base::failure("Error creating file");
        outfile << "         ; ; ;\n";
        outfile << "                   ;        ;  ;     ;;    ;\n";
        outfile << "                ;                 ;         ;  ;\n";
        outfile << "                                ;\n";
        outfile << "                               ;                ;; \n";
        outfile << "               ;          ;            ;              ;\n";
        outfile << "               ;            ';,        ;               ;\n";
        outfile << "               ;              'b      *\n";
        outfile << "                ;              '$    ;;                ;;\n";
        outfile << "               ;    ;           $:   ;:               ;\n";
        outfile << "             ;;      ;  ;;      *;  @):        ;   ; ;\n";
        outfile << "                          ;     :@,@):   ,;**:'   ;\n";
        outfile << "              ;      ;,         :@@*: ;;**'      ;   ;\n";
        outfile << "                       ';o;    ;:(@';@*\"'  ;\n";
        outfile << "               ;  ;       'bq,;;:,@@*'   ,*      ;  ;\n";
        outfile << "                          ,p$q8,:@)'  ;p*'      ;\n";
        outfile << "                   ;     '  ; '@@Pp@@*'    ;  ;\n";
        outfile << "                    ;  ; ;;    Y7'.'     ;  ;\n";
        outfile << "                              :@):.\n";
        outfile << "                             .:@:'.\n";
        outfile << "                           .::(@:.      -Omar Ghazi-\n";
        outfile.close();
        std::cout << "Shrubbery successfully created in " << getName() << "_shrubbery" << std::endl;
}
