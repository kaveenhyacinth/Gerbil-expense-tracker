#include "dashboard.h"
#include "ui_dashboard.h"

Dashboard::Dashboard(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Dashboard)
{
    DataAdapter adapter;

    ui->setupUi(this);
    adapter.LoadAccountData(ui->tblAccounts, ui->cmbDeleteAccount);
    adapter.LoadTransactionData
            (ui->tblTransactions, ui->cmbTrInAccount, ui->cmbTrInCategory, ui->cmbTrExAccount, ui->cmbTrExCategory);
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
    DataAdapter adapter;

    accountController.CreateAccount(account);
    adapter.LoadAccountData(ui->tblAccounts, ui->cmbDeleteAccount);
    adapter.LoadTransactionData
            (ui->tblTransactions, ui->cmbTrInAccount, ui->cmbTrInCategory, ui->cmbTrExAccount, ui->cmbTrExCategory);
}

void Dashboard::on_btnAccountDelete_clicked()
{
    QString accountName = ui->cmbDeleteAccount->currentText();
    AccountController accountController;
    DataAdapter adapter;

    accountController.DeleteAccount(accountName);
    adapter.LoadAccountData(ui->tblAccounts, ui->cmbDeleteAccount);
    adapter.LoadTransactionData
            (ui->tblTransactions, ui->cmbTrInAccount, ui->cmbTrInCategory, ui->cmbTrExAccount, ui->cmbTrExCategory);
}

void Dashboard::on_btnTrInAdd_clicked()
{
    Util util;
    TransactionController transactionController;
    int accountId = transactionController.ParseAccountId(ui->cmbTrInAccount->currentText());
    int categoryId = transactionController.ParseCategoryId(ui->cmbTrInCategory->currentText());
    QString amount = util.FormatBalance(ui->txtTrInAmount->text(), ui->txtTrInCents->text());
    QString type = "INCOME";
    QDate date = ui->dtTrInDate->date();
    Transaction transaction(accountId, categoryId, type, amount, date);
    DataAdapter adapter;

    transactionController.CreateTransaction(transaction);
    adapter.LoadAccountData(ui->tblAccounts, ui->cmbDeleteAccount);
    adapter.LoadTransactionData
            (ui->tblTransactions, ui->cmbTrInAccount, ui->cmbTrInCategory, ui->cmbTrExAccount, ui->cmbTrExCategory);

}

void Dashboard::on_btnTrExAdd_clicked()
{
    Util util;
    TransactionController transactionController;
    int accountId = transactionController.ParseAccountId(ui->cmbTrExAccount->currentText());
    int categoryId = transactionController.ParseCategoryId(ui->cmbTrExCategory->currentText());
    QString amount = util.FormatBalance(ui->txtTrExAmount->text(), ui->txtTrExCents->text());
    QString type = "EXPENSE";
    QDate date = ui->dtTrExDate->date();
    Transaction transaction(accountId, categoryId, type, amount, date);
    DataAdapter adapter;

    transactionController.CreateTransaction(transaction);
    adapter.LoadAccountData(ui->tblAccounts, ui->cmbDeleteAccount);
    adapter.LoadTransactionData
            (ui->tblTransactions, ui->cmbTrInAccount, ui->cmbTrInCategory, ui->cmbTrExAccount, ui->cmbTrExCategory);
}
