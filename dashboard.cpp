#include "dashboard.h"
#include "ui_dashboard.h"
#include <QtDebug>

Dashboard::Dashboard(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Dashboard)
{
    ui->setupUi(this);

    AccountController accountController;
    accountController.LoadData(ui->tblAccounts, ui->cmbDeleteAccount);
}

Dashboard::~Dashboard()
{
    delete ui;
}

void Dashboard::on_btnAccountAdd_clicked()
{
    QString accountName = ui->txtAccountName->text();
    int balance = ui->txtBalance->text().toInt();

    Account account(accountName, balance);
    AccountController accountController;

    accountController.CreateAccount(account);
    accountController.LoadData(ui->tblAccounts, ui->cmbDeleteAccount);
}

void Dashboard::on_btnAccountDelete_clicked()
{
    QString accountName = ui->cmbDeleteAccount->currentText();

    AccountController accountController;
    accountController.DeleteAccount(accountName);
    accountController.LoadData(ui->tblAccounts, ui->cmbDeleteAccount);
}
