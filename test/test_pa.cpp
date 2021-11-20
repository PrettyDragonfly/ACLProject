#include <iostream>
#include "../src/model/entities/Bomb.h"
#include "../src/model/map/Map.h"
#include "../src/model/World.h"

int main() {
    World w;
    Map* m = w.get_map();
    Bomb b(5, 5, m);
    std::cout << "ntm" << endl;
    int taille = (w.get_tab_bomb())[0]->get_health();
    std::cout << taille << endl;
    w.add_bomb(&b);
    //Bomb** bom = w.init_tab(bom);
    w.printTab(w.get_tab_bomb());
    //m->show();
}
