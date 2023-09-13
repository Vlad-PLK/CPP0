/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:18:17 by vpolojie          #+#    #+#             */
/*   Updated: 2023/09/13 09:44:26 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Megaphone
{
public:
    char    *str;

    void    ft_toupper(void)
    {
        int i;

        i = 0;
        while (str[i] != '\0')
        {
            str[i] = toupper(str[i]);
            std::cout << str[i];
            i++;
        }
    }
};

int main(int argc, char **argv)
{
    Megaphone m_phone;

    int i;

    i = 1;
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        while (argv[i])
        {
            m_phone.str = argv[i];
            m_phone.ft_toupper();
            i++;
        }
        std::cout << "\n";
    }
    return 0;
}

