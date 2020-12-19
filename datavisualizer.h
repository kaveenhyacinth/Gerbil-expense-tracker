#ifndef DATAVISUALIZER_H
#define DATAVISUALIZER_H

#include <QtCharts>
#include <QChartView>
#include <QPieSeries>
#include <QPieSlice>

class DataVisualizer
{
public:
    DataVisualizer();

public:
    void RenderChart(QWidget *, int, int);
};

#endif // DATAVISUALIZER_H
