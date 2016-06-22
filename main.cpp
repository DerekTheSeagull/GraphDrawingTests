#include <iostream>
#include <QtWidgets/qapplication.h>
#include <QtWidgets/qdesktopwidget.h>
#include "ConvertEquation.h"
#include "MainWindow.h"

using namespace std;

int main(int argc, char **argv) {

    QApplication app (argc, argv);
    MainWindow mw;
    mw.show();
    app.exec();

    return 0;
}