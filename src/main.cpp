#include <iostream>
#include "model/Game.h"
#include "CSVReader.cpp"

int main() {
    Game g;
    readCSV();
    g.play();
    return 0;
}
