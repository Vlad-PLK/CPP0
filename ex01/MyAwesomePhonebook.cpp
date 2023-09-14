/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyAwesomePhonebook.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:14:06 by vpolojie          #+#    #+#             */
/*   Updated: 2023/09/14 17:01:05 by vpolojie         ###   ########.fr       */
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
            phone.add();
        else if (input.compare("SEARCH") == 0)
            phone.search();
    }
    std::cout << "You've decided to exit, all contacts will be deleted forever..." << std::endl;
    return (0);
}