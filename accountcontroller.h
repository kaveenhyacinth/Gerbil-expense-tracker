#ifndef ACCOUNTCONTROLLER_H
#define ACCOUNTCONTROLLER_H

#include "account.h"
#include <QTableView>
#include <QComboBox>

class AccountController
{
public:
    AccountController();

public:
    void CreateAccount(Account);
    void DeleteAccount(QString);
    void ReadAccounts(QTableView *);
    void ReadAccounts(QComboBox *);
    void LoadData(QTableView *, QComboBox *);
};

#endif // ACCOUNTCONTROLLER_H
