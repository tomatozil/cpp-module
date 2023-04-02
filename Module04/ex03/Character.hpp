#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter {
public:
	virtual std::string const & getName() const;
	virtual void equip(AMateria* m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter& target);

	Character();
	Character(std::string const & name);
	Character(Character const & origin);
	Character& operator=(Character const & character);
	~Character();

private:
	std::string name;
	AMateria* inventory[4];
};

#endif
