/*!
 * \author Kaveen Hyacinth
 * \copyright Kaveen Hyacinth Digital © 2020
 * \package model
*/

#ifndef DBGATEWAY_H
#define DBGATEWAY_H

#include <QMainWindow>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QDebug>
#include <QDir>

/*!
 * \brief The DbGateway class maintains the connetction with database
 */
class DbGateway
{
public:
    DbGateway();

public:
    void Disconnect();
    bool Connect();
    QSqlDatabase getDb();

private:
    QSqlDatabase db;
    QString path;
};

#endif // DBGATEWAY_H
