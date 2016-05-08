//
// Created by Josh aka Bae on 21/03/2016.
//

#include "MainWindow.h"

using namespace std;

MainWindow::MainWindow() {
    setMenuBar(&qmMenuBar);
    qvbLayout.addWidget(&qtToolbar);
    qvbLayout.addWidget(&ggsGraph->view);
    qwCentralWidget.setLayout(&qvbLayout);
    setCentralWidget(&qwCentralWidget);
}
