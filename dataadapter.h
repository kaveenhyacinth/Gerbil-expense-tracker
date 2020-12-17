#ifndef DATAADAPTER_H
#define DATAADAPTER_H

#include <QTableView>
#include <QComboBox>

class DataAdapter
{
public:
    DataAdapter();

public:
    void ReadAccounts(QComboBox *);
    void ReadAccounts(QTableView *);
    void ReadCategories(QComboBox*);
    void ReadTransactions(QTableView*);
    void LoadAccountData(QTableView *, QComboBox *);
    void LoadTransactionData(QTableView*, QComboBox*, QComboBox*, QComboBox*, QComboBox*);
    bool UpdateAccountIncome(int, int);
    bool UpdateAccountExpense(int, int);
    QString FetchTotalByType(QString recordType);
    QString FetchTotalBalance();
};

#endif // DATAADAPTER_H
