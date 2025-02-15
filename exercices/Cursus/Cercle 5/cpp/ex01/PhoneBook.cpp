/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locagnio <locagnio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 18:58:04 by locagnio          #+#    #+#             */
/*   Updated: 2025/02/15 20:35:55 by locagnio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : currentIndex(0) {}

void PhoneBook::addContact()
{
    Contact newContact;
    std::string input;

    std::cout << "Enter First Name: ";
    std::getline(std::cin, input);
    newContact.setFirstName(input);

    std::cout << "Enter Last Name: ";
    std::getline(std::cin, input);
    newContact.setLastName(input);

    std::cout << "Enter Nickname: ";
    std::getline(std::cin, input);
    newContact.setNickname(input);

    std::cout << "Enter Phone Number: ";
    std::getline(std::cin, input);
    newContact.setPhoneNumber(input);

    std::cout << "Enter Darkest Secret: ";
    std::getline(std::cin, input);
    newContact.setDarkestSecret(input);

    // Ajout du contact, ou remplacement du plus ancien si le répertoire est plein
    if (currentIndex < 8)
        contacts[currentIndex++] = newContact;
    else
	{
        for (int i = 1; i < 8; ++i)
            contacts[i - 1] = contacts[i];  // Décaler les contacts
        contacts[7] = newContact;  // Remplacer le plus ancien contact
    }
}

void PhoneBook::searchContacts() const
{
    displayContacts();

    int index;
    std::cout << "Enter index to view full information: ";
    std::cin >> index;
    std::cin.ignore();  // Ignore the newline character left by std::cin

    if (index < 0 || index >= currentIndex)
        std::cout << "Invalid index." << std::endl;
    else
        contacts[index].displayFullInfo();
}

void PhoneBook::displayContacts() const
{
    std::cout << "|----------|----------|----------|----------|" << std::endl;
    std::cout << "| Index    | First Name | Last Name | Nickname |" << std::endl;
    std::cout << "|----------|----------|----------|----------|" << std::endl;
    for (int i = 0; i < currentIndex; ++i)
	{
        std::cout << "|" << std::right << std::setw(10) << i << "|";
        contacts[i].displaySummary();
    }
}