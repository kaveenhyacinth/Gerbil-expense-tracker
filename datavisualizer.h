/*!
 * \author Kaveen Hyacinth
 * \copyright Kaveen Hyacinth Digital © 2020
 * \package controller
*/

#ifndef DATAVISUALIZER_H
#define DATAVISUALIZER_H

#include <QtCharts>
#include <QChartView>
#include <QPieSeries>
#include <QPieSlice>

/*!
 * \brief The DataVisualizer class renders the chart of cashflow accoring to the given inputs
 */
class DataVisualizer
{
public:
    DataVisualizer();

public:
    /*!
     * \brief RenderChart renders the chart accoring to the given inputs
     * \param frame is a QWidget with renders the ChartView
     */
    void RenderChart(QWidget *frame, int incomeBalance, int expenseBalance);
};

#endif // DATAVISUALIZER_H
