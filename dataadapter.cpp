#include "dataadapter.h"
#include "dbgateway.h"

DataAdapter::DataAdapter()
{

}

void DataAdapter::ReadAccounts(QTableView *tbl)
{
    DbGateway db;
    QSqlQuery *qry;
    QSqlQueryModel *model;

    if(!db.Connect()) {
        qDebug() << "Failed to open the database connection";
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
    qDebug() << (model->rowCount());
}

void DataAdapter::ReadTransactions(QTableView *tbl)
{
    DbGateway db;
    QSqlQuery *qry;
    QSqlQueryModel *model;

    if(!db.Connect()) {
        qDebug() << "Failed to open the database connection";
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
    qDebug() << (model->rowCount());
}

void DataAdapter::ReadAccounts(QComboBox *cmb)
{
    DbGateway db;
    QSqlQuery *qry;
    QSqlQueryModel *model;

    if(!db.Connect()) {
        qDebug() << "Failed to open the database connection";
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
    qDebug() << (model->rowCount());
}

void DataAdapter::ReadCategories(QComboBox *cmb)
{
    DbGateway db;
    QSqlQuery *qry;
    QSqlQueryModel *model;

    if(!db.Connect()) {
        qDebug() << "Failed to open the database connection";
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
    qDebug() << (model->rowCount());
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
