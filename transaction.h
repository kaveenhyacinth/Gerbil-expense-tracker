/*!
 * \author Kaveen Hyacinth
 * \copyright Kaveen Hyacinth Digital © 2020
 * \package model
*/

#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <QString>
#include <QDate>

/*!
 * \brief The Transaction class holds the basic transaction data
 */
class Transaction
{
public:
    Transaction(int id, int category, QString type, QString amount, QDate date);

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
