/*!
 * \author Kaveen Hyacinth
 * \copyright Kaveen Hyacinth Digital © 2020
 * \package controller
*/

#ifndef ACCOUNTCONTROLLER_H
#define ACCOUNTCONTROLLER_H

#include "account.h"
#include <QTableView>
#include <QComboBox>

/*!
 * \brief The AccountController class does two main account operations; create account and delete account
 */
class AccountController
{
public:
    AccountController();

public:
    /*!
     * \brief CreateAccount create an account in the database
     * \param account is the Account model
     */
    void CreateAccount(Account account);

    /*!
     * \brief DeleteAccount deletes an account based on its name
     * \param name is the account name which is to be deleted
     */
    void DeleteAccount(QString name);
};

#endif // ACCOUNTCONTROLLER_H
