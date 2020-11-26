#include "dashboard.h"
#include "ui_dashboard.h"

Dashboard::Dashboard(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Dashboard)
{
    AccountController accountController;

    ui->setupUi(this);
    accountController.LoadData(ui->tblAccounts, ui->cmbDeleteAccount);
}

Dashboard::~Dashboard()
{
    delete ui;
}

void Dashboard::on_btnAccountAdd_clicked()
{
    Util util;
    QString accountName = ui->txtAccountName->text();
    QString balance = util.FormatBalance(ui->txtBalance->text(), ui->txtBalanceCents->text());
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

void Dashboard::on_btnTrInAdd_clicked()
{
    Util util;
    TransactionController transactionController;
    int accountId = transactionController.ParseAccountId(ui->cmbTrInAccount->currentText());
    int categoryId = transactionController.ParseCategoryId(ui->cmbTrInCategory->currentText());
    QString amount = util.FormatBalance(ui->txtTrInAmount->text(), ui->txtTrInCents->text());
    QString type = "I";
    QDate date = ui->dtTrInDate->date();
    Transaction transaction(accountId, categoryId, type, amount, date);

    transactionController.CreateTransaction(transaction);

}
