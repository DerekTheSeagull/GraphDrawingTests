#include <iostream>
//#include <QtWidgets/qapplication.h>
//#include <QtWidgets/qdesktopwidget.h>
//#include "ConvertEquation.h"
//#include "MainWindow.h"
#include "RearrangeEq.h"

using namespace std;

int main(int argc, char **argv) {
    //QApplication app (argc, argv);
    //MainWindow mw;
    //mw.show();
    //app.exec();

    RearrageEquation("x+3*2+y*4=x+3", "y");

    return 0;
}