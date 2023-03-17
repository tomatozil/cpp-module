#ifndef HUMANB_H_
# define HUMANB_H_

# include "Weapon.hpp"

class HumanB {

public:
	void attack();
	void setWeapon(Weapon& weapon);
	HumanB(std::string name);
	~HumanB();

private:
	std::string name_;
	Weapon* weapon_;
};

#endif