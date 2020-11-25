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
    int accountBalance = account.getBalance();

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













