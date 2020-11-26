#include "accountcontroller.h"
#include "dbgateway.h"

AccountController::AccountController()
{

}

void AccountController::CreateAccount(Account account)
{
    DbGateway db;
    QSqlQuery qry;

    QString accountName = account.getAccountName();
    QString accountBalance = account.getBalance();

    if(!db.Connect()) {
        qDebug() << "Failed to open the database connection";
        return;
    }

    qry.prepare("INSERT INTO account (account_name, balance) VALUES (?, ?)");
    qry.bindValue(0, accountName);
    qry.bindValue(1, accountBalance);

    if(!qry.exec())
    {
        qDebug() << "Account Creation Went Wrong...";
        return;
    }

    qDebug() << "Account Saved..";
    db.Disconnect();
}

void AccountController::ReadAccounts(QTableView *tbl)
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

void AccountController::ReadAccounts(QComboBox *cmb)
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

void AccountController::LoadData(QTableView *tbl, QComboBox *cmb)
{
    this->ReadAccounts(tbl);
    this->ReadAccounts(cmb);
}

void AccountController::DeleteAccount(QString name)
{
    DbGateway db;
    QSqlQuery qry;

    if(!db.Connect()) {
        qDebug() << "Failed to open the database connection";
        return;
    }

    qry.prepare("DELETE FROM account WHERE account_name = ?");
    qry.bindValue(0, name);

    if(!qry.exec())
    {
        qDebug() << "Something went wrong while deleting the account";
        return;
    }


    db.Disconnect();
    qDebug() << "Account " << name << " has been deleted";
}











