#include "model/Game.h"
<<<<<<< HEAD
#include "CSVReader.cpp"
=======
#include "FileReader.cpp"
>>>>>>> main

int main(int argc, char** argv) {
    Game g;
    readCSV();
    g.init();
    //readFile(g.getMap());
    g.get_map()->show();
    g.play();
    g.clean();
    return 0;
}
