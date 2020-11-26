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
};

#endif // ACCOUNTCONTROLLER_H
