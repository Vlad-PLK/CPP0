/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:18:03 by vpolojie          #+#    #+#             */
/*   Updated: 2023/09/25 18:25:44 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <algorithm>
#include <functional>
#include "Account.hpp"
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void)
{
    return (_nbAccounts);
}

int Account::getTotalAmount(void)
{
    return (_totalAmount);
}

int Account::getNbDeposits(void)
{
    return (_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
    return (_totalNbWithdrawals);
}

Account::Account(int initial_deposit)
{
    _accountIndex = getNbAccounts();
    _amount = initial_deposit + _amount;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
    _totalAmount += _amount;
    _nbAccounts++;
}

Account::~Account()
{
    std::cout << "Destructor called" << std::endl;
}

void    Account::makeDeposit(int deposit)
{
    std::cout << "index:" << _accountIndex;
    std::cout << ";p_amount:" << _amount;
    std::cout << ";deposit:" << deposit;
    _amount += deposit;
    std::cout << ";amount:" << _amount;
    _nbDeposits += 1;
    std::cout << ";nb_deposits:" << _nbDeposits << std::endl;
    _totalNbDeposits += _nbDeposits;
    _totalAmount += deposit;
}

bool    Account::makeWithdrawal(int withdrawal)
{
    std::cout << "index:" << _accountIndex;
    std::cout << ";p_amount:" << _amount;
    std::cout << ";withdrawal:";
    if ((_amount - withdrawal) < 0)
    {
        std::cout << "refused" << std::endl;
        return (false);
    }
    else
    {
        _amount = _amount - withdrawal;
        std::cout << withdrawal;
        std::cout << ";amount:" << _amount;
        _nbWithdrawals++;
        _totalNbWithdrawals = _nbDeposits;
        _totalAmount -= withdrawal;
        std::cout << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
        return (true);
    }
}

void Account::displayAccountsInfos()
{
    std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void Account::displayStatus() const
{
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

