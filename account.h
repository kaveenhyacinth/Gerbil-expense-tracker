/*!
 * \author Kaveen Hyacinth
 * \copyright Kaveen Hyacinth Digital © 2020
*/

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QString>

/*!
 * \brief The Account class holds details of a account, name and balance
 */
class Account
{
public:
    Account(QString name, QString balance);
    QString getAccountName();
    QString getBalance();

private:
    QString accountName;
    QString balance;
};

#endif // ACCOUNT_H
