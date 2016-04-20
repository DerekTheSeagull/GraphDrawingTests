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
    view.setSceneRect(- width_ / 2 , - height_ / 2, width_, height_);

    view.setDragMode(QGraphicsView::ScrollHandDrag);

    axisPen_.setColor(Qt::red);
    yAxis_.setPen(axisPen_);
    xAxis_.setPen(axisPen_);

    AddGrid();

    connect(&timer_, SIGNAL(timeout()), this, SLOT(tick()));
    timer_.start(10);
}

bool GraphGraphicsScene::DrawGraph(string sEquation) {

}

bool GraphGraphicsScene::DrawAxes() {
    //scrolls the y-axis as the scene moves
    if ( currentMinX_ <= 0 <= currentMaxX_ ) {
        yAxis_.setLine(0, currentMinY_, 0, currentMaxY_);
        removeItem(&yAxis_);
        addItem(&yAxis_);
    }

    //scrolls the x-axis as the scene moves
}

bool GraphGraphicsScene::AddGrid() {
    //draws lines along the y-axis
    for (int i = -100000 / 20; i < 100000 / 20; ++i) {
            addLine(currentMinX_, i * 20, currentMaxX_, i * 20);
    }

}

bool GraphGraphicsScene::AddLabels() {

}

void GraphGraphicsScene::tick() {
    scrollOffsetX_ += 10;
    scrollOffsetY_ += 10;

    //view.setSceneRect(viewX_ + scrollOffsetX_, viewY_ + scrollOffsetY_, 500, 500);

    //records the scene coordinates under the top-left and bottom-right corners of the view
    currentMinX_ = view.mapToScene(0, 0).x();
    currentMinY_ = view.mapToScene(0, 0).x();

    currentMaxX_ = view.mapToScene(view.height(), 0).x();
    currentMaxY_ = view.mapToScene(0, view.width()).y();

    //updates the position of the axes on the screen
    DrawAxes();
}