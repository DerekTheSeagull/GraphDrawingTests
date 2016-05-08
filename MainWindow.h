//
// Created by Josh aka Bae on 21/03/2016.
//

#ifndef GRAPHDRAWINGTESTS_MAINWINDOW_H
#define GRAPHDRAWINGTESTS_MAINWINDOW_H

#include "GraphGraphicsScene.h"

#include <QtCore>
#include <QtGui>
#include <QtWidgets/qmainwindow.h>
#include <QtWidgets/qboxlayout.h>
#include <QtWidgets/qmenubar.h>
#include <QtWidgets/qtoolbar.h>
#include <QtWidgets/QPushButton>
#include <QtWidgets/qdesktopwidget.h>

using namespace std;

class MainWindow : public QMainWindow {

public:
    MainWindow();

private:

    QVBoxLayout qvbLayout;
    QWidget qwCentralWidget;
    QToolBar qtToolbar;
    QMenuBar qmMenuBar;
    QDesktopWidget dw;
    GraphGraphicsScene *ggsGraph = new GraphGraphicsScene(200, 200);
};


#endif //GRAPHDRAWINGTESTS_MAINWINDOW_H
