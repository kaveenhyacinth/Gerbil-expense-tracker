#include "account.h"

Account::Account(QString name, int balance)
{
    this->accountName = name;
    this->balance = balance;
}

QString Account::getAccountName()
{
    return this->accountName;
}

int Account::getBalance()
{
    return this->balance;
}
