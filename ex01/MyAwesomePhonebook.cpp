/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyAwesomePhonebook.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:14:06 by vpolojie          #+#    #+#             */
/*   Updated: 2023/09/21 17:39:03 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>
#include "PhoneBook.hpp"
#include "Contact.hpp"

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
    std::cout << "You've decided to store a new contact, please fill the following questions : " << std::endl;
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
            //c_tab[7].data[i].erase(0, c_tab[7].data[i].size());
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
    int     k;

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
            || index[0] == '0' || index[0] == '9')
            std::cout << "Please, enter a valid index !" << std::endl;
        else
            break ;
    }
    k = atoi(index.c_str());
    c_tab[k - 1].showdata();

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