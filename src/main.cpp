#include "model/Game.h"
#include "ressources/FileReader.cpp"

int main(int argc, char** argv) {
    Game g;
    g.init();
    //readFile(g.getMap());
    g.get_map()->show();
    g.play();
    g.clean();
    return 0;
}
