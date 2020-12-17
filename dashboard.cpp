#include "dashboard.h"
#include "ui_dashboard.h"

#include <QMessageBox>

Dashboard::Dashboard(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Dashboard)
{
    DataAdapter adapter;

    ui->setupUi(this);
    ui->dtTrInDate->setDate(QDate::currentDate());
    ui->dtTrExDate->setDate(QDate::currentDate());
    ui->lblIncome->setText(adapter.FetchTotalByType("INCOME"));
    ui->lblExpense->setText(adapter.FetchTotalByType("EXPENSE"));
    ui->lblTotal->setText(adapter.FetchTotalBalance());

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
    QMessageBox msgBox;
    msgBox.setWindowTitle("Confirm Action!");
    msgBox.setText("Do you want to add this new account?");
    msgBox.setIcon(QMessageBox::Question);
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    int ret = msgBox.exec();

    if(ret != QMessageBox::Yes) return;

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

    ui->lblIncome->setText(adapter.FetchTotalByType("INCOME"));
    ui->lblExpense->setText(adapter.FetchTotalByType("EXPENSE"));
    ui->lblTotal->setText(adapter.FetchTotalBalance());
}

void Dashboard::on_btnAccountDelete_clicked()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("Confirm Action!");
    msgBox.setText("Do you want to delete this account?");
    msgBox.setIcon(QMessageBox::Question);
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    int ret = msgBox.exec();

    if(ret != QMessageBox::Yes) return;

    QString accountName = ui->cmbDeleteAccount->currentText();
    TransactionController transactionController;
    AccountController accountController;
    DataAdapter adapter;

    transactionController.DeleteTransactionByAccount(transactionController.ParseAccountId(accountName));
    accountController.DeleteAccount(accountName);

    adapter.LoadAccountData(ui->tblAccounts, ui->cmbDeleteAccount);
    adapter.LoadTransactionData
            (ui->tblTransactions, ui->cmbTrInAccount, ui->cmbTrInCategory, ui->cmbTrExAccount, ui->cmbTrExCategory);

    ui->lblIncome->setText(adapter.FetchTotalByType("INCOME"));
    ui->lblExpense->setText(adapter.FetchTotalByType("EXPENSE"));
    ui->lblTotal->setText(adapter.FetchTotalBalance());
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

    if(adapter.UpdateAccountIncome(accountId, util.FormatMoney(amount)))
        transactionController.CreateTransaction(transaction);

    adapter.LoadAccountData(ui->tblAccounts, ui->cmbDeleteAccount);
    adapter.LoadTransactionData
            (ui->tblTransactions, ui->cmbTrInAccount, ui->cmbTrInCategory, ui->cmbTrExAccount, ui->cmbTrExCategory);

    ui->lblIncome->setText(adapter.FetchTotalByType("INCOME"));
    ui->lblExpense->setText(adapter.FetchTotalByType("EXPENSE"));
    ui->lblTotal->setText(adapter.FetchTotalBalance());
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

    if(adapter.UpdateAccountExpense(accountId, util.FormatMoney(amount)))
        transactionController.CreateTransaction(transaction);

    adapter.LoadAccountData(ui->tblAccounts, ui->cmbDeleteAccount);
    adapter.LoadTransactionData
            (ui->tblTransactions, ui->cmbTrInAccount, ui->cmbTrInCategory, ui->cmbTrExAccount, ui->cmbTrExCategory);

    ui->lblIncome->setText(adapter.FetchTotalByType("INCOME"));
    ui->lblExpense->setText(adapter.FetchTotalByType("EXPENSE"));
    ui->lblTotal->setText(adapter.FetchTotalBalance());
}
