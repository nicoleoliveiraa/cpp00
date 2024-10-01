/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:06:27 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/10/01 21:07:27 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
	PhoneBook PhoneBook;
	std::string command;

	std::cout << "Enter one of these three commands: ADD, SEARCH or EXIT." \
	<< std::endl;
	while (1)
	{
		if (!std::getline(std::cin, command))
		{
			if (std::cin.eof())
				break ;
		}
		if (command == "EXIT")
			return (0);
		if (command == "ADD")
			PhoneBook.add_contact();
		if (command == "SEARCH")
			PhoneBook.search_contact();
		std::cout << "Enter one of these three commands: ADD, SEARCH or EXIT." \
		<< std::endl;
	}
	return (0);
}