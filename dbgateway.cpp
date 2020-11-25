#include "dbgateway.h"


DbGateway::DbGateway()
{
    path = "gerbil.db";
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(path);
}

QSqlDatabase DbGateway::getDb()
{
    return db;
}

bool DbGateway::Connect()
{
    if(db.open())
    {
        qDebug() << "Database connected...";
        return true;
    }
    else
    {
        qDebug() << "Failed to open the database connection";
        return false;
    }
}

void DbGateway::Disconnect()
{
    db.close();
    db.removeDatabase(QSqlDatabase::defaultConnection);
}

