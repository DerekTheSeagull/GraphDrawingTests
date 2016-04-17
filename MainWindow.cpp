//
// Created by Josh aka Bae on 21/03/2016.
//

#include "MainWindow.h"

MainWindow::MainWindow() {
    setMenuBar(&qmMenuBar);
    qvbLayout.addWidget(&qtToolbar);
    qwCentralWidget.setLayout(&qvbLayout);
    setCentralWidget(&qwCentralWidget);
}