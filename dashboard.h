/*!
 * \author Kaveen Hyacinth
 * \copyright Kaveen Hyacinth Digital © 2020
 * \package view
*/

#ifndef DASHBOARD_H
#define DASHBOARD_H

#include "util.h"
#include "account.h"
#include "dataadapter.h"
#include "transaction.h"
#include "datavisualizer.h"
#include "accountcontroller.h"
#include "transactioncontroller.h"

#include <QtDebug>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Dashboard; }
QT_END_NAMESPACE

/*!
 * \brief The Dashboard class is the main window of the application where user does every operation
 */
class Dashboard : public QMainWindow
{
    Q_OBJECT

public:
    Dashboard(QWidget *parent = nullptr);
    ~Dashboard();

private slots:
    void on_btnTrInAdd_clicked();

    void on_btnAccountAdd_clicked();

    void on_btnAccountDelete_clicked();

    void on_btnTrExAdd_clicked();

    void on_btnTrInClear_clicked();

    void on_btnTrExClear_clicked();

    void on_btnAccountClear_clicked();

    void on_btnFilter_clicked();

    void on_btnReset_clicked();

private:
    Ui::Dashboard *ui;
};
#endif // DASHBOARD_H
