/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:31:12 by vpolojie          #+#    #+#             */
/*   Updated: 2023/09/14 17:28:05 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <array>

class PhoneBook
{
public:        
    //std::array<Contact, 8> repertoire;
    Contact c_tab[8];

    void    add()
    {
        return ;
    }
    void    search()
    {
        return ;
    }
    void    exit()
    {
        return ;
    }
};

#endif