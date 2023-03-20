#ifndef ZOMBIE_H_
# define ZOMBIE_H_

# include <iostream>

class Zombie {
public:
	void announce();
	static Zombie *zombieHorde(int N, std::string name);
	void setName(std::string name);
	Zombie();
	~Zombie();

private:
	std::string name;
};

#endif
