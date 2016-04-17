#include <iostream>
#include <QtWidgets/qapplication.h>
#include "ConvertEquation.h"
#include "MainWindow.h"

using namespace std;

int main() {
    initialiseMap();

    cout << ConvertEquation("3x+2x(3x+3)y");
    return 0;
}