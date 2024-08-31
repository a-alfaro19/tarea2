#include <iostream>
#include <QApplication>

#include "AlgorithmsTester.h"
#include "ChartPlotter.h"

using namespace QtCharts;
using namespace std;

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    if (argc < 3) {
        qCritical("Usage: %s <Algorithm> <Test Case>", argv[0]);
        return -1;
    }
    const string algorithmArg = argv[1];
    const string testCaseArg = argv[2];

    AlgorithmsTester tester;
    const auto experimentalResult = tester.runTest(algorithmArg, testCaseArg);
    const auto theoreticalComplexity = tester.getTheoreticalComplexity(algorithmArg, testCaseArg);

    if (!experimentalResult.has_value() || !theoreticalComplexity.has_value()) {
        qCritical("Invalid algorithm");
        return -1;
    }

    ChartPlotter plotter;
    plotter.plotResults(algorithmArg, experimentalResult.value(), theoreticalComplexity.value(), testCaseArg);

    return app.exec();
}
