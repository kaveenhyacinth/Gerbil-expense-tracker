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
    void ReadTransactions(QTableView*);
    void ReadAccounts(QComboBox*);
    void ReadCategories(QComboBox*);
    void LoadData(QTableView*, QComboBox*, QComboBox*);
    int ParseCategoryId(QString);
    int ParseAccountId(QString);
};

#endif // TRANSACTIONCONTROLLER_H
