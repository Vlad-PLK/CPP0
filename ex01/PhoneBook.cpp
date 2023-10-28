/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 09:31:53 by vpolojie          #+#    #+#             */
/*   Updated: 2023/10/28 15:59:54 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <string>

void    PhoneBook::setLastContact(int new_value)
{
    last_contact = new_value;
}

int PhoneBook::getLastContact(void)
{
    return (last_contact);
}

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
        std::cout << "Your oldest contact will be replaced with the new one !" << std::endl;
        i = 0;
        while (i != 4)
        {
            c_tab[getLastContact()].data[i].clear();
            i++;
        }
        c_tab[getLastContact()].getdata();
        if (getLastContact() == 7)
            setLastContact(0);
        else
            setLastContact(getLastContact() + 1);
    }
    return ;
}

void    PhoneBook::Contact_tab()
{
    int i;
    int j;

    i = 0;
    std::string separator = "+----------+----------+----------+----------+\n";
    while (i != nb_contacts)
    {
        std::cout << "| ";
        std::cout << std::setw(9) << i + 1 << "| ";
        j = 0;
        while (j != 3)
        {
            if (c_tab[i].data[j].size() > 8)
            {
                std::string tronc;
                tronc = c_tab[i].data[j].substr(0, 8);
                tronc.append(".");
                std::cout << std::setw(9) << tronc;
            }
            else
                std::cout << std::setw(9) << c_tab[i].data[j];
            if (j < 2)
                std::cout << "| ";
            j++;
        }
        std::cout << "|\n";
        std::cout << separator;
        i++;
    }
}

void    PhoneBook::Contact_info()
{
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

void    PhoneBook::Search()
{

    std::string separator = "+----------+----------+----------+----------+\n";
    std::string h1 = "index";
    std::string h2 = "first name";
    std::string h3 = "last name";
    std::string h4 = "nickname";
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
    Contact_tab();
    Contact_info();
}
