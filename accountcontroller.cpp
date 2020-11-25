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

    if(qry.exec())
    {
        qDebug() << "Account Saved..";
        db.Disconnect();
    }
    else
    {
        qDebug() << "Account Creation Went Wrong...";
    }
}
