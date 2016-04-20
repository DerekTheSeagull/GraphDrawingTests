#include <iostream>
#include <QtWidgets/qapplication.h>
#include <QtWidgets/qdesktopwidget.h>
#include "ConvertEquation.h"
#include "MainWindow.h"

using namespace std;

int main(int argc, char **argv) {
    QApplication app (argc, argv);
    QDesktopWidget dw;

    MainWindow mw;
    mw.setFixedHeight(dw.height() * 0.7);
    mw.setFixedWidth(dw.width() * 0.7);
    mw.show();
    app.exec();

    return 0;
}