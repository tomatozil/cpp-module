#ifndef WEAPON_H_
# define WEAPON_H_

# include <iostream>

class Weapon {

public:
	void setType(std::string type);
	const std::string& getType();
	Weapon(std::string type);
	~Weapon();

private:
	std::string type_;
};

#endif
