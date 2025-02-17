#include "Account.hpp"
#include <ctime>
#include <iomanip>
#include <iostream>

int Account::_nbAccounts         = 0;
int Account::_totalAmount        = 0;
int Account::_totalNbDeposits    = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts()
{
    return _nbAccounts;
}

int Account::getTotalAmount()
{
    return _totalAmount;
}

int Account::getNbDeposits()
{
    return _totalNbDeposits;
}

int Account::getNbWithdrawals()
{
    return _totalNbWithdrawals;
}

void Account::displayAccountsInfos()
{
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts;
    std::cout << ";total:" << _totalAmount;
    std::cout << ";deposits:" << _totalNbDeposits;
    std::cout << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

Account::Account(int initial_deposit)
    : _accountIndex(_nbAccounts++), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex;
    std::cout << ";amount:" << _amount;
    std::cout << ";created" << std::endl;
    _totalAmount += _amount;
}

Account::~Account()
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex;
    std::cout << ";amount:" << _amount;
    std::cout << ";closed" << std::endl;
}

void Account::makeDeposit(int deposit)
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex;
    std::cout << ";p_amount:" << this->_amount;
    std::cout << ";deposit:" << deposit;
    _totalNbDeposits++;
    this->_nbDeposits++;
    _totalAmount += deposit;
    this->_amount += deposit;
    std::cout << ";amount:" << this->_amount;
    std::cout << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex;
    std::cout << ";p_amount:" << this->_amount;
    this->_amount -= withdrawal;
    if (!checkAmount())
    {
        std::cout << ";withdrawal:"
                  << "refused" << std::endl;
        this->_amount += withdrawal;
        return false;
    }
    std::cout << ";withdrawal:" << withdrawal;
    _totalNbWithdrawals++;
    this->_nbWithdrawals++;
    _totalAmount -= withdrawal;
    std::cout << ";amount:" << this->_amount;
    std::cout << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
    return true;
}

int Account::checkAmount() const
{
    if (this->_amount < 0)
        return 0;
    return 1;
}

void Account::displayStatus() const
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex;
    std::cout << ";amount:" << this->_amount;
    std::cout << ";deposits:" << this->_nbDeposits;
    std::cout << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

// epoch = reference point in time (01/01/1970) from where we start counting it in seconds
void Account::_displayTimestamp()
{
    // get cur time -> seconds since epoch
    std::time_t time = std::time(0);
    // convert to time_t (breaks down the time in year, month...) to be able to format
    std::tm* converted = std::localtime(&time);
    // display while formatting
    std::cout << "[" << 1900 + converted->tm_year // 1900 + 123 (nb of years since 1900) = 2023
              << std::setw(2) << std::setfill('0')
              << 1 + converted->tm_mon // month since January (0-11)
              << std::setw(2) << std::setfill('0') << converted->tm_mday << "_" << std::setw(2)
              << std::setfill('0') << converted->tm_hour << std::setw(2) << std::setfill('0')
              << converted->tm_min << std::setw(2) << std::setfill('0') << converted->tm_sec
              << "] ";
}
