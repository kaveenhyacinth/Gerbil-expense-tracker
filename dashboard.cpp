#include "dashboard.h"
#include "ui_dashboard.h"

#include <QMessageBox>
#include <QPixmap>

Dashboard::Dashboard(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Dashboard)
{
    ui->setupUi(this);

    DataAdapter adapter;
    DataVisualizer visual;
    QPixmap pix(":/img/resources/gerbil_logo.png");

    int width = ui->lblAboutImage->width();
    int height = ui->lblAboutImage->height();

    ui->dtTrInDate->setDate(QDate::currentDate());
    ui->dtTrExDate->setDate(QDate::currentDate());
    ui->lblAboutImage->setPixmap(pix.scaled(width, height, Qt::KeepAspectRatio));
    ui->lblTotal->setText(adapter.FetchTotalBalance());
    ui->lblIncome->setText(adapter.FetchTotalStringByType("INCOME"));
    ui->lblExpense->setText(adapter.FetchTotalStringByType("EXPENSE"));

    adapter.LoadAccountData(ui->tblAccounts, ui->cmbDeleteAccount);
    adapter.LoadTransactionData
            (ui->tblTransactions, ui->cmbTrInAccount, ui->cmbTrInCategory, ui->cmbTrExAccount, ui->cmbTrExCategory);
    visual.RenderChart(ui->frmChart, adapter.FetchTotalByType("INCOME"), adapter.FetchTotalByType("EXPENSE"));
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
    DataVisualizer visual;
    DataAdapter adapter;
    AccountController accountController;

    QString accountName = ui->txtAccountName->text();
    QString balance = util.FormatBalance(ui->txtBalance->text(), ui->txtBalanceCents->text());
    Account account(accountName, balance);

    accountController.CreateAccount(account);

    adapter.LoadAccountData(ui->tblAccounts, ui->cmbDeleteAccount);
    adapter.LoadTransactionData
            (ui->tblTransactions, ui->cmbTrInAccount, ui->cmbTrInCategory, ui->cmbTrExAccount, ui->cmbTrExCategory);
    visual.RenderChart(ui->frmChart, adapter.FetchTotalByType("INCOME"), adapter.FetchTotalByType("EXPENSE"));

    ui->lblTotal->setText(adapter.FetchTotalBalance());
    ui->lblIncome->setText(adapter.FetchTotalStringByType("INCOME"));
    ui->lblExpense->setText(adapter.FetchTotalStringByType("EXPENSE"));
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

    DataAdapter adapter;
    DataVisualizer visual;
    AccountController accountController;
    TransactionController transactionController;

    QString accountName = ui->cmbDeleteAccount->currentText();

    transactionController.DeleteTransactionByAccount(transactionController.ParseAccountId(accountName));
    accountController.DeleteAccount(accountName);

    adapter.LoadAccountData(ui->tblAccounts, ui->cmbDeleteAccount);
    adapter.LoadTransactionData
            (ui->tblTransactions, ui->cmbTrInAccount, ui->cmbTrInCategory, ui->cmbTrExAccount, ui->cmbTrExCategory);
    visual.RenderChart(ui->frmChart, adapter.FetchTotalByType("INCOME"), adapter.FetchTotalByType("EXPENSE"));

    ui->lblTotal->setText(adapter.FetchTotalBalance());
    ui->lblIncome->setText(adapter.FetchTotalStringByType("INCOME"));
    ui->lblExpense->setText(adapter.FetchTotalStringByType("EXPENSE"));
}

void Dashboard::on_btnTrInAdd_clicked()
{
    Util util;
    DataAdapter adapter;
    DataVisualizer visual;
    TransactionController transactionController;

    int accountId = transactionController.ParseAccountId(ui->cmbTrInAccount->currentText());
    int categoryId = transactionController.ParseCategoryId(ui->cmbTrInCategory->currentText());
    QString amount = util.FormatBalance(ui->txtTrInAmount->text(), ui->txtTrInCents->text());
    QString type = "INCOME";
    QDate date = ui->dtTrInDate->date();
    Transaction transaction(accountId, categoryId, type, amount, date);

    if(adapter.UpdateAccountIncome(accountId, util.FormatMoney(amount)))
        transactionController.CreateTransaction(transaction);

    adapter.LoadAccountData(ui->tblAccounts, ui->cmbDeleteAccount);
    adapter.LoadTransactionData
            (ui->tblTransactions, ui->cmbTrInAccount, ui->cmbTrInCategory, ui->cmbTrExAccount, ui->cmbTrExCategory);
    visual.RenderChart(ui->frmChart, adapter.FetchTotalByType("INCOME"), adapter.FetchTotalByType("EXPENSE"));

    ui->lblTotal->setText(adapter.FetchTotalBalance());
    ui->lblIncome->setText(adapter.FetchTotalStringByType("INCOME"));
    ui->lblExpense->setText(adapter.FetchTotalStringByType("EXPENSE"));
}

void Dashboard::on_btnTrExAdd_clicked()
{
    Util util;
    DataAdapter adapter;
    DataVisualizer visual;
    TransactionController transactionController;

    int accountId = transactionController.ParseAccountId(ui->cmbTrExAccount->currentText());
    int categoryId = transactionController.ParseCategoryId(ui->cmbTrExCategory->currentText());
    QString amount = util.FormatBalance(ui->txtTrExAmount->text(), ui->txtTrExCents->text());
    QString type = "EXPENSE";
    QDate date = ui->dtTrExDate->date();
    Transaction transaction(accountId, categoryId, type, amount, date);

    if(adapter.UpdateAccountExpense(accountId, util.FormatMoney(amount)))
        transactionController.CreateTransaction(transaction);

    adapter.LoadAccountData(ui->tblAccounts, ui->cmbDeleteAccount);
    adapter.LoadTransactionData
            (ui->tblTransactions, ui->cmbTrInAccount, ui->cmbTrInCategory, ui->cmbTrExAccount, ui->cmbTrExCategory);
    visual.RenderChart(ui->frmChart, adapter.FetchTotalByType("INCOME"), adapter.FetchTotalByType("EXPENSE"));

    ui->lblTotal->setText(adapter.FetchTotalBalance());
    ui->lblIncome->setText(adapter.FetchTotalStringByType("INCOME"));
    ui->lblExpense->setText(adapter.FetchTotalStringByType("EXPENSE"));
}
