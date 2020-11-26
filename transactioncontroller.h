#ifndef TRANSACTIONCONTROLLER_H
#define TRANSACTIONCONTROLLER_H

#include "transaction.h"
#include <QTableView>
#include <QComboBox>

class TransactionController
{
public:
    TransactionController();

public:
    void CreateTransaction(Transaction);
    int ParseCategoryId(QString);
    int ParseAccountId(QString);
};

#endif // TRANSACTIONCONTROLLER_H
