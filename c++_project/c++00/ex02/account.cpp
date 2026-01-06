/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 13:09:05 by omghazi           #+#    #+#             */
/*   Updated: 2024/10/18 15:14:01 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iomanip>
#include <iostream>

// ************************************************************************** //
//                               init account data functions                  //
// ************************************************************************** //

int	Account::_nbAccounts = 0;
int     Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) : _accountIndex(Account::_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";created" << std::endl;
	Account::_totalAmount += _amount;
	Account::_nbAccounts++;
}

Account::~Account( void )
{
        Account::_displayTimestamp();
        std::cout << "index:";
        std::cout << Account::_accountIndex;
        std::cout << "amount:" << Account::_amount << ",closed" << std::endl;
}

void     Account::displayAccountsInfos( void )
{
        Account::_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts;
	std::cout << ";total:" << Account::_totalAmount;
	std::cout << ";deposits:" << Account::_totalNbDeposits;
	std::cout << ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

// ************************************************************************** //
//                               Gere account functions                       //
// ************************************************************************** //

void Account::makeDeposit( int deposit)
{
        Account::_displayTimestamp();
	std::cout << "index:" << Account::_accountIndex;
	std::cout << ";p_amount:" << Account::_amount;
	this->_nbDeposits++;
    	this->_amount += deposit;
   	Account::_totalNbDeposits++;
   	Account::_totalAmount += deposit;
	std::cout << ";deposit:" << deposit;
	std::cout << ";amount:" << Account::_amount;
	std::cout <<  ";nb_deposits:" << Account::_nbDeposits << std::endl; 
}

bool Account::makeWithdrawal( int withdrawal )
{
        Account::_displayTimestamp();
	std::cout << "index:" << Account::_accountIndex;
	std::cout << ";p_amount:" << Account::_amount;
	if (withdrawal > Account::_amount)
        {
		std::cout << ";withdrawal:refused" << std::endl;
                return 0;
	}
	this->_nbWithdrawals++;
    	this->_amount -= withdrawal;
    	Account::_totalNbWithdrawals++;
    	Account::_totalAmount -= withdrawal;
	std::cout << ";withdrawal:" << withdrawal;
	std::cout << ";amount:" << Account::_amount;
	std::cout <<  ";nb_withdrawals:" << Account::_nbWithdrawals << std::endl;
	return 1;
}

void    Account::displayStatus( void ) const
{
        Account::_displayTimestamp();
	std::cout << "index:" << Account::_accountIndex;
	std::cout << ";amount:" << Account::_amount;
	std::cout << ";deposits:" << Account::_nbDeposits;
	std::cout << ";withdrawals:" << Account::_nbWithdrawals << std::endl;
}

// ************************************************************************** //
//                              timer function                                //
// ************************************************************************** //

void    Account::_displayTimestamp( void )
{
        struct tm *time;
        time_t  timestamp;

        timestamp = std::time(NULL);
        time = localtime(&timestamp);
         std::cout << "[" << (time->tm_year + 1900)<< (time->tm_mon + 1)
              << time->tm_mday << "_" << time->tm_hour << time->tm_min << time->tm_sec << "] ";
}
