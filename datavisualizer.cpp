#include "datavisualizer.h"

DataVisualizer::DataVisualizer()
{

}

void DataVisualizer::RenderChart(QWidget *frame, int incomeBalance, int expenseBalance)
{
    QPieSeries *series = new QPieSeries();

    series->append("INCOME", incomeBalance)->setBrush(Qt::green);
    series->append("EXPENSES", expenseBalance)->setBrush(Qt::red);

    QPieSlice *sliceIn = series->slices().at(0);
    sliceIn->setLabel("Income " + QString("%1%").arg(100*sliceIn->percentage(), 0, 'f', 1));

    QPieSlice *sliceEx = series->slices().at(1);
    sliceEx->setLabel("Expense " + QString("%1%").arg(100*sliceEx->percentage(), 0, 'f', 1));

    if(!(incomeBalance <= 0 && expenseBalance <= 0))
    {
        series->setLabelsVisible();
        series->setLabelsPosition(QPieSlice::LabelOutside);
        sliceEx->setLabelVisible(true);
        sliceIn->setLabelVisible(true);
    }

    qDebug() << "Rendering Charts" << incomeBalance << expenseBalance;

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Cash Flow of Last 30 Days");

    QChartView *chartView = new QChartView(chart);
    chartView->setParent(frame);
    chartView->resize(frame->width(), frame->height());
}
