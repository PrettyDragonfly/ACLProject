#include "model/Game.h"

int main(int argc, char** argv) {
    Game g;
    g.init();
    g.get_map()->show();
    g.play();
    g.clean();
    return 0;
}
