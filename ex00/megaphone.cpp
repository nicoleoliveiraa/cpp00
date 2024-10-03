/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:06:13 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/09/27 16:46:19 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

void	megaphone(char *str)
{
	int i = 0;
	while (str[i])
	{
		str[i] = std::toupper(str[i]);
		i++;
	}
	std::cout << str;
}

int	main(int ac, char **av)
{
	int i = 0;
	
	if (ac < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		while (++i < ac)
			megaphone(av[i]);
		std::cout << std::endl;
	}
	return (0);
}
