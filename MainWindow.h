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
#include "images/resources.cpp"

using namespace std;

class MainWindow : public QMainWindow {

Q_OBJECT

public:
    MainWindow();
    GraphGraphicsScene* getGraph();

private:
    void CreateMainLayout();

    QVBoxLayout qvbLayout;
    QHBoxLayout qhbZoomButtons;
    QWidget qwCentralWidget;
    QToolBar qtToolbar;
    QMenuBar qmMenuBar;
    GraphGraphicsScene *ggsGraph = new GraphGraphicsScene(500, 500);
};


#endif //GRAPHDRAWINGTESTS_MAINWINDOW_H
