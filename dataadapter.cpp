#include "dataadapter.h"
#include "dbgateway.h"
#include "util.h"

DataAdapter::DataAdapter()
{

}

void DataAdapter::ReadAccounts(QTableView *tbl)
{
    DbGateway db;
    QSqlQuery *qry;
    QSqlQueryModel *model;

    if(!db.Connect()) {
        qDebug() << "Failed to open the database connection @ ReadAccounts";
        return;
    }

    model = new QSqlQueryModel();
    qry = new QSqlQuery(db.getDb());

    qry->prepare("SELECT account_name as 'Account', balance as 'Balance' FROM account");

    if(!qry->exec())
    {
        qDebug() << "Something went wrong while fetching account details";
        return;
    }

    model->setQuery(*qry);
    tbl->setModel(model);
    db.Disconnect();
}

void DataAdapter::ReadTransactions(QTableView *tbl)
{
    DbGateway db;
    QSqlQuery *qry;
    QSqlQueryModel *model;

    if(!db.Connect()) {
        qDebug() << "Failed to open the database connection @ ReadTransactions";
        return;
    }

    model = new QSqlQueryModel();
    qry = new QSqlQuery(db.getDb());

    qry->prepare("SELECT a.account_name as 'Account', "
                 "t.amount as 'Amount', "
                 "t.record_type as 'Type', "
                 "t.date as 'Date', "
                 "c.type as 'Category' "
                 "FROM ((record as t "
                 "INNER JOIN account as a ON t.account_id = a._id) "
                 "INNER JOIN category as c ON t.category = c._id)");

    if(!qry->exec())
    {
        qDebug() << "Something went wrong while fetching transaction details";
        return;
    }

    model->setQuery(*qry);
    tbl->setModel(model);
    db.Disconnect();
}

void DataAdapter::ReadAccounts(QComboBox *cmb)
{
    DbGateway db;
    QSqlQuery *qry;
    QSqlQueryModel *model;

    if(!db.Connect()) {
        qDebug() << "Failed to open the database connection @ ReadAccounts";
        return;
    }

    model = new QSqlQueryModel();
    qry = new QSqlQuery(db.getDb());

    qry->prepare("SELECT account_name FROM account ORDER BY _id");

    if(!qry->exec())
    {
        qDebug() << "Something went wrong while fetching account details";
        return;
    }

    model->setQuery(*qry);
    cmb->setModel(model);
    db.Disconnect();
}

void DataAdapter::ReadCategories(QComboBox *cmb)
{
    DbGateway db;
    QSqlQuery *qry;
    QSqlQueryModel *model;

    if(!db.Connect()) {
        qDebug() << "Failed to open the database connection @ ReadCategories";
        return;
    }

    model = new QSqlQueryModel();
    qry = new QSqlQuery(db.getDb());

    qry->prepare("SELECT type FROM category ORDER BY _id");

    if(!qry->exec())
    {
        qDebug() << "Something went wrong while fetching category details";
        return;
    }

    model->setQuery(*qry);
    cmb->setModel(model);
    db.Disconnect();
}

int DataAdapter::ParseAccountBalance(int accountId)
{
    Util util;
    DbGateway tempdb;
    QSqlQuery tempqry;
    QString balanceStr;
    int balance;

    if(!tempdb.Connect()) {
        qDebug() << "Failed to open the database connection @ ParseAccountBalance";
        return -1;
    }

    tempqry.prepare("SELECT balance FROM account WHERE _id = ?");
    tempqry.bindValue(0, accountId);

    if(!tempqry.exec())
    {
        qDebug() << "Something went wrong while parsing account balance";
        return -1;
    }

    while (tempqry.next())
    {
        balanceStr = tempqry.value(0).toString();
    }

    balance = util.FormatMoney(balanceStr);
    tempdb.Disconnect();
    qDebug() << "Parsed account balance" << balance;
    return balance;

}

void DataAdapter::UpdateAccountIncome(int accountId, int incomeBalance)
{
    Util util;
    DbGateway db;
    QSqlQuery qry;
    QSqlQuery tempqry;
    QString tempBalanceStr;
    QString balanceStr;
    int tempBalance;
    int balance;

    if(!db.Connect()) {
        qDebug() << "Failed to open the database connection @ UpdateAccountIncome";
        return;
    }

    tempqry.prepare("SELECT balance FROM account WHERE _id = ?");
    tempqry.bindValue(0, accountId);

    if(!tempqry.exec())
    {
        qDebug() << "Something went wrong while parsing account balance";
        return;
    }

    while (tempqry.next())
    {
        tempBalanceStr = tempqry.value(0).toString();
    }

    tempBalance = util.FormatMoney(tempBalanceStr);
    balance = tempBalance + incomeBalance;
    balanceStr = util.FormatBalance(balance);

    qDebug() << "New account balance" << balanceStr;

    qry.prepare("UPDATE account SET balance = ? WHERE _id = ?");
    qry.bindValue(0, balanceStr);
    qry.bindValue(1, accountId);

    if(!qry.exec())
    {
        qDebug() << "Something went wrong while updating account balance";
        return;
    }

    db.Disconnect();
    qDebug() << "Account balance updated";
}

void DataAdapter::LoadAccountData(QTableView *tbl, QComboBox *cmb)
{
    this->ReadAccounts(tbl);
    this->ReadAccounts(cmb);
}

void DataAdapter::LoadTransactionData
(QTableView *tbl, QComboBox *cmbInAcc, QComboBox *cmbInCat, QComboBox *cmbExAcc, QComboBox *cmbExCat)
{
    this->ReadTransactions(tbl);
    this->ReadAccounts(cmbInAcc);
    this->ReadAccounts(cmbExAcc);
    this->ReadCategories(cmbInCat);
    this->ReadCategories(cmbExCat);
}
