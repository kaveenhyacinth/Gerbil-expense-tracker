#include "transaction.h"

Transaction::Transaction
(int id, int category, QString type, QString amount, QDate date)
{
    this->accountId = id;
    this->category = category;
    this->type = type;
    this->amount = amount;
    this->date = date;
}

int Transaction::getAccountId()
{
    return accountId;
}

int Transaction::getCategory()
{
    return category;
}

QString Transaction::getType()
{
    return type;
}

QString Transaction::getAmount()
{
    return amount;
}

QDate Transaction::getDate()
{
    return date;
}
