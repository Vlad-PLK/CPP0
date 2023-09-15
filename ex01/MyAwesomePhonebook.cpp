/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyAwesomePhonebook.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:14:06 by vpolojie          #+#    #+#             */
/*   Updated: 2023/09/15 13:57:36 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>
#include "PhoneBook.hpp"
#include "Contact.hpp"

void Add(PhoneBook& phone, Contact& nv_contact)
{
    phone.c_tab[phone.nb_contacts] = nv_contact;
    std::cout << "\n";
    std::cout << "You've decided to store a new contact, please fill the following questions : " << std::endl;
    std::cout << "FIRST NAME : " << std::endl;
    std::getline (std::cin, nv_contact.first_name);
    std::cout << "LAST NAME : " << std::endl;
    std::getline (std::cin, nv_contact.last_name);
    std::cout << "NICKNAME : " << std::endl;
    std::getline (std::cin, nv_contact.nickname);
    std::cout << "PHONE NUMBER : " << std::endl;
    std::getline (std::cin, nv_contact.phone_number);
    std::cout << "DARKEST SECRET : " << std::endl;
    std::getline (std::cin, nv_contact.darkest_secret);
    if (phone.nb_contacts < 7)
        phone.nb_contacts++;
    return ;
}

int main(int argc, char **argv)
{
    (void)argv;
    std::string input;
    Contact     new_contact;
    PhoneBook   phone;
    phone.nb_contacts = 0;
    if (argc != 1)
    {
        std::cout << "No arguments required" << std::endl;
        return (1);
    }
    while (true)
    {
        std::cout << "Hi, please enter one of the following commands : ADD, SEARCH, EXIT" << std::endl;
        std::getline (std::cin, input);
        // ask about bad input "     EXIT" //
        if (input.compare("EXIT") == 0)
            break ;
        else if (input.compare("ADD") == 0)
        {
            Add(phone, new_contact);
        }
        else if (input.compare("SEARCH") == 0)
        {//
            //std::string ct;
            //ct = phone.c_tab[0].first_name + phone.c_tab[0].last_name + phone.c_tab[0].nickname;
            std::cout << phone.c_tab[0].first_name << std::endl;
        }
    }
    std::cout << "You've decided to exit, all contacts will be deleted forever..." << std::endl;
    return (0);
}