#include "ChartPlotter.h"
#include <QtCharts/QLineSeries>

using namespace QtCharts;
using namespace std;

ChartPlotter::ChartPlotter() {
    chart = new QChart();
    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    window.setCentralWidget(chartView);
    window.resize(800, 600);
}

void ChartPlotter::plotResults(const string& algorithm,
    const vector<double>& experimentalResults,
    const vector<double>& theoreticalResults,
    const string& testCase) {

    chart->setTitle(QString("Benchmark Result - %1").arg(QString::fromStdString(testCase)));

    QLineSeries* experimentalSeries = new QLineSeries();
    experimentalSeries->setName("Experimental " + QString::fromStdString(algorithm));

    QVector<qreal> xValues = {100, 5050, 10000};

    const double k = calculateScalingFactor({100, 5050, 10000}, experimentalResults);
    for (size_t i = 0; i < experimentalResults.size(); ++i) {
        experimentalSeries->append(xValues[i], experimentalResults[i]);
    }

    experimentalSeries->setPointsVisible(true);
    experimentalSeries->setPointLabelsVisible(true);

    const auto theoreticalSeries = new QLineSeries();
    theoreticalSeries->setName("Theoretical " + QString::fromStdString(algorithm));
    theoreticalSeries->setColor(Qt::red);

    for (size_t i = 0; i < theoreticalResults.size(); ++i) {
        theoreticalSeries->append(xValues[i], theoreticalResults[i] * k);
    }

    theoreticalSeries->setPointsVisible(true);
    theoreticalSeries->setPointLabelsVisible(true);

    chart->addSeries(experimentalSeries);
    chart->addSeries(theoreticalSeries);
    chart->createDefaultAxes();
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    window.show();
}

double ChartPlotter::calculateScalingFactor(const vector<int>& inputSizes, const vector<double>& experimentalTimes) {
    const int n = inputSizes.size();
    const double sum_n = accumulate(inputSizes.begin(), inputSizes.end(), 0.0);
    const double sum_t = accumulate(experimentalTimes.begin(), experimentalTimes.end(), 0.0);
    double sum_nt = 0.0;
    double sum_n2 = 0.0;

    for (int i = 0; i < n; ++i) {
        sum_nt += inputSizes[i] * experimentalTimes[i];
        sum_n2 += inputSizes[i] * inputSizes[i];
    }

    const double k = (n * sum_nt - sum_n * sum_t) / (n * sum_n2 - sum_n * sum_n);
    return k;
}