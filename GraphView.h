//
// Created by Josh on 22/06/2016.
//

#ifndef GRAPHDRAWINGTESTS_GRAPHVIEW_H
#define GRAPHDRAWINGTESTS_GRAPHVIEW_H


#include <QtWidgets/QGraphicsView>

class GraphView : public QGraphicsView {
public:
    void wheelEvent(QWheelEvent *event);

    GraphGraphicsScene *graph;
};


#endif //GRAPHDRAWINGTESTS_GRAPHVIEW_H
