#pragma once

#include <QChartView>
#include <QMainWindow>
#include <vector>
#include <string>

class ChartPlotter {
public:
    ChartPlotter();
    void plotResults(const std::string& algorithm,
        const std::vector<double>& experimentalResults,
        const std::vector<double>& theoreticalResults,
        const std::string& testCase);

private:
    static double calculateScalingFactor(const std::vector<int>& inputSizes, const std::vector<double>& experimentalTimes);
    QtCharts::QChart* chart;
    QtCharts::QChartView* chartView;
    QMainWindow window;
};

