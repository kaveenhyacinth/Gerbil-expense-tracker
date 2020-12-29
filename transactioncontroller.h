/*!
 * \author Kaveen Hyacinth
 * \copyright Kaveen Hyacinth Digital © 2020
 * \package controller
*/

#ifndef TRANSACTIONCONTROLLER_H
#define TRANSACTIONCONTROLLER_H

#include "transaction.h"
#include <QTableView>
#include <QComboBox>

/*!
 * \brief The TransactionController class handles the basic transaction operations such as create, delete and parse
 */
class TransactionController
{
public:
    TransactionController();

public:
    /*!
     * \brief CreateTransaction creates a transaction based on Transaction model
     * \param transaction is the Transaction model
     */
    void CreateTransaction(Transaction transaction);

    /*!
     * \brief DeleteTransactionByAccount deletes a transaction based on its account id field
     * \param accountId is the point of deletion
     */
    void DeleteTransactionByAccount(int accountId);

    /*!
     * \brief ParseAccountId returns the account id when the account name is given
     * \param account is the name of the account
     * \return account id
     */
    int ParseAccountId(QString account);

    /*!
     * \brief ParseCategoryId returns the category id when the category name is given
     * \param category is the name of the category
     * \return category id
     */
    int ParseCategoryId(QString category);
};

#endif // TRANSACTIONCONTROLLER_H
