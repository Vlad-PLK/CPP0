/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:18:17 by vpolojie          #+#    #+#             */
/*   Updated: 2023/09/11 21:25:37 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
    int     i;
    int     j;
    char    c;

    i = 1;
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        while (argv[i] != 0)
        {
            j = 0;
            while (argv[i][j] != '\0')
            {
                if (97 <= argv[i][j] && argv[i][j] <= 122)
                {
                    c = argv[i][j] - 32;
                    std::cout << c ;
                }
                else
                {
                    c = argv[i][j];
                    std::cout << c ;
                }
                j++;
            }
            i++;
        }
    }
    return 0;
}

