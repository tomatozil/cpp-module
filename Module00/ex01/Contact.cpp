#include "Contact.hpp"

void Contact::SetFirstName() {
	std::cout << "first name: ";
	std::getline(std::cin, firstName);
	if (std::cin.eof())
		return ;
	if (firstName.length() < 1) {
		std::cout << "Enter first name correctly" << std::endl;
		SetFirstName();
	}
}

void Contact::SetLastName() {
	if (firstName.empty())
		return ;
	std::cout << "last name: ";
	std::getline(std::cin, lastName);
	if (std::cin.eof())
		return ;
	if (lastName.length() < 1) {
		std::cout << "Enter last name correctly" << std::endl;
		SetLastName();
	}
}

void Contact::SetNickname() {
	if (lastName.empty())
		return ;
	std::cout << "nickname: ";
	std::getline(std::cin, nickname);
	if (std::cin.eof())
		return ;
	if (nickname.length() < 1) {
		std::cout << "Enter nickname correctly" << std::endl;
		SetNickname();
	}
}

void Contact::SetPhoneNumber() {
	if (nickname.empty())
		return ;
	std::cout << "phone number: ";
	std::getline(std::cin, phoneNumber);
	if (std::cin.eof())
		return ;
	if (phoneNumber.length() < 1) {
		std::cout << "Enter phone number correctly" << std::endl;
		SetPhoneNumber();
	}
}

void Contact::SetDarkestSecret() {
	if (phoneNumber.empty())
		return ;
	std::cout << "darkest secret: ";
	std::getline(std::cin, darkestSecret);
	if (std::cin.eof())
		return ;
	if (darkestSecret.length() < 1) {
		std::cout << "Enter darkest secret correctly" << std::endl;
		SetDarkestSecret();
	}
}

std::string Contact::GetFirstName() {
	return firstName;
}

std::string Contact::GetLastName() {
	return lastName;
}

std::string Contact::GetNickname() {
	return nickname;
}

std::string Contact::GetPhoneNumber() {
	return phoneNumber;
}

std::string Contact::GetDarkestSecret() {
	return darkestSecret;
}

Contact::Contact() {}

Contact::~Contact() {}
