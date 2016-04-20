//
// Created by Josh aka Bae on 21/03/2016.
//

//TODO Add functions to draw graphs, add a grid and axes labels
//TODO Have the axes move when the graph is moved?
//TODO Use a timer_ for all updates to graph (If still laggy maybe 100 lines added per tick?)

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
    bool DrawGraph(string sEquation);

    QGraphicsView view;

public slots:
    void tick();

private:
    bool DrawAxes();
    bool AddGrid();
    bool AddLabels();

    int height_;
    int width_;

    int viewX_ = -500;
    int viewY_ = -500;
    int scrollOffsetX_;
    int scrollOffsetY_;

    float currentMinX_;
    float currentMaxX_;
    float currentMinY_;
    float currentMaxY_;

    QPen axisPen_;
    QGraphicsLineItem xAxis_;
    QGraphicsLineItem yAxis_;
    QTimer timer_;
};


#endif //GRAPHDRAWINGTESTS_GRAPHGRAPHICSSCENE_H
