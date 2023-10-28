/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:31:12 by vpolojie          #+#    #+#             */
/*   Updated: 2023/10/28 15:51:10 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
private:
    Contact c_tab[8];
    int     last_contact;
public:
    int     nb_contacts;

    void    setLastContact(int new_value);
    int     getLastContact(void);
    void    Add();
    void    Search();
    void    Contact_tab();
    void    Contact_info();
};

#endif