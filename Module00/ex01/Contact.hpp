#ifndef CONTACT_H_
# define CONTACT_H_

# include <iostream>

class Contact {
public:
	void SetFirstName();
	void SetLastName();
	void SetNickname();
	void SetPhoneNumber();
	void SetDarkestSecret();
	std::string GetFirstName();
	std::string GetLastName();
	std::string GetNickname();
	std::string GetPhoneNumber();
	std::string GetDarkestSecret();
	Contact();
	~Contact();

private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;
};

#endif
