#ifndef HUMANA_H_
# define HUMANA_H_

# include "Weapon.hpp"

class HumanA {

public:
	void attack();
	HumanA(std::string name, Weapon& weapon);
	~HumanA();

private:
	std::string name_;
	Weapon& weapon_;
};

#endif