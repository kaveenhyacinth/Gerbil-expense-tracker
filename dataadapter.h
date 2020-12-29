/*!
 * \author Kaveen Hyacinth
 * \copyright Kaveen Hyacinth Digital © 2020
 * \package controller
*/

#ifndef DATAADAPTER_H
#define DATAADAPTER_H

#include <QTableView>
#include <QComboBox>

/*!
 * \brief The DataAdapter class does basic database operations
 */
class DataAdapter
{
public:
    DataAdapter();

public:
    /*!
     * \brief ReadAccounts loads account details to the QTableView model
     * \param tbl is the QTableView model that displays the account data
     */
    void ReadAccounts(QTableView *tbl);

    /*!
     * \brief ReadTransactions loads transaction details to the QTableView model
     * \param tbl is the QTableView model that displays the transaction data
     */
    void ReadTransactions(QTableView *tbl);

    /*!
     * \brief ReadAccounts loads the account names to the given QComboBox
     * \param cmb is the QComboBox that displays the account names
     */
    void ReadAccounts(QComboBox *cmb);

    /*!
     * \brief ReadCategories loads the category names that grouped by ref to the given QComboBox
     * \param cmb is the QComboBox model that displays the category names
     * \param ref is the type of the category, income or expense
     */
    void ReadCategories(QComboBox *cmb, QString ref);

    /*!
     * \brief LoadAccountData load account details to the QTableView and account names to the QComboBox at the same time
     * \param tbl is the QTableView that displays the account details
     * \param cmb is the QComboBox model that displays the account names
     */
    void LoadAccountData(QTableView *tbl, QComboBox *cmb);

    /*!
     * \brief LoadTransactionData loads all the transactions that are happen within the database
     * \param tbl is the table view model to display transaction data model
     * \param cmbInAcc is the QComboBox model to load accounts in add income area
     * \param cmbInCat is the QComboBox model to load categories in add income area
     * \param cmbExAcc is the QComboBox model to load accounts in add expense area
     * \param cmbExCat is the QComboBox model to load categories in add expense area
     */
    void LoadTransactionData(QTableView *tbl, QComboBox *cmbInAcc, QComboBox *cmbInCat, QComboBox *cmbExAcc, QComboBox *cmbExCat);

    /*!
     * \brief UpdateAccountIncome updates the relevant account when an income is added
     * \param accountId is the relevant account id
     * \param incomeBalance is the transaction amount
     * \return true or false based on the success of the operation
     */
    bool UpdateAccountIncome(int accountId, int incomeBalance);

    /*!
     * \brief UpdateAccountExpense updates the relevant account when an expense is added
     * \param accountId is the relevant account id
     * \param expenseBalance is the transaction amount
     * \return true or false based on the success of the operation
     */
    bool UpdateAccountExpense(int accountId, int expenseBalance);

    /*!
     * \brief FetchTotalByType sum up total transaction amount based on the given type
     * \param recordType is the type, income or expense
     * \return total balance as an int type
     */
    int FetchTotalByType(QString recordType);

    /*!
     * \brief FetchTotalOfTypeByDate sum up total transaction amount based on the given type and date range
     * \param recordType is the type, income or expense
     * \param startDate is the start point of the date range
     * \param endDate is the end point of the date range
     * \return total balance as an int type
     */
    int FetchTotalOfTypeByDate(QString recordType, QDate startDate, QDate endDate);

    /*!
     * \brief FetchTotalStringByType sum up total transaction amount based on the given type
     * \param recordType is the type, income or expense
     * \return total balance as a string type
     */
    QString FetchTotalStringByType(QString recordType);

    /*!
     * \brief FetchTotalStringOfTypeByDate sum up total transaction amount based on the given type and date range
     * \param recordType is the type, income or expense
     * \param startDate is the start point of the date range
     * \param endDate is the end point of the date range
     * \return total balance as a string type
     */
    QString FetchTotalStringOfTypeByDate(QString recordType, QDate startDate, QDate endDate);

    /*!
     * \brief FetchTotalBalance sum up total acount balance
     * \return total balance as a string type
     */
    QString FetchTotalBalance();

};

#endif // DATAADAPTER_H
