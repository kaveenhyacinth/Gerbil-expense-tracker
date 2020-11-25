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
    DbGateway db;
    QSqlQuery qry;
    QString accountName, accountBalance;

    accountName = ui->txtAccountName->text();
    accountBalance = ui->txtBalance->text();

    if(!db.Connect()) {
        qDebug() << "Failed to open the database connection";
        return;
    }
    qry.prepare("INSERT INTO account (account_name, balance) VALUES (?, ?)");
    qry.bindValue(0, accountName);
    qry.bindValue(1, accountBalance.toInt());

    if(qry.exec())
    {
        ui->lblConnection->setText("Account Saved..");
        db.Disconnect();
    }
    else
    {
        ui->lblConnection->setText("Went Wrong...");
    }
}
