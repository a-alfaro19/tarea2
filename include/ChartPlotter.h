#pragma once

#include <QChartView>
#include <QLineSeries>
#include <QMainWindow>
#include <vector>
#include <string>

class ChartPlotter {
public:
    /**
     * Constructor
     */
    ChartPlotter();

    /**
     * Plot the results of the given algorithm
     * @param algorithm The algorithm to be plotted
     * @param experimentalResults The experimental results
     * @param theoreticalResults The theoretical results
     * @param testCase The test case
     */
    void plotResults(const std::string& algorithm,
        const std::string& testCase,
        const std::vector<double>& experimentalResults,
        const std::vector<double>& theoreticalResults);

private:
    /**
     * Create a series
     * @param name The name of the series
     * @param values The values of the series
     * @return The series
     */
    static QtCharts::QLineSeries* createSeries(const std::string& name, const std::vector<double>& values);

    /**
     * Configure the chart
     * @param chart The chart to be configured
     * @param series The series to be added
     * @param complexity The complexity of the algorithm
     */
    static void configureChart(QtCharts::QChart* chart, QtCharts::QLineSeries* series, const std::string& complexity);

    /**
     * Initialize the algorithm complexity map
     */
    void initializeAlgorithmComplexityMap();

    QtCharts::QChart* experimentalChart; ///< The chart
    QtCharts::QChartView* experimentalChartView; ///< The chart view
    QtCharts::QChart* theoreticalChart; ///< The theoretical chart
    QtCharts::QChartView* theoreticalChartView; ///< The theoretical chart view

    QMainWindow window; ///< The window
    std::map<std::string, std::map<std::string, std::string>> algorithmComplexityMap; ///< The algorithm complexity map
};

