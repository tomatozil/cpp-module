#include "Phonebook.hpp"

void Phonebook::AddContact() {
	int idx;

	idx = index % 8;
	contact[idx].SetFirstName();
	contact[idx].SetLastName();
	contact[idx].SetNickname();
	contact[idx].SetPhoneNumber();
	contact[idx].SetDarkestSecret();
	std::cout << std::endl;
	index++;
}

void Phonebook::PrintPhonebook() {
	std::cout << std::setw(44) << std::setfill('=') << "\n";
	std::cout << std::setfill(' ');
	std::cout << std::setw(10) << "INDEX" << "|";
	std::cout << std::setw(10) << "FIRST NAME" << "|";
	std::cout << std::setw(10) << "LAST NAME" << "|";
	std::cout << std::setw(10) << "NICKNAME" << "\n";
	for(int i = 0; i < std::min(index, 8); i++) {
		std::cout << std::setw(10) << i + 1 << "|";
		std::cout << std::setw(10) << CutTen(contact[i].GetFirstName()) << "|";
		std::cout << std::setw(10) << CutTen(contact[i].GetLastName()) << "|";
		std::cout << std::setw(10) << CutTen(contact[i].GetNickname()) << "\n";
	}
	std::cout << std::setw(44) << std::setfill('=') << "\n";
	std::cout << std::setfill(' ');
}

std::string Phonebook::CutTen(std::string str) {
	if (str.length() > 10)
		return str.substr(0, 9) + '.';
	return str;
}

void Phonebook::Search() {
	int selectedIdx;

	PrintPhonebook();
	if (index == 0) {
		std::cout << "THERE'S NO INFORMATION YET" << std::endl;
		return ;
	}
	while (true) {
		std::cout << "Choose the index you want" << std::endl;
		std::cin >> selectedIdx;
		if (std::cin.eof()) //ctrl c 눌렀을 때 (?!)
			return ;
		if (std::cin.fail()) { //숫자가 아닌 문자일 때
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Enter correct index number" << std::endl;
			continue ;
		}
		if (selectedIdx < 1 || selectedIdx > std::min(index, 8)) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Enter between 1 and " << std::min(index, 8) << std::endl;
			continue ;
		}
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		break ;
	}
	selectedIdx--;
	std::cout << std::setw(20) << "First Name: " << contact[selectedIdx].GetFirstName() << std::endl;
	std::cout << std::setw(20) << "Last Name: " << contact[selectedIdx].GetLastName() << std::endl;
	std::cout << std::setw(20) << "Nickname: " << contact[selectedIdx].GetNickname() << std::endl;
	std::cout << std::setw(20) << "Phone Number: " << contact[selectedIdx].GetPhoneNumber() << std::endl;
	std::cout << std::setw(20) << "Darkest Secret: " << contact[selectedIdx].GetDarkestSecret() << std::endl;
}

Phonebook::Phonebook() {
	index = 0;
}

Phonebook::~Phonebook() {}
