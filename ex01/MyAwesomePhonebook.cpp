/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyAwesomePhonebook.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:14:06 by vpolojie          #+#    #+#             */
/*   Updated: 2023/09/19 07:18:09 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>
#include "PhoneBook.hpp"
#include "Contact.hpp"

void    Contact::getdata()
{
    std::cout << "\n";
    std::cout << "You've decided to store a new contact, please fill the following questions : " << std::endl;
    std::cout << "FIRST NAME : " << std::endl;
    std::getline (std::cin, first_name);
    //std::cout << "LAST NAME : " << std::endl;
    //std::getline (std::cin, last_name);
    //std::cout << "NICKNAME : " << std::endl;
    //std::getline (std::cin, nickname);
    //std::cout << "PHONE NUMBER : " << std::endl;
    //std::getline (std::cin, phone_number);
    //std::cout << "DARKEST SECRET : " << std::endl;
    //std::getline (std::cin, darkest_secret);
}

void    PhoneBook::Add()
{
    c_tab[nb_contacts].getdata();
    if (nb_contacts < 7)
        nb_contacts++;
    else
    {
        std::cout << "You've reached the maximum capacity of the phonebook : " << std::endl;
        std::cout << "Your last contact will be replaced with this one !" << std::endl;
    }
    return ;
}

void    PhoneBook::Search()
{
    std::string separator = "+----------+----------+----------+----------+\n";
    std::string h1 = "index";
    std::string h2 = "first name";
    std::string h3 = "last name";
    std::string h4 = "nickname";
    std::string headers = "| " + h1 + " | " + h2 + " | " + h3 + " | " + h4 + " |\n";
    std::cout << separator;
    std::cout << "| " << std::setw(9) << h1 << "| ";
    h2.resize(8);
    h2.append(".");
    std::cout << h2 << "| ";
    std::cout << h3 << "| ";
    std::cout << std::setw(9) << h4 << "|\n";
    std::cout << separator;
    std::cout << separator;
}

int main(int argc, char **argv)
{
    (void)argv;
    std::string input;
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
        if (input.compare("EXIT") == 0)
            break ;
        else if (input.compare("ADD") == 0)
            phone.Add();
        else if (input.compare("SEARCH") == 0)
            phone.Search();
    }
    std::cout << "You've decided to exit, all contacts will be deleted forever..." << std::endl;
    return (0);
}