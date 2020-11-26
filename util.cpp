#include "util.h"

Util::Util()
{

}

QString Util::FormatBalance(QString amount, QString cents)
{
    cents.truncate(2);
    QString balance = amount + "." + cents;
    return balance;
}

QString Util::FormatBalance(int balance)
{
    QString amount = QString::number(balance);
    QString cents = amount.right(2);
    amount.chop(2);
    QString balanceString = amount + "." + cents;
    return balanceString;
}

QStringList Util::SplitBalance(QString balance)
{
    QStringList list = balance.split(".");
    return list;
}

int Util::FormatMoney(QStringList list)
{
    int amount = list.at(0).toInt();
    int cents = list.at(1).toInt();
    int money = (amount * 100) + cents;
    return money;
}

