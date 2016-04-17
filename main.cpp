#include <iostream>
#include <QtWidgets/qapplication.h>
#include "ConvertEquation.h"
#include "MainWindow.h"
#include "exprtk.hpp"

using namespace std;

int main() {
    QApplication app(__argc, __argv);
    app.exec();
    MainWindow mwMainWindow;
    mwMainWindow.raise();

    return 0;
}