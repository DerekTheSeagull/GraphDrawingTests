//
// Created by Josh aka Bae on 21/03/2016.
//

#include "GraphGraphicsScene.h"
#include <iostream>
#include <QtWidgets/QGraphicsItem>

using namespace std;

GraphGraphicsScene::GraphGraphicsScene(int width, int height) {
    height_ = height;
    width_ = width;

    view.setScene(this);
    view.setSceneRect(-250, -250, 500, 500);

    view.setDragMode(QGraphicsView::ScrollHandDrag);

    axisPen.setColor(Qt::red);
    yAxis.setPen(axisPen);
    xAxis.setPen(axisPen);

    AddGrid();

    connect(&timer, SIGNAL(timeout()), this, SLOT(tick()));
    timer.start(10);
}

bool GraphGraphicsScene::DrawGraph(string sEquation) {

}

bool GraphGraphicsScene::DrawAxes() {
    //scrolls the y-axis when the scene moves
    if (currentMinY <= 0 <= currentMaxY) {
        yAxis.setLine(0, currentMinY, 0, currentMaxY);
        removeItem(&yAxis);
        addItem(&yAxis);
    }   else if (0 > currentMaxY) {
        yAxis.setLine(currentMaxX, currentMinY, currentMaxX, currentMaxY);
        removeItem(&yAxis);
        addItem(&yAxis);
    }   else if (0 < currentMinY) {
        yAxis.setLine(currentMaxX , currentMinY, currentMaxX, currentMaxY);
        removeItem(&yAxis);
        addItem(&yAxis);
    }

    //scrolls the x-axis when the screen moves
    if (currentMinX <= 0 <= currentMaxX) {
        xAxis.setLine(currentMinX, 0, currentMaxX, 0);
        removeItem(&xAxis);
        addItem(&xAxis);
    }   else if (0 > currentMaxY) {
        xAxis.setLine(currentMinX, currentMaxY, currentMaxX, currentMaxY);
        removeItem(&xAxis);
        addItem(&xAxis);
    }   else if (0 < currentMinY) {
        xAxis.setLine(currentMinX, currentMaxY, currentMaxX, currentMaxY);
        removeItem(&xAxis);
        addItem(&xAxis);
    }
}

bool GraphGraphicsScene::AddGrid() {
    //draws lines along the y-axis
    for (int i = -100000 / 20; i < 100000 / 20; ++i) {
            addLine(currentMinX, i * 20, currentMaxX, i * 20);
    }

}

bool GraphGraphicsScene::AddLabels() {

}

void GraphGraphicsScene::tick() {
    //records the scene coordinates under the top-left and bottom-right corners of the view
    currentMinX = view.mapToScene(0, 0).x();
    currentMinY = view.mapToScene(0, 0).x();

    currentMaxX = view.mapToScene(view.height(), 0).x();
    currentMaxY = view.mapToScene(0, view.width()).y();


    DrawAxes();
}