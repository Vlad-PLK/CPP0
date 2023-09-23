/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:18:03 by vpolojie          #+#    #+#             */
/*   Updated: 2023/09/23 11:04:00 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <algorithm>
#include <functional>
#include "Account.hpp"
#include <iostream>

Account::Account(int initial_deposit)
{
    static int i;

    i = 0;
    initial_deposit = initial_deposit + _amount;
    i = i + _accountIndex + 1;
    std::cout << "Index:" << i << ";amount:" << initial_deposit << ";created" << std::endl;
}

Account::~Account()
{
    std::cout << "Destructor called" << std::endl;
}

void    Account::makeDeposit(int deposit)
{
    deposit += 5;
    std::cout << deposit + 1 << std::endl;
}

bool    Account::makeWithdrawal(int withdrawal)
{
    if (withdrawal > 5)
        return (true);
    else
        return (false);
}

void Account::displayAccountsInfos()
{
    std::cout << "accounts infos" << std::endl;
}

void Account::displayStatus() const
{
    std::cout << "status" << std::endl;
}

