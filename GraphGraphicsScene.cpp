//
// Created by Josh aka Bae on 27/04/2016.
//

#include "GraphGraphicsScene.h"

using namespace std;

GraphGraphicsScene::GraphGraphicsScene(int w, int h) {
    width_ = w; height_ = h;

    view.setScene(this);
    view.setSceneRect(-width_ / 2, -height_ / 2, height_, width_);

    iMinX_ = -width_/2; iMinY_ = -height_/2;
    iMaxX_ = iMinX_ + width_; iMaxY_ = iMinY_ + height_;

    pen.setColor(Qt::red); yAxis_.setPen(pen); xAxis_.setPen(pen);

    connect(timer, SIGNAL(timeout()), this, SLOT(tick()));

    timer->start(10);
}

void GraphGraphicsScene::drawAxis() {
    if (iMinX_ > 0) {
        yAxis_.setLine(iMinX_, iMinY_, iMinX_, iMaxY_);
        removeItem(&yAxis_);
        addItem(&yAxis_);
    } else if (iMaxX_ < 0) {
        yAxis_.setLine(iMaxX_, iMinY_, iMaxX_, iMaxY_);
        removeItem(&yAxis_);
        addItem(&yAxis_);
    } else if (iMinX_ < 0 < iMaxX_) {
        yAxis_.setLine(0, iMinY_, 0, iMaxY_);
        removeItem(&yAxis_);
        addItem(&yAxis_);
    }

    if (iMinY_ > 0) {
        xAxis_.setLine(iMinX_, iMinY_, iMaxX_, iMinY_);
        removeItem(&xAxis_);
        addItem(&xAxis_);
    } else if (iMaxY_ < 0) {
        xAxis_.setLine(iMinX_, iMinY_, iMaxX_, iMinY_);
        removeItem(&xAxis_);
        addItem(&xAxis_);
    } else if (iMinY_ < 0 < iMaxY_) {
        xAxis_.setLine(iMinX_, 0, iMaxX_, 0);
        removeItem(&xAxis_);
        addItem(&xAxis_);
    }
}

long GraphGraphicsScene::tick() {
    iMinX_ += xOffset;
    iMinY_ += yOffset;

    iMaxX_ = iMinX_ + height_;
    iMaxY_ = iMinY_ + width_;

    view.setSceneRect(iMinX_, iMinY_, height_, width_);

    drawAxis();


}
