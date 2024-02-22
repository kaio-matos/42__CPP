/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 20:59:04 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/02/21 21:21:49 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(
    std::string target) : AForm("Shrubbery Creation Form", 145, 137), target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &value) : AForm(value.getName(), value.getGradeToSign(), value.getGradeToExecute()), target(value.target)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
    AForm::operator=(rhs);
    *this = rhs;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    this->validateExecution(executor);

    std::ofstream output_file;
    output_file.open((this->target + "_shrubbery").c_str());
    output_file << "\n"
                   "\n"
                   "\n"
                   "\n"
                   "                                  # #### ####\n"
                   "                                ### \\/#|### |/####\n"
                   "                               ##\\/#/ \\||/##/_/##/_#\n"
                   "                             ###  \\/###|/ \\/ # ###\n"
                   "                           ##_\\_#\\_\\## | #/###_/_####\n"
                   "                          ## #### # \\ #| /  #### ##/##\n"
                   "                           __#_--###`  |{,###---###-~\n"
                   "                                     \\ }{\n"
                   "                                      }}{\n"
                   "                                      }}{\n"
                   "                                 ejm  {{}\n"
                   "                                , -=-~{ .-^- _\n"
                   "                                      `}\n"
                   "                                       {\n"
                   "\n"
                   "\n"
                   "\n"
                   "\n"
                   "\n"
                   "\n"
                   "          &&& &&  & &&\n"
                   "      && &\\/&\\|& ()|/ @, &&\n"
                   "      &\\/(/&/&||/& /_/)_&/_&\n"
                   "   &() &\\/&|()|/&\\/ '%\" & ()\n"
                   "  &_\\_&&_\\ |& |&&/&__%_/_& &&\n"
                   "&&   && & &| &| /& & % ()& /&&\n"
                   " ()&_---()&\\&\\|&&-&&--%---()~\n"
                   "     &&     \\|||\n"
                   "             |||\n"
                   "             |||\n"
                   "             |||\n"
                   "       , -=-~  .-^- _\n"
                   "ejm97         `\n"
                   "\n"
                   "\n"
                   "\n"
                   "\n"
                   "\n"
                   "       ###\n"
                   "      #o###\n"
                   "    #####o###\n"
                   "   #o#\\#|#/###\n"
                   "    ###\\|/#o#\n"
                   "     # }|{  #\n"
                   "ejm97  }|{\n"
                   "\n"
                   "\n"
                   "\n"
                   "\n"
                   "\n"
                   "\n"
                   "\n"
                   "\n"
                   "\n"
                   "\n"
                   "\n"
                   "    oxoxoo    ooxoo\n"
                   "  ooxoxo oo  oxoxooo\n"
                   " oooo xxoxoo ooo ooox\n"
                   " oxo o oxoxo  xoxxoxo\n"
                   "  oxo xooxoooo o ooo\n"
                   "    ooo\\oo\\  /o/o\n"
                   "        \\  \\/ /\n"
                   "         |   /\n"
                   "         |  |\n"
                   "         | D|\n"
                   "         |  |\n"
                   "         |  |\n"
                   "  ______/____\\____\n"
                   " Christopher S McDowell\n"
                   "\n"
                   "\n"
                   "     ccee88oo\n"
                   "  C8O8O8Q8PoOb o8oo\n"
                   " dOB69QO8PdUOpugoO9bD\n"
                   "CgggbU8OU qOp qOdoUOdcb\n"
                   "    6OuU  /p u gcoUodpP\n"
                   "      \\\\\\//  /douUP\n"
                   "        \\\\\\////\n"
                   "         |||/\\\n"
                   "         |||\\/\n"
                   "         |||||\n"
                   "   .....//||||\\....\n"
                   "   David Moore\n"
                   "\n"
                   "\n"
                   "Sydney Harper\n"
                   "                                    @\n"
                   "                              @ @ @  @ @ @\n"
                   "                            @  @\\/@ @ /__@\n"
                   "                            @@@ @\\ / @/  @ @\n"
                   "                           @\\  \\/@| @ | @\n"
                   "                          @__\\@ \\ |/ \\| / @\n"
                   "                             __\\|@|  ||/__/@\n"
                   "                            /  \\ \\\\  / /__\n"
                   "                           @    \\  \\/ /   @\n"
                   "                                 |\" '|\n"
                   "                                 |\"  |\n"
                   "                                 |\"  |\n"
                   "                                ~|\"  |~\n"
                   "                            ~~~~       ~~~~\n"
                   "                          ~~               ~~~\n"
                   "\n"
                   "\n"
                   "\n"
                   "\n"
                   "\n"
                   "\n"
                   "\n"
                   "\n"
                   "\n"
                   "               ,@@@@@@@,\n"
                   "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
                   "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
                   "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
                   "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
                   "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"
                   "   `&%\\ ` /%&'    |.|        \\ '|8'\n"
                   "       |o|        | |         | |\n"
                   "       |.|        | |         | |\n"
                   "jgs \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_\n"
                   "\n"
                   "\n"
                   "\n"
                   "\n"
                   "\n"
                   "\n"
                   "\n"
                   "\n"
                   "\n"
                   "\n"
                   "\n"
                   "                  %%%,%%%%%%%\n"
                   "                   ,'%% \\\\-*%%%%%%%\n"
                   "             ;%%%%%*%   _%%%%\"\n"
                   "              ,%%%       \\(_.*%%%%.\n"
                   "              % *%%, ,%%%%*(    '\n"
                   "            %^     ,*%%% )\\|,%%*%,_\n"
                   "                 *%    \\/ #).-\"*%%*\n"
                   "                     _.) ,/ *%,\n"
                   "             _________/)#(_____________\n"
                   "            b'ger\n"
                   "\n"
                   "\n"
                   "\n"
                   "\n"
                   "\n"
                   "\n"
                   "\n"
                   "\n"
                   "\n"
                   "                            '.,\n"
                   "                              'b      *\n"
                   "                               '$    #.\n"
                   "                                $:   #:\n"
                   "                                *#  @):\n"
                   "                                :@,@):   ,.**:'\n"
                   "                      ,         :@@*: ..**'\n"
                   "                       '#o.    .:(@'.@*\"'\n"
                   "                          'bq,..:,@@*'   ,*\n"
                   "                          ,p$q8,:@)'  .p*'\n"
                   "                         '    '@@Pp@@*'\n"
                   "                               Y7'.'\n"
                   "                              :@):.\n"
                   "                             .:@:'.\n"
                   "                           .::(@:.      -Sam Blumenstein-\n"
                   "\n"
                   "\n"
                   "\n"
                   "\n"
                   "\n"
                   "                     . . .\n"
                   "                   .        .  .     ..    .\n"
                   "                .                 .         .  .\n"
                   "                                .\n"
                   "                               .                ..\n"
                   "               .          .            .              .\n"
                   "               .            '.,        .               .\n"
                   "               .              'b      *\n"
                   "                .              '$    #.                ..\n"
                   "               .    .           $:   #:               .\n"
                   "             ..      .  ..      *#  @):        .   . .\n"
                   "                          .     :@,@):   ,.**:'   .\n"
                   "              .      .,         :@@*: ..**'      .   .\n"
                   "                       '#o.    .:(@'.@*\"'  .\n"
                   "               .  .       'bq,..:,@@*'   ,*      .  .\n"
                   "                          ,p$q8,:@)'  .p*'      .\n"
                   "                   .     '  . '@@Pp@@*'    .  .\n"
                   "                    .  . ..    Y7'.'     .  .\n"
                   "                              :@):.\n"
                   "                             .:@:'.\n"
                   "                           .::(@:.      -Sam Blumenstein-";
    output_file.close();
};
