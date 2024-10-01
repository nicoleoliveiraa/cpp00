/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:48:25 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/10/01 15:52:58 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::set_string(int i, std::string str)
{
	switch (i)
	{
		case 1:
			this->first_name = str;
			break;
		case 2:
			this->last_name = str;
			break;
		case 3:
			this->nickname = str;
			break;
		case 4:
			this->phone_number = str;
			break;
		case 5:
			this->darkest_secret = str;
			break;
		default:
			break;
	}
}

std::string Contact::get_string(int i)
{
	switch (i)
	{
		case 1:
			return this->first_name;
		case 2:
			return this->last_name;
		case 3:
			return this->nickname;
		case 4:
			return this->phone_number;
		case 5:
			return this->darkest_secret;
	}
	return NULL;
}