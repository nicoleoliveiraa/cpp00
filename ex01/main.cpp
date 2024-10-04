/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:06:27 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/10/04 14:40:10 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

void signal_handler(int signal) 
{
    if (signal == SIGINT)
		return;
}

int main()
{
	PhoneBook PhoneBook;
	std::string command;

	signal(SIGINT, signal_handler);
	std::cout << BOLD_WHITE << "Enter one of these three commands:" << BOLD_RED \
	<< " ADD, SEARCH or EXIT" << RESET << std::endl;
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
		std::cout << std::endl;
		std::cout << BOLD_WHITE << "Enter one of these three commands:" << BOLD_RED \
		<< " ADD, SEARCH or EXIT" << RESET << std::endl;
	}
	return (0);
}