#include "transactioncontroller.h"
#include "dbgateway.h"

TransactionController::TransactionController()
{

}

int TransactionController::ParseAccountId(QString account)
{
    DbGateway db;
    QSqlQuery qry;
    int accountId;

    if(!db.Connect()) {
        qDebug() << "Failed to open the database connection @ ParseAccountId";
        return -1;
    }

    qry.prepare("SELECT _id FROM account WHERE account_name = ?");
    qry.bindValue(0, account);

    if(!qry.exec())
    {
        qDebug() << "Account id parsing Went Wrong...";
        return -1;
    }

    while (qry.next())
    {
        accountId = qry.value(0).toInt();
    }

    db.Disconnect();
    return accountId;

}

int TransactionController::ParseCategoryId(QString category)
{
    DbGateway db;
    QSqlQuery qry;
    int categoryId;

    if(!db.Connect()) {
        qDebug() << "Failed to open the database connection @ ParseCategoryId";
        return -1;
    }

    qry.prepare("SELECT _id FROM category WHERE type = ?");
    qry.bindValue(0, category);

    if(!qry.exec())
    {
        qDebug() << "Category id parsing Went Wrong...";
        return -1;
    }

    while (qry.next())
    {
        categoryId = qry.value(0).toInt();
    }

    db.Disconnect();
    return categoryId;
}

void TransactionController::CreateTransaction(Transaction transaction)
{
    DbGateway db;
    QSqlQuery qry;

    int accountId = transaction.getAccountId();
    int category = transaction.getCategory();
    QString type = transaction.getType();
    QString amount = transaction.getAmount();
    QDate date = transaction.getDate();

    if(!db.Connect()) {
        qDebug() << "Failed to open the database connection @ CreateTransaction";
        return;
    }

    qry.prepare("INSERT INTO record (account_id, record_type, category, amount, date) VALUES (?, ?, ?, ?, ?)");
    qry.bindValue(0, accountId);
    qry.bindValue(1, type);
    qry.bindValue(2, category);
    qry.bindValue(3, amount);
    qry.bindValue(4, date);

    if(!qry.exec())
    {
        qDebug() << "Transaction Creation Went Wrong...";
        return;
    }

    qDebug() << "Transaction Saved..";
    db.Disconnect();

}

void TransactionController::DeleteTransactionByAccount(int accountId)
{
    DbGateway db;
    QSqlQuery qry;

    if(!db.Connect()) {
        qDebug() << "Failed to open the database connection @ DeleteTransactionByAccount";
        return;
    }

    qry.prepare("DELETE FROM record WHERE account_id = ?");
    qry.bindValue(0, accountId);

    if(!qry.exec())
    {
        qDebug() << "Transaction deletion Went Wrong...";
        return;
    }

    qDebug() << "Transactions deleted";
    db.Disconnect();
}
