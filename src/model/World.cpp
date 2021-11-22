#include "World.h"
#include "entities/Player.h"
#include <iostream>

World::World() {
    //std::cout << "World constructor called\n";
    map = new Map();
    player = new Player(1, 1, 10, this->map);
    Bomb **tab_bomb;
    init_tab(tab_bomb);
}

/**
 * @brief Update function for the world
 */
void World::update() {

}

/**
 * Player getter
 * @return player
 */
Entity* World::get_player() const{
    return player;
}

World::~World() {
    std::cout << "World destructor called\n";
    delete player;
    free_tab(tab_bomb); 
}

Map* World::get_map() const{
    return map;
}


Bomb**World::free_tab(Bomb** b) {
    for (int i = 0; i < 50; i++) {
        free(b[i]);
    }
    free(b);
}

Bomb**World::init_tab(Bomb** tab) {
    //Allocation dynamique du tableau
    tab_bomb = (Bomb**) malloc(50 * sizeof(Bomb*));

    for (int i = 0; i < 50; i++) {
        tab_bomb[i] = (Bomb*) malloc(sizeof(Bomb));
        if(tab_bomb[i] == NULL){  
            for(i=i-1 ; i >= 0 ; i--) 
                 free(tab_bomb[i]);
            std::cout << "Erreur allocation";
            exit(EXIT_FAILURE);
        }
    }

    //Initialisation du tableau
    for (int i = 0; i < 50; i++) {
        //std::cout << &(tab[i]) << endl;
        tab_bomb[i]->set_health(0);
        tab_bomb[i]->set_position(0, 0);
        tab_bomb[i]->setTime(0);
        tab_bomb[i]->setSize(0);
        //std::cout << tab[i]->get_health() << endl;
    }
    return tab;
}

Bomb** World::get_tab_bomb() const{
    return tab_bomb;
}

//Fonction pour afficher le tableau de bombes
void World::printTab(Bomb** tab) {
   // Bomb** tab = tab_bomb;
    int taille = tab[0]->get_health(); //on met la taille ici 

    if (taille == 0) std::cout << "Tableau vide" << endl; 

    for(int i = 1; i <= taille; i++) {
        int x_bombe = tab[i]->get_x_position();
        int y_bombe = tab[i]->get_y_position();
        float time = tab[i]->getTime();

        std::cout << x_bombe << " " << y_bombe << " " << time << endl;
    }
}


bool World::tab_vide() {
    if (tab_bomb[0]->get_health() == 0) return true;
    else return false;
}

//Fonction pour ajouter une bombe (l'ajoute au tableau accessoirement)
void World::add_bomb(int x, int y, int time, int size) {
    //std::cout << "add_bomb" << endl;
    //std::cout << tab_bomb << endl;
    int taille = (tab_bomb[0]->get_health())+1; //on recupere l'indice d'insertion
    //std::cout << "ouioui" << endl;
    tab_bomb[0]->set_health(taille);
    tab_bomb[taille]->set_position(x, y);
    tab_bomb[taille]->setTime(time);
    tab_bomb[taille]->setSize(size);
}

void World::add_bomb(Bomb* b) {
    
   // std::cout << tab_bomb << endl;
    int taille = tab_bomb[0]->get_health()+1; //on recupere l'indice d'insertion
    //std::cout << taille << endl;
    tab_bomb[0]->set_health(taille);
    //std::cout << "add_bomb" << endl;
    tab_bomb[taille]->set_health(b->get_health());
    tab_bomb[taille]->set_position(b->get_x_position(), b->get_y_position());
    tab_bomb[taille]->setSize(b->getSize());
    tab_bomb[taille]->setTime(b->getTime());
}

//Fonction qui commande l'explosion d'une bombe
void World::explode(int indice) {
    //isHurtbyaBomb()  -> infliger degats entity
    //Break()          -> casser les murs sur le trajet de l'explosion de la bombe
    
    int taille = tab_bomb[0]->get_health();
    if (taille == indice) { 
        //il s'agit de la dernière bombe du tableau, on décrémente
        std::cout << taille << endl;
        tab_bomb[0]->set_health(taille-1);
    } else {
        //on met la dernière bombe à la place de celle qui a explosé
        int x_last_bomb = tab_bomb[taille]->get_x_position();
        int y_last_bomb = tab_bomb[taille]->get_y_position();

        tab_bomb[0]->set_health(taille-1);
        tab_bomb[indice]->set_position(x_last_bomb, y_last_bomb);
        tab_bomb[indice]->setTime(tab_bomb[taille]->getTime());
        //pour l'instant x,y et time doivent suffire
    }
}

//Fonction qui verifie si une bombe doit exploser
void World::check_bomb() {
    //gerer sortie de case du perso lorsqu'il y'a une bombe pour ne pas y revenir ?

    int taille = tab_bomb[0]->get_health();
    //le temps d'une bombe est ecoulée on la fait péter
    for (int i = 1; i <= taille; i++) {
        float unite_temps = 0.1;

        if (tab_bomb[i]->getTime() <= 0) { 
            explode(i);
        }
        //enlever une unité de temps à la bombe
        float time = tab_bomb[i]->getTime();
        tab_bomb[i]->setTime(time-unite_temps);
    }
}

//Fonction qui permet de poser une bombe (ajout au tableau)
//Pour l'instant pas bloquant pour déplacement sur bombe
void World::pose_bomb(char c) {
    std::cout << "Bombe posée\n";
    if (c == 'B') {
        int x = player->get_x_position();
        int y = player->get_y_position();
        map->setTile(x, y, 'B');
        add_bomb(x, y, 3, 5);
    }
    
}