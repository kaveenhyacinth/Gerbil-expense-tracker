#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <QString>
#include <QDate>

class Transaction
{
public:
    Transaction(int, int, QString, QString, QDate);

public:
    int getAccountId();
    int getCategory();
    QString getType();
    QString getAmount();
    QDate getDate();

private:
    int accountId;
    int category;
    QString type;
    QString amount;
    QDate date;

};

#endif // TRANSACTION_H
