#ifndef UTIL_H
#define UTIL_H

#include <QString>
#include <QStringList>

class Util
{
public:
    Util();

public:
    QString FormatBalance(QString, QString);
    QString FormatBalance(int);
    QStringList SplitBalance(QString);
    int FormatMoney(QString);

};

#endif // UTIL_H
