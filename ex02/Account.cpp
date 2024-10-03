/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:02:14 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/10/03 16:47:13 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	this->_accountIndex = Account::_nbAccounts;
	Account::_nbAccounts++;
	this->_amount = initial_deposit;
	Account::_totalAmount += initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount \
	<< ";created" << std::endl;
}

Account::~Account()
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount \
	<< ";closed" << std::endl;
}

void Account::_displayTimestamp()
{
	std::time_t	now;
	std::tm *local;
	char buffer[80];
	
	now = time(NULL);
	local = localtime(&now);
	std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S] ", local);
	std::cout << buffer;
}

void Account::displayStatus() const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount \
	<< ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals \
	<< std::endl;
}

int Account::getNbAccounts()
{
	return (Account::_nbAccounts);
}

int Account::getTotalAmount()
{
	return (Account::_totalAmount);
}

int Account::getNbDeposits()
{
	return (Account::_totalNbDeposits);
}

int Account::getNbWithdrawals()
{
	return (Account::_totalNbWithdrawals);
}

void Account::displayAccountsInfos()
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ";total:" << Account::getTotalAmount() \
	<< ";deposits:" << Account::getNbDeposits() << ";withdrawals:" << Account::getNbWithdrawals() \
	<< std::endl;
}

void Account::makeDeposit(int deposit)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount \
	<< ";deposit:" << deposit;
	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_totalAmount += deposit;
	std::cout << ";amount:" << this->_amount << ";nb_deposits:" << this->_nbDeposits \
	<< std::endl;
	Account::_totalNbDeposits++;
}

int Account::checkAmount(void) const
{
	return (this->_amount);
}

bool Account::makeWithdrawal(int withdrawal)
{
	int amount;

	Account::_displayTimestamp();
	amount = checkAmount();
	if (amount >= withdrawal)
	{
		std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount \
		<< ";withdrawal:" << withdrawal;
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		std::cout << ";amount:" << this->_amount << ";nb_withdrawals:" \
		<< this->_nbWithdrawals << std::endl;
		Account::_totalAmount -= withdrawal;
		Account::_totalNbWithdrawals++;
		return (true);
	}
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount \
	<< ";withdrawal:refused" << std::endl;
	return (false);
}


