#ifndef DASHBOARD_H
#define DASHBOARD_H

#include "util.h"
#include "account.h"
#include "accountcontroller.h"
#include <QMainWindow>
#include <QtDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class Dashboard; }
QT_END_NAMESPACE

class Dashboard : public QMainWindow
{
    Q_OBJECT

public:
    Dashboard(QWidget *parent = nullptr);
    ~Dashboard();

private slots:
    void on_btnAccountAdd_clicked();

    void on_btnAccountDelete_clicked();

private:
    Ui::Dashboard *ui;
};
#endif // DASHBOARD_H
