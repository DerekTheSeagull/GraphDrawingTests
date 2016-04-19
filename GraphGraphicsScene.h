//
// Created by Josh aka Bae on 21/03/2016.
//

//TODO Add functions to draw graphs, add axes, add a grid and axes labels
//TODO Have the axes move when the graph is moved?
//TODO Use a timer for all updates to graph (If still laggy maybe 100 lines added per tick?)

#ifndef GRAPHDRAWINGTESTS_GRAPHGRAPHICSSCENE_H
#define GRAPHDRAWINGTESTS_GRAPHGRAPHICSSCENE_H

#include <QtWidgets/QGraphicsScene>
#include <QtWidgets/QGraphicsView>
#include <QtCore/QTimer>
#include <QtWidgets/QGraphicsLineItem>

using namespace std;

class GraphGraphicsScene : public QGraphicsScene {
    Q_OBJECT


public:
    GraphGraphicsScene(int width, int height);

    QGraphicsView view;

public slots:
    void tick();

private:
    bool DrawGraph(string sEquation);
    bool DrawAxes();
    bool AddGrid();
    bool AddLabels();

    int height_;
    int width_;

    float currentMinX;
    float currentMaxX;
    float currentMinY;
    float currentMaxY;

    QPen axisPen;
    QPoint bottomRight;
    QGraphicsLineItem xAxis;
    QGraphicsLineItem yAxis;
    QTimer timer;
};


#endif //GRAPHDRAWINGTESTS_GRAPHGRAPHICSSCENE_H
