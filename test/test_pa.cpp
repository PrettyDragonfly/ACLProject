#include <iostream>
#include "../src/model/entities/Bomb.h"
#include "../src/model/map/Map.h"
#include "../src/model/World.h"

int main() {
    World w;
    Map* m = w.get_map();
    //Création bombes
    Bomb b(5, 5, m, 3, 5);
    Bomb bb(2, 2, m, 3, 6);

    int taille = (w.get_tab_bomb())[0]->get_health();
    std::cout << taille << endl;
    
    //Ajout bombes
    w.add_bomb(&b);
    w.add_bomb(&bb);
    //w.add_bomb(&bb);

    //Récupération tableau de bombes
    Bomb** t = w.get_tab_bomb();

    //Affichage
    //w.printTab(t);
    //w.printTab(w.get_tab_bomb());
    //m->show();

    

    w.printTab(t);

    Bomb a(3, 3, m, 3, 4);
    Bomb aa(4, 4, m, 3, 20);
    Bomb aaa(5, 5, m, 3, 6);
    Bomb aaaa(6, 6, m, 3, 6);

    w.add_bomb(&a);
    w.add_bomb(&aa);
    w.add_bomb(&aaa);
    w.add_bomb(&aaaa);

    int val = 1;
    while (val == 1) {
        //std::cout << "val : " << val << endl;
        w.check_bomb();
        w.printTab(t);
        if (w.tab_vide()) val = 0;
        //std::cout << "val : " << val << endl;
    }
}
