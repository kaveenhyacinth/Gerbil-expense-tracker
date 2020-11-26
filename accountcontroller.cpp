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
        qDebug() << "Failed to open the database connection @ CreateAccount";
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

void AccountController::DeleteAccount(QString name)
{
    DbGateway db;
    QSqlQuery qry;

    if(!db.Connect()) {
        qDebug() << "Failed to open the database connection @ DeleteAccount";
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











