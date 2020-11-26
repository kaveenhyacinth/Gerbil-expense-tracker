#include "account.h"

Account::Account(QString name, QString balance)
{
    this->accountName = name;
    this->balance = balance;
}

QString Account::getAccountName()
{
    return this->accountName;
}

QString Account::getBalance()
{
    return this->balance;
}
