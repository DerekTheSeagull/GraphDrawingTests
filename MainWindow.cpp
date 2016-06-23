//
// Created by Josh aka Bae on 21/03/2016.
//

#include "MainWindow.h"

using namespace std;

MainWindow::MainWindow() {
    CreateMainLayout();
}

void MainWindow::CreateMainLayout() {
    QResource::registerResource("resources.cpp");
    setWindowIcon(QIcon(QPixmap(":/window_icon")));

    setMenuBar(&qmMenuBar);

    qvbLayout.addWidget(&qtToolbar);
    qvbLayout.addWidget(&ggsGraph->view);

    qwCentralWidget.setLayout(&qvbLayout);
    setCentralWidget(&qwCentralWidget);
}

GraphGraphicsScene* MainWindow::getGraph() {
    return ggsGraph;
}
