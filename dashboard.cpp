#include "dashboard.h"
#include "ui_dashboard.h"
#include "dbgateway.h"

Dashboard::Dashboard(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Dashboard)
{
    DbGateway db;

    ui->setupUi(this);

    (db.Connect())
            ? ui->lblConnection->setText("Connected...")
            : ui->lblConnection->setText("Database connection failed...");
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
}
