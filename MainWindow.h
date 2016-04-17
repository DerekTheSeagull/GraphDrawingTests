//
// Created by Josh aka Bae on 21/03/2016.
//

#ifndef GRAPHDRAWINGTESTS_MAINWINDOW_H
#define GRAPHDRAWINGTESTS_MAINWINDOW_H

#include <QtCore>
#include <QtGui>
#include <QtWidgets/qmainwindow.h>
#include <QtWidgets/qboxlayout.h>
#include <QtWidgets/qmenubar.h>
#include <QtWidgets/qtoolbar.h>

using namespace std;

class MainWindow : QMainWindow {

public:
    MainWindow();



private:
    QVBoxLayout qvbLayout;
    QWidget qwCentralWidget;
    QToolBar qtToolbar;
    QMenuBar qmMenuBar;
};


#endif //GRAPHDRAWINGTESTS_MAINWINDOW_H
