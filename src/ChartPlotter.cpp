#include "ChartPlotter.h"
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QHBoxLayout>
#include <cmath>

#include "AlgorithmsTester.h"

using namespace QtCharts;
using namespace std;

ChartPlotter::ChartPlotter() {
    experimentalChart = new QChart();
    theoreticalChart = new QChart();
    experimentalChartView = new QChartView(experimentalChart);
    theoreticalChartView = new QChartView(theoreticalChart);
    experimentalChartView->setRenderHint(QPainter::Antialiasing);
    theoreticalChartView->setRenderHint(QPainter::Antialiasing);

    const auto centralWidget = new QWidget();
    const auto layout = new QHBoxLayout(centralWidget);
    layout->addWidget(experimentalChartView);
    layout->addWidget(theoreticalChartView);

    window.setCentralWidget(centralWidget);
    window.resize(1600, 800);

    initializeAlgorithmComplexityMap();
}

void ChartPlotter::plotResults(const string& algorithm,
    const string& testCase,
    const vector<double>& experimentalResults,
    const vector<double>& theoreticalResults) {

    QVector<qreal> xValues = QVector<qreal>::fromStdVector(vector<qreal>(AlgorithmsTester::sizes.begin(), AlgorithmsTester::sizes.end()));
    const string complexity = algorithmComplexityMap[algorithm][testCase];

    experimentalChart->setTitle(QString("Experimental Results - %1").arg(QString::fromStdString(testCase)));
    theoreticalChart->setTitle(QString("Theoretical Results - %1").arg(QString::fromStdString(testCase)));

    QLineSeries* experimentalSeries = createSeries("Experimental " + algorithm, experimentalResults);
    configureChart(experimentalChart, experimentalSeries, complexity);

    QLineSeries* theoreticalSeries = createSeries("Theoretical " + algorithm, theoreticalResults);
    configureChart(theoreticalChart, theoreticalSeries, complexity);

    window.show();
}

QLineSeries* ChartPlotter::createSeries(const string& name, const vector<double>& values) {
    const auto series = new QLineSeries();
    series->setName(QString::fromStdString(name));
    for (size_t i = 0; i < values.size(); ++i) {
        series->append(i, values[i]);
    }

    series->setPointsVisible(true);
    series->setPointLabelsVisible(true);

    return series;
}

void ChartPlotter::configureChart(QChart* chart, QLineSeries* series, const string& complexity) {
    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QValueAxis* xAxis = new QValueAxis();
    xAxis->setTitleText("Input Size (n)");
    chart->setAxisX(xAxis, series);

    QCategoryAxis* yAxis = new QCategoryAxis();
    yAxis->setTitleText("Time Complexity");
    yAxis->append(QString::fromStdString(complexity), 1);
    chart->setAxisY(yAxis, series);
}

void ChartPlotter::initializeAlgorithmComplexityMap() {
    algorithmComplexityMap["BUBBLE_SORT"]["BEST_CASE"] = "O(n)";
    algorithmComplexityMap["BUBBLE_SORT"]["AVERAGE_CASE"] = "O(n^2)";
    algorithmComplexityMap["BUBBLE_SORT"]["WORST_CASE"] = "O(n^2)";

    algorithmComplexityMap["SELECTION_SORT"]["BEST_CASE"] = "O(n^2)";
    algorithmComplexityMap["SELECTION_SORT"]["AVERAGE_CASE"] = "O(n^2)";
    algorithmComplexityMap["SELECTION_SORT"]["WORST_CASE"] = "O(n^2)";

    algorithmComplexityMap["MERGE_SORT"]["BEST_CASE"] = "O(n log n)";
    algorithmComplexityMap["MERGE_SORT"]["AVERAGE_CASE"] = "O(n log n)";
    algorithmComplexityMap["MERGE_SORT"]["WORST_CASE"] = "O(n log n)";

    algorithmComplexityMap["LINKED_LIST_SEARCH"]["BEST_CASE"] = "O(1)";
    algorithmComplexityMap["LINKED_LIST_SEARCH"]["AVERAGE_CASE"] = "O(n)";
    algorithmComplexityMap["LINKED_LIST_SEARCH"]["WORST_CASE"] = "O(n)";

    algorithmComplexityMap["BS_TREE_INSERTION"]["BEST_CASE"] = "O(log n)";
    algorithmComplexityMap["BS_TREE_INSERTION"]["AVERAGE_CASE"] = "O(log n)";
    algorithmComplexityMap["BS_TREE_INSERTION"]["WORST_CASE"] = "O(n)";
}
