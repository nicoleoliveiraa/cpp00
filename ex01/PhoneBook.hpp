/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:06:04 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/10/02 16:44:24 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

/* #include <iostream>
#include <sstream>
#include <string>
#include "Contact.hpp" */
#include"phonebookutils.hpp"

class PhoneBook
{
	private:
		Contact contact[8];
		int contact_nbr;

	public:
		PhoneBook();
		~PhoneBook();
		void add_contact();
		void search_contact();
};

#endif