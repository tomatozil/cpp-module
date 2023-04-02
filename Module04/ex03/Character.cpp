#include "Character.hpp"

std::string const & Character::getName() const {
	return (name);
}

void Character::equip(AMateria* m) {
	if (!m) {
		std::cout << "Equip Fail: invalid Materia." << std::endl;
	}
	for(int i = 0; i < 4; i++) {
		if (!inventory[i]) {
			inventory[i] = m;
			return ;
		}
	}
	std::cout << "Equip Fail: " << name << "'s inventory is full." << std::endl;
}

void Character::unequip(int idx) {
	if (idx >= 4) {
		std::cout << "Equip Fail: idx doesn't exist." << std::endl;
		return ;
	}
	if (!inventory[idx]) {
		std::cout << "Equip Fail: Materia doesn't exist." << std::endl;
		return ;
	}
	inventory[idx] = 0;
}

void Character::use(int idx, ICharacter &target) {
	if (idx >= 4) {
		std::cout << "Use Fail: idx doesn't exist." << std::endl;
		return ;
	}
	if (!inventory[idx]) {
		std::cout << "Use Fail: Materia doesn't exist." << std::endl;
		return ;
	}
	inventory[idx]->use(target);
}

Character::Character() : name("Unknown"), inventory() {
	for(int i = 0; i < 4; i++)
		inventory[i] = 0;
}

Character::Character(const std::string &name) : name(name) , inventory() {
	for(int i = 0; i < 4; i++)
		inventory[i] = 0;
}

Character::Character(const Character &origin) : name(origin.name) {
	for(int i = 0; i < 4; i++) {
		if (origin.inventory[i])
			inventory[i] = origin.inventory[i]->clone();
	}
}

Character& Character::operator=(const Character &character) {
	if (this == &character)
		return (*this);
	name = character.name;
	for(int i = 0; i < 4; i++) {
		if (inventory[i])
			delete inventory[i];
		if (character.inventory[i])
			inventory[i] = character.inventory[i]->clone();
		else
			inventory[i] = 0;
	}
	return (*this);
}

Character::~Character() {
	for(int i = 0; i < 4; i++)
		if (inventory[i])
			delete inventory[i];
}