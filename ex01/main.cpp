/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:14:06 by vpolojie          #+#    #+#             */
/*   Updated: 2023/10/28 15:51:18 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>
#include "PhoneBook.hpp"
#include "Contact.hpp"

int main(int argc, char **argv)
{
    (void)argv;
    std::string input;
    PhoneBook   phone;
    phone.setLastContact(0);
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
