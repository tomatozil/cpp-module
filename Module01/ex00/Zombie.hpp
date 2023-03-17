#ifndef ZOMBIE_H_
# define ZOMBIE_H_

# include <iostream>

class Zombie {

public:
	void announce();
	static Zombie *newZombie(std::string name);
	static void randomChump(std::string name);
	explicit Zombie(std::string name);
	~Zombie();

private:
	std::string name;
};

#endif
