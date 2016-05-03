//
// Created by Josh aka Bae on 27/04/2016.
//

#ifndef GRAPHDRAWINGTESTS_GRAPHGRAPHICSSCENE_H
#define GRAPHDRAWINGTESTS_GRAPHGRAPHICSSCENE_H

#include <iostream>
#include <QtWidgets/qgraphicsview.h>
#include <QtWidgets/qgraphicsitem.h>
#include <QtCore/qtimer.h>


class GraphGraphicsScene : public QGraphicsScene {
    Q_OBJECT

public:
    GraphGraphicsScene(int w, int h);

    QGraphicsView view;

public slots:
    long tick();

private:
    void drawAxis();

    int iScale = 5;

    int iMinY_;
    int iMinX_;
    int iMaxY_;
    int iMaxX_;

    int width_;
    int height_;

    int xOffset = 0;
    int yOffset = 0;

    QPen pen;

    QGraphicsLineItem yAxis_;
    QGraphicsLineItem xAxis_;

    QTimer *timer = new QTimer();
};


#endif //GRAPHDRAWINGTESTS_GRAPHGRAPHICSSCENE_H
