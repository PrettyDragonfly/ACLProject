#include "../src/model/World.h"
#include "../src/model/entities/Bomb.h"
#include "../src/model/entities/Player.h"

int main(int argc, char** argv) {
    World w;

    Bomb b = Bomb(5, 5, w.get_map(), 3, 4);
    w.add_bomb(&b);

    Player p = Player(3, 3, 3, w.get_map());
    Player p1 = Player(4, 4, 4, w.get_map());
    Player p2 = Player(5, 5, 5, w.get_map());
    Player p3 = Player(6, 6, 6, w.get_map());

    w.add_entite(&p);
    w.add_entite(&p1);
    w.add_entite(&p2);
    w.add_entite(&p3);


    Entity** tableau = w.get_tab_entite();
    w.print(tableau);

    while(!w.tab_entite_vide()) {
        w.print(tableau);
        int taille = tableau[0]->get_health();
        for(int i = 1; i <= taille; i++) {
            int life = tableau[i]->get_health();
            tableau[i]->set_health(life-1);
            w.check_entite();
        }
    }
}