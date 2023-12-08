/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:41:28 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/12/08 20:32:36 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int       ClapTrap::clap_traps_length = 0;
ClapTrap  *ClapTrap::clap_traps[];

ClapTrap::ClapTrap(std::string name):
    name(name),
    hit_points(10),
    energy_points(10),
    attack_damage(0)
{
    ClapTrap::appendClapTrap(this);
    std::cout << "ClapTrap " << this->name << " instantiated" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &value):
    name(value.name),
    hit_points(value.hit_points),
    energy_points(value.energy_points),
    attack_damage(value.attack_damage) {
    ClapTrap::appendClapTrap(this);
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs) {
    if (this != &rhs) {
        this->name = rhs.name;
        this->attack_damage = rhs.attack_damage;
        this->energy_points = rhs.energy_points;
        this->hit_points = rhs.hit_points;
    }
    return *this;
}

ClapTrap::~ClapTrap(void) {
    this->removeClapTrap(this);
    std::cout << "ClapTrap destroyed" << std::endl;
}

void ClapTrap::attack(const std::string &target) {
    if (!this->canAct()) {
        if (this->isDead()) {
            std::cout << "ClapTrap " << this->name << " tries to attack " << target << ", but he notices that he is already dead!" << std::endl;
        } else if (this->isOutOfEnergy()) {
            std::cout << "ClapTrap " << this->name << " tries to attack " << target << ", but he notices that he is out of energy!" << std::endl;
        }
        return ;
    }

    ClapTrap *found = ClapTrap::getClapTrap(target);
    if (!found) {
        std::cout << "ClapTrap " << this->name << " couldn't find ClapTrap " << target << "!" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;

    found->takeDamage(this->attack_damage);
    this->consumeEnergy();
}

void ClapTrap::takeDamage(unsigned int amount) {
    this->hit_points -= amount;
    if (this->hit_points < 0) {
        this->hit_points = 0;
        return ;
    }
    std::cout << "ClapTrap " << this->name << " received " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (!this->canAct()) {
        if (this->isDead()) {
            std::cout << "ClapTrap " << this->name << " tries to repair itself, but he notices that he is already dead!" << std::endl;
        } else if (this->isOutOfEnergy()) {
            std::cout << "ClapTrap " << this->name << " tries to repair itself, but he notices that he is out of energy!" << std::endl;
        }
        return ;
    }

    this->hit_points += amount;
    if (this->hit_points > 10) {
        this->hit_points = 10;
        return ;
    }
    this->consumeEnergy();
    std::cout << "ClapTrap " << this->name << " repaired " << amount << " points of health!" << std::endl;
}

void ClapTrap::log(void) {
    std::cout << std::endl;
    std::cout << "----------------------"<< std::endl;
    std::cout << this->name << " Stats" << std::endl;
    std::cout << "Health -------- " << this->hit_points << std::endl;
    std::cout << "Energy -------- " << this->energy_points << std::endl;
    std::cout << "Attack Damage - " << this->attack_damage << std::endl;
    std::cout << "----------------------" << std::endl;
    std::cout << std::endl;
}

//
// Getters / Setters
//

std::string ClapTrap::getName(void) {
    return this->name;
}

void ClapTrap::setDamage(unsigned int amount) {
    this->attack_damage = amount;
}

bool ClapTrap::canAct(void) {
    return !this->isDead() && !this->isOutOfEnergy();
}

bool ClapTrap::isDead(void) {
    return this->hit_points == 0;
}

//
// Private
//
bool ClapTrap::isOutOfEnergy(void) {
    return this->energy_points == 0;
}

void ClapTrap::consumeEnergy(unsigned int amount) {
    this->energy_points -= amount;
    if (this->energy_points < 0) {
        this->energy_points = 0;
    }
}

void ClapTrap::appendClapTrap(ClapTrap *clap_trap) {
    ClapTrap::clap_traps[ClapTrap::clap_traps_length] = clap_trap;
    ClapTrap::clap_traps_length += 1;
}

void ClapTrap::removeClapTrap(ClapTrap *clap_trap) {
    for (int i = 0; i < ClapTrap::clap_traps_length; i++) {
        if (ClapTrap::clap_traps[i]->getName() == clap_trap->getName()) {

            for (; i < ClapTrap::clap_traps_length; i++) {
                if (i + 1 < ClapTrap::clap_traps_length) {
                    ClapTrap::clap_traps[i] = ClapTrap::clap_traps[i + 1];
                    ClapTrap::clap_traps[i + 1] = NULL;
                    ClapTrap::clap_traps_length -= 1;
                } else {
                    ClapTrap::clap_traps[i] = NULL;
                    ClapTrap::clap_traps_length -= 1;
                }
            }

            break ;
        }
    }
}

ClapTrap* ClapTrap::getClapTrap(const std::string name) {
    for (int i = 0; i < ClapTrap::clap_traps_length; i++) {
        ClapTrap *clap_trap = ClapTrap::clap_traps[i];

        if (clap_trap->getName() == name) {
            return clap_trap;
        }
    }
    return NULL;
}
