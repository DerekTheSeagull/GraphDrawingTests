//
// Created by Josh aka Bae on 27/04/2016.
//

#ifndef GRAPHDRAWINGTESTS_GRAPHGRAPHICSSCENE_H
#define GRAPHDRAWINGTESTS_GRAPHGRAPHICSSCENE_H

#include <iostream>
#include <QtWidgets/qgraphicsview.h>
#include <QtWidgets/qgraphicsitem.h>
#include <QtCore/qtimer.h>

using namespace std;


class GraphGraphicsScene : public QGraphicsScene {
    Q_OBJECT

public:
    GraphGraphicsScene(int w, int h);

    QGraphicsView view;

public slots:
    long tick();

private:
    void DrawAxis();
    void DrawGrid(int scale); //this is only called when it's needed i.e. not every tick only when the scale or the scene position has moved.
    void MoveScene(int newX, int newY); //moves the top left hand corner of the scene to the specified position.

    int iScale = 5;

    vector<QGraphicsLineItem *> GridLines;

    int iMinY_;
    int iMinX_;
    int iMaxY_;
    int iMaxX_;

    int width_;
    int height_;

    int xOffset_ = 0;
    int yOffset_ = 0;

    QPen AxisPen;
    QPen GridPen;

    QGraphicsLineItem yAxis_;
    QGraphicsLineItem xAxis_;

    QGraphicsLineItem GridLine_;

    QTimer *timer = new QTimer();
};


#endif //GRAPHDRAWINGTESTS_GRAPHGRAPHICSSCENE_H
