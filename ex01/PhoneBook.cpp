/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:20:54 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/10/04 14:43:23 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->contact_nbr = 0;
	std::cout << std::endl;
	std::cout << BOLD_MAGENTA << "Welcome to your PhoneBook! 📞" << RESET << std::endl;
	std::cout << std::endl;
}

PhoneBook::~PhoneBook()
{
	std::cout << std::endl;
	std::cout << BOLD_MAGENTA << "Closing the PhoneBook, and all the contacts are lost forever!" << RESET << std::endl;
	std::cout << BOLD_MAGENTA << "BYE!! 👋" << RESET << std::endl;
	std::cout << std::endl;
}

std::string catch_line()
{
	std::string str;

	str = "";
	while (str == "")
	{
		if (!std::getline(std::cin, str))
		{
			if (std::cin.eof())
				break ;
		}
	}
	return (str);
}

void PhoneBook::add_contact()
{
	std::string str;
	int i;

	i = this->contact_nbr;
	std::cout << std::endl;
	std::cout << BOLD_RED << "Add new contact:" << RESET << std::endl;
	std::cout << std::endl;
	std::cout << BOLD_WHITE << "Enter the first name:" << RESET << std::endl;
	str = catch_line();
	this->contact[i].set_string(1, str);
	std::cout << std::endl;
	std::cout << BOLD_WHITE << "Enter the last name:" << RESET << std::endl;
	str = catch_line();
	this->contact[i].set_string(2, str);
	std::cout << std::endl;
	std::cout << BOLD_WHITE << "Enter the nickname:" << RESET << std::endl;
	str = catch_line();
	this->contact[i].set_string(3, str);
	std::cout << std::endl;
	std::cout << BOLD_WHITE << "Enter the phone number:" << RESET << std::endl;
	str = catch_line();
	this->contact[i].set_string(4, str);
	std::cout << std::endl;
	std::cout << BOLD_WHITE << "Enter the darkest secret:" << RESET << std::endl;
	str = catch_line();
	this->contact[i].set_string(5, str);
	if (i < 7)
		this->contact_nbr++;
}

void print_contact_string(std::string str)
{
	int i;

	i = str.length();
	if (i <= 10)
	{
		std::cout << str;
		while (i < 10)
		{
			std::cout << " ";
			i++;
		}
	}
	else
	{
		std::cout << str.substr(0, 9) << ".";
	}
}

std::string change_int_in_str(int i)
{
	i++;
	std::ostringstream oss;
    oss << i;

    return (oss.str());
}

int change_str_in_int(std::string index)
{
	int i;
	
	for (size_t j = 0; j < index.length(); ++j)
        if (!std::isdigit(index[j]))
            return (-1);
	std::istringstream iss(index);
    iss >> i;
	return (i - 1);
}

void PhoneBook::search_contact()
{
	int i = 0;
	std::string index;
	
	std::cout << std::endl;
	std::cout << BOLD_YELLOW << "Find a contact:" << RESET << std::endl;
	std::cout << std::endl;
	std::cout << BOLD_YELLOW << "---------------------------------------------" << RESET << std::endl;
	std::cout << BOLD_YELLOW << "|" << RESET;
	std::cout << WHITE << "  INDEX   " << RESET;
	std::cout << BOLD_YELLOW << "|" << RESET;
	std::cout << WHITE << " F. NAME  " << RESET;
	std::cout << BOLD_YELLOW << "|" << RESET;
	std::cout << WHITE << " L. NAME  " << RESET;
	std::cout << BOLD_YELLOW << "|" << RESET;
	std::cout << WHITE << " NICKNAME " << RESET;
	std::cout << BOLD_YELLOW << "|" << RESET << std::endl;
	std::cout << BOLD_YELLOW << "---------------------------------------------" << RESET << std::endl;
	while (i <= 7)
	{
		std::cout << BOLD_YELLOW << "|" << RESET;
		print_contact_string(change_int_in_str(i));
		std::cout << BOLD_YELLOW << "|" << RESET;
		print_contact_string(this->contact[i].get_string(1));
		std::cout << BOLD_YELLOW << "|" << RESET;
		print_contact_string(this->contact[i].get_string(2));
		std::cout << BOLD_YELLOW << "|" << RESET;
		print_contact_string(this->contact[i].get_string(3));
		std::cout << BOLD_YELLOW << "|" << RESET << std::endl;
		i++;
	}
	std::cout << BOLD_YELLOW << "---------------------------------------------" << RESET << std::endl;
	std::cout << std::endl;
	std::cout << BOLD_WHITE << "Choose one contact to see, by index:" << RESET << std::endl;
	index = catch_line();
	if (index == "")
		return ;
	std::cout << std::endl;
	i = change_str_in_int(index);
	if (i < 0 || i > 7)
		std::cout << RED << "Incorrect index!" << RESET << std::endl;
	else if (i > this->contact_nbr -1)
	{
		std::cout << RED << "This contact is empty!" << RESET << std::endl;
	}
	else
	{
		std::cout << BOLD_WHITE << "First Name:" << RESET << std::endl;
		std::cout << this->contact[i].get_string(1) << std::endl;
		std::cout << BOLD_WHITE << "Last Name:" << RESET << std::endl;
		std::cout << this->contact[i].get_string(2) << std::endl;
		std::cout << BOLD_WHITE << "Nickname:" << RESET << std::endl;
		std::cout << this->contact[i].get_string(3) << std::endl;
		std::cout << BOLD_WHITE << "Phone Number:" << RESET << std::endl;
		std::cout << this->contact[i].get_string(4) << std::endl;
		std::cout << BOLD_WHITE << "Darkest Secrect:" << RESET << std::endl;
		std::cout << this->contact[i].get_string(5) << std::endl;
	}
}