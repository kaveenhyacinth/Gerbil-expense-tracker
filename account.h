#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QString>

class Account
{
public:
    Account(QString, int);
    QString getAccountName();
    int getBalance();

private:
    QString accountName;
    int balance;
};

#endif // ACCOUNT_H
