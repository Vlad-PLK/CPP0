/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:18:03 by vpolojie          #+#    #+#             */
/*   Updated: 2023/09/28 16:36:23 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <algorithm>
#include <functional>
#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void    Account::_displayTimestamp(void)
{
    time_t  now;

    now = time(0);
    tm *ltm = localtime(&now);
    std::cout << "[";
    std::cout << 1900 + ltm->tm_year;
    std::cout << 1 + ltm->tm_mon;
    std::cout << ltm->tm_mday;
    std::cout << "_";
    std::cout << ltm->tm_hour; 
    std::cout << ltm->tm_min;
    std::cout << ltm->tm_sec;
    std::cout << "] ";
}

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
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
    _totalAmount += _amount;
    _nbAccounts++;
}

Account::~Account()
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

int Account::checkAmount(void) const
{
    if (_amount <= 0)
        return (1);
    else
        return (0);
}

void    Account::makeDeposit(int deposit)
{
    _displayTimestamp();
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
    _displayTimestamp();
    std::cout << "index:" << _accountIndex;
    std::cout << ";p_amount:" << _amount;
    std::cout << ";withdrawal:";
    if ((_amount - withdrawal) < 0 || checkAmount() == 1)
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
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void Account::displayStatus() const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

