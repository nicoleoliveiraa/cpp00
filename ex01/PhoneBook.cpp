/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:20:54 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/10/01 13:33:49 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->contact_nbr = 0;
	std::cout << "Welcome to your PhoneBook!" << std::endl;
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
}