/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 09:31:46 by vpolojie          #+#    #+#             */
/*   Updated: 2023/10/09 13:42:57 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <string>

void    Contact::showdata()
{
    int i;

    i = 0;
    std::cout << "\n";
    while (i != 5)
    {
        std::cout << ask_data[i] << data[i] << std::endl;
        i++;
    }
    std::cout << "\n";
}

void    Contact::set_askdata()
{
    ask_data[0].append("FIRST NAME : ");
    ask_data[1].append("LAST NAME : ");
    ask_data[2].append("NICKNAME : ");
    ask_data[3].append("PHONE NUMBER : ");
    ask_data[4].append("DARKEST SECRET : ");
}

void    Contact::getdata()
{
    int i;

    i = 0;
    std::cout << "\n";
    std::cout << "You've decided to store a new contact, please fill the following infos : " << std::endl;
    while (i != 5)
    {
        std::cout << ask_data[i] << std::endl;
        while (true)
        {
            std::getline (std::cin, data[i]);
            if (data[i].empty())
                std::cout << "You can't have missing infos !" << std::endl;
            else
                break ;
        }
        i++;
    }
}
