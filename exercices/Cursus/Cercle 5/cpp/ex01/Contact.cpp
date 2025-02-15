/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 18:58:04 by locagnio          #+#    #+#             */
/*   Updated: 2025/02/15 21:15:36 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() : firstName(""), lastName(""), nickname(""), phoneNumber(""), darkestSecret("") {}

void Contact::setFirstName(const std::string& firstName)
{
    this->firstName = firstName;
}

void Contact::setLastName(const std::string& lastName)
{
    this->lastName = lastName;
}

void Contact::setNickname(const std::string& nickname)
{
    this->nickname = nickname;
}

void Contact::setPhoneNumber(const std::string& phoneNumber)
{
    this->phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(const std::string& darkestSecret)
{
    this->darkestSecret = darkestSecret;
}

std::string Contact::getFirstName() const
{
    return (firstName);
}

std::string Contact::getLastName() const
{
    return (lastName);
}

std::string Contact::getNickname() const
{
    return (nickname);
}

std::string Contact::getPhoneNumber() const
{
    return (phoneNumber);
}

std::string Contact::getDarkestSecret() const
{
    return (darkestSecret);
}

void Contact::displaySummary() const
{
	/* auto evite d'ecrire : std::function<std::string(const std::string&)> truncate*/
    auto truncate = [](const std::string& str)
	{
        return str.length() > 10 ? str.substr(0, 9) + "." : str;
    };

    std::cout << "|" << std::right << std::setw(10) << truncate(firstName) 
              << "|" << std::right << std::setw(10) << truncate(lastName) 
              << "|" << std::right << std::setw(10) << truncate(nickname) << "|" << std::endl;
}

void Contact::displayFullInfo() const
{
    std::cout << "First Name: " << firstName << std::endl;
    std::cout << "Last Name: " << lastName << std::endl;
    std::cout << "Nickname: " << nickname << std::endl;
    std::cout << "Phone Number: " << phoneNumber << std::endl;
    std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}