/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 18:58:04 by locagnio          #+#    #+#             */
/*   Updated: 2025/02/15 20:46:24 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

/* 
	- ecrire sur la sortie standard : std::cout << (trucs a print) << std::endl;
	- std::cerr = sortie d'erreur
	- changer la base d'un nombre :
		* str::hex = hexadecimal
		* str::dec = decimal
		* str::oct = octale
	- scanf = std::cin >> (variable qui va recuperer l'entree standard)
	  pour l'afficher ; std::cout << (la variable) << std::endl
	- std::string : recupere une string dynamiquement;
	- (string).str() : recupere le formattage complet de la variable declaree avec std::stringstream
 */
/* namespace Os
{
	int var = 10;
	const float vers = 10.8;
}*/

int	main(int ac, char **av)
{
	if (ac == 1)
		return (std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl, 1);
	for (int i = 1; av[i]; i++)
	{
		std::string str = av[i];
		for (size_t j = 0; j < str.size(); ++j)
        	str[j] = std::toupper(static_cast<unsigned char>(str[j]));
		std::cout << str;
	}
	std::cout << std::endl;
	return (0);
}