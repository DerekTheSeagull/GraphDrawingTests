//
// Created by Josh aka Bae on 27/04/2016.
//

#include "GraphGraphicsScene.h"
#include "ReadEquation.h"

using namespace std;

GraphGraphicsScene::GraphGraphicsScene(int w, int h) {
    width_ = w; height_ = h;

    view.setFixedHeight(height_ + 3);
    view.setFixedWidth(width_ + 3);

    view.setScene(this);
    view.setSceneRect(-width_ / 2, -height_ / 2, height_, width_);

    iMinX_ = -width_/2; iMinY_ = -height_/2;
    iMaxX_ = iMinX_ + width_; iMaxY_ = iMinY_ + height_;

    AxisPen_.setColor(Qt::red); yAxis_.setPen(AxisPen_); xAxis_.setPen(AxisPen_);
    GridPen_.setColor(Qt::lightGray);

    connect(timer_, SIGNAL(timeout()), this, SLOT(tick()));

    for (int i = 0; i <= iLinesToStore_; ++i) {
        GridLines_.insert(GridLines_.end(), new QGraphicsLineItem);
        GridLines_[i]->setPen(GridPen_);
    }

    DrawGrid(iScale_);

    DrawGraph("3x");

    timer_->start(1000 * 1 / 30);
}

void GraphGraphicsScene::DrawGrid(int scale) {
    int i = 0;


    //Loops through all values of x that are divisible by the scale starting at the smallest
    //visible x value that is divisible by the scale
    //Then draws lines for the grid
    for (int x = iMinX_ - (iMinX_ % scale); x <= iMaxX_; x += scale) {
        GridLines_[i]->setLine(x, iMinY_, x, iMaxY_);
        if (GridLines_[i]->scene() == this) {
            removeItem(GridLines_[i]);
        }
        addItem(GridLines_[i]);

        ++i;
    }

    i = iLinesToStore_ - 1;


    //Loops through all values of y that are divisible by the scale starting at the smallest
    //visible y value that is divisible by the scale
    //Then draws lines for the grid
    for (int y = iMinY_ - (iMinY_ % scale); y <= iMaxY_; y += scale) {
        GridLines_[i]->setLine(iMinX_, y, iMaxX_, y);
        if (GridLines_[i]->scene() == this) {
            removeItem(GridLines_[i]);
        }
        addItem(GridLines_[i]);

        --i;
    }

}

void GraphGraphicsScene::DrawGraph(string equation) {
    map<double, double> mValues = ReadEquation(equation);

    for (double x = iMinX_ / iScale_; x < iMaxX_ / iScale_; x += 0.01) {
        addLine((x - 0.01) * iScale_ , mValues[x - 0.01] * iScale_, x * iScale_, mValues[x] * iScale_);
    }
}

void GraphGraphicsScene::DrawAxis() {
    if (iMinX_ > 0) { //draws x axis if view showing scene to the right of origin
        yAxis_.setLine(iMinX_, iMinY_, iMinX_, iMaxY_);
        removeItem(&yAxis_);
        addItem(&yAxis_);
    } else if (iMaxX_ < 0) { //draws x axis if view showing scene to the left of origin
        yAxis_.setLine(iMaxX_, iMinY_, iMaxX_, iMaxY_);
        removeItem(&yAxis_);
        addItem(&yAxis_);
    } else if (iMinX_ < 0 < iMaxX_) { //draws x axis if x = 0 is currently on screen
        yAxis_.setLine(0, iMinY_, 0, iMaxY_);
        removeItem(&yAxis_);
        addItem(&yAxis_);
    }

    if (iMinY_ > 0) { //draws y axis if view showing scene below origin
        xAxis_.setLine(iMinX_, iMinY_, iMaxX_, iMinY_);
        removeItem(&xAxis_);
        addItem(&xAxis_);
    } else if (iMaxY_ < 0) { //draws y axis if view showing scene above origin
        xAxis_.setLine(iMinX_, iMaxY_, iMaxX_, iMaxY_);
        removeItem(&xAxis_);
        addItem(&xAxis_);
    } else if (iMinY_ < 0 < iMaxY_) { //draws y axis if y = 0 is currently on screen
        xAxis_.setLine(iMinX_, 0, iMaxX_, 0);
        removeItem(&xAxis_);
        addItem(&xAxis_);
    }
}

void GraphGraphicsScene::MoveScene(int newX, int newY) {
    view.setSceneRect(newX, newY, height_, width_);

    DrawGrid(iScale_);
}

long GraphGraphicsScene::tick() {
    iCurrentTick ++;

    xOffset_ = -1; yOffset_ = -1;

    iMinX_ += xOffset_;
    iMinY_ += yOffset_;

    iMaxX_ = iMinX_ + height_;
    iMaxY_ = iMinY_ + width_;

    MoveScene(iMinX_, iMinY_);

    if (iCurrentTick % 30 == 0) {
        DrawGrid(20);
    }

    DrawAxis();
}
