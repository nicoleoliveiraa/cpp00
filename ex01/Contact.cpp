/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:48:25 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/10/01 13:14:24 by nsouza-o         ###   ########.fr       */
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
	// std::cout << this->first_name << std::endl;
	// std::cout << this->last_name << std::endl;
}