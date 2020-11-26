#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QString>

class Account
{
public:
    Account(QString, QString);
    QString getAccountName();
    QString getBalance();

private:
    QString accountName;
    QString balance;
};

#endif // ACCOUNT_H
