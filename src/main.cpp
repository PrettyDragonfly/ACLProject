#include <iostream>
#include "model/Game.h"
#include "FileReader.cpp"

int main() {
    Game g;
    readFile();
    g.play();
    return 0;
}
