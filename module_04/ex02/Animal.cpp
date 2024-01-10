/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:59:26 by kmatos-s          #+#    #+#             */
/*   Updated: 2024/01/10 18:28:18 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() {
    std::cout << "Contructed Animal" << std::endl;
}

Animal::Animal(const Animal &value) {
    this->type = value.type;
}

Animal& Animal::operator=(const Animal &value) {
    *this = value;
    return *this;
}

Animal::~Animal() {
    std::cout << "Destroyed Animal" << std::endl;
}

std::string Animal::getType() const {
    return this->type;
}
