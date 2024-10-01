/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:20:54 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/10/01 16:27:08 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->contact_nbr = 0;
	std::cout << "Welcome to your PhoneBook!" << std::endl;
}

PhoneBook::~PhoneBook()
{
	std::cout << "All the contacts are lost forever!!" << std::endl;
}

std::string catch_line()
{
	std::string str;

	str = "";
	while (str == "")
		std::getline(std::cin, str);
	return (str);
}

void PhoneBook::add_contact()
{
	std::string str;
	int i;

	i = this->contact_nbr;
	std::cout << i << std::endl;
	std::cout << "Add new contact:" << std::endl;
	std::cout << "Enter the first name:" << std::endl;
	str = catch_line();
	this->contact[i].set_string(1, str);
	std::cout << "Enter the last name:" << std::endl;
	str = catch_line();
	this->contact[i].set_string(2, str);
	std::cout << "Enter the nickname:" << std::endl;
	str = catch_line();
	this->contact[i].set_string(3, str);
	std::cout << "Enter the phone number:" << std::endl;
	str = catch_line();
	this->contact[i].set_string(4, str);
	std::cout << "Enter the darkest secret:" << std::endl;
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
	
	std::cout << "---------------------------------------------" << std::endl;
	while (i <= 7)
	{
		std::cout << "|";
		print_contact_string(change_int_in_str(i));
		std::cout << "|";
		print_contact_string(this->contact[i].get_string(1));
		std::cout << "|";
		print_contact_string(this->contact[i].get_string(2));
		std::cout << "|";
		print_contact_string(this->contact[i].get_string(3));
		std::cout << "|" << std::endl;
		i++;
	}
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "Choose one contact to see, by index:" << std::endl;
	index = catch_line();
	i = change_str_in_int(index);
	if (i < 0 || i > 7)
		std::cout << "Incorrect index!" << std::endl;
	else
	{
		std::cout << "First Name:" << std::endl;
		std::cout << this->contact[i].get_string(1) << std::endl;
		std::cout << "Last Name:" << std::endl;
		std::cout << this->contact[i].get_string(2) << std::endl;
		std::cout << "Nickname:" << std::endl;
		std::cout << this->contact[i].get_string(3) << std::endl;
		std::cout << "Phone Number:" << std::endl;
		std::cout << this->contact[i].get_string(4) << std::endl;
		std::cout << "Darkest Secrect:" << std::endl;
		std::cout << this->contact[i].get_string(5) << std::endl;
	}
}