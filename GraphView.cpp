//
// Created by Josh on 22/06/2016.
//

#include "GraphView.h"


void GraphView::wheelEvent(QWheelEvent *event) {
    graph->iScale_ ++;
}
