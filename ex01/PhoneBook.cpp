/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 09:31:53 by vpolojie          #+#    #+#             */
/*   Updated: 2023/09/22 09:35:05 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <string>

void    PhoneBook::Add()
{
    int i;

    if (nb_contacts < 8)
    {
        c_tab[nb_contacts].set_askdata();
        c_tab[nb_contacts].getdata();
        nb_contacts++;
    }
    else
    {
        std::cout << "You've reached the maximum capacity of the phonebook : " << std::endl;
        std::cout << "Your last contact will be replaced with the new one !" << std::endl;
        i = 0;
        while (i != 4)
        {
            c_tab[7].data[i].clear();
            i++;
        }
        c_tab[7].getdata();
    }
    return ;
}

void    PhoneBook::Contact_info(int i)
{
    int j;

    j = 0;
    std::cout << std::setw(2) << i << "| ";
    while (j != 2)
    {
        if (c_tab[i].data[j].size() > 8)
        {
            c_tab[i].data[j].resize(8);
            c_tab[i].data[j].append(".");
            std::string info = c_tab[i].data[j];
            std::cout << info;
            if (j <= 1)
                std::cout << "| ";
        }
        j++;
    }
}

void    PhoneBook::Search()
{

    std::string separator = "+----------+----------+----------+----------+\n";
    std::string h1 = "index";
    std::string h2 = "first name";
    std::string h3 = "last name";
    std::string h4 = "nickname";
    int     i;
    int     j;

    i = 0;
    if (nb_contacts == 0)
    {
        std::cout << "You don't have any contacts yet !" << std::endl;
        return ;
    }
    std::cout << separator;
    std::cout << "| " << std::setw(9) << h1 << "| ";
    h2.resize(8);
    h2.append(".");
    std::cout << h2 << "| ";
    std::cout << h3 << "| ";
    std::cout << std::setw(9) << h4 << "|\n";
    std::cout << separator;
    while (i != nb_contacts)
    {
        std::cout << "| ";
        std::cout << std::setw(9) << i + 1 << "| ";
        j = 0;
        while (j != 3)
        {
            if (c_tab[i].data[j].size() > 8)
            {
                c_tab[i].data[j].resize(8);
                c_tab[i].data[j].append(".");
            }
            std::cout << std::setw(9) << c_tab[i].data[j];
            if (j < 2)
                std::cout << "| ";
            j++;
        }
        std::cout << "|\n";
        std::cout << separator;
        i++;
    }
    std::cout << "Please, enter the index of the desired contact : " << std::endl;
    std::string index;
    while (true)
    {
        std::getline (std::cin, index);
        if (index.empty() || index.size() > 2 || isdigit(index[0]) == 0
            || index[0] == '0' || index[0] == '9' || atoi(index.c_str()) -1 >= nb_contacts)
            std::cout << "Please, enter a valid index !" << std::endl;
        else
            break ;
    }
    c_tab[atoi(index.c_str()) - 1].showdata();

}
