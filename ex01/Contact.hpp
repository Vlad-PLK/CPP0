/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:34:02 by vpolojie          #+#    #+#             */
/*   Updated: 2023/09/21 17:21:44 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
public:
    //std::string first_name;
    //std::string last_name;
    //std::string nickname;
    //std::string phone_number;
    //std::string darkest_secret;
    std::string data[5];
    std::string ask_data[5];

    void    getdata();
    void    set_askdata();
    void    showdata();
};

#endif