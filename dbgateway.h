#ifndef DBGATEWAY_H
#define DBGATEWAY_H

#include <QMainWindow>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QDebug>

class DbGateway
{
public:
    DbGateway();

public:
    bool Connect();
    void Disconnect();
    int couter();
    QSqlDatabase getDb();

private:
    QSqlDatabase db;
    QString path;
};

#endif // DBGATEWAY_H