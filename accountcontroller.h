#ifndef ACCOUNTCONTROLLER_H
#define ACCOUNTCONTROLLER_H

#include "account.h"
#include <QTableView>

class AccountController
{
public:
    AccountController();

public:
    void CreateAccount(Account);
    void DeleteAccount(int);
    void ReadAccounts(QTableView *);
};

#endif // ACCOUNTCONTROLLER_H
