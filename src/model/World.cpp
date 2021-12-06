#include "World.h"
#include "entities/Player.h"
#include "entities/Enemy.h"
#include <iostream>

World::World() {
    //std::cout << "World constructor called\n";
    map = new Map();
    player = new Player(1, 1, 10, this->map);
    enemy = new Enemy(5,5,5, this->map);

    //Creation des tableaux d'éléments
    Bomb **tab_bomb = nullptr;
    Entity **tab_entite = nullptr;

    //Initialisation des tableaux
    init_tab(tab_bomb);
    init_entite(tab_entite);
    //Ajout des entités dans le tableau
    add_entite(player);
    add_entite(enemy);
}

/**
 * @brief Update function for the world
 */
void World::update() {
    check_bomb();
    check_entite();
}

/**
 * Player getter
 * @return player
 */
Entity* World::get_player() const{
    return player;
}

Enemy* World::get_enemy() const {
    return enemy;
}

World::~World() {
    std::cout << "World destructor called\n";
    delete player;
    free_tab(tab_bomb); 
    free_entite(tab_entite);
}

Map* World::get_map() const{
    return map;
}

//######################################################
//################# TABLEAU D'ENTITES ##################
//######################################################
Entity** World::get_tab_entite() const {
    return tab_entite;
}


//Fonctions qui permettent de gérer tableau d'entités
void World::free_entite(Entity** e) {
    for (int i = 0; i < 50; i++) {
        free(e[i]);
    }
    free(e);
}

Entity**World::init_entite(Entity** tab) {
    //Allocation dynamique du tableau
    tab_entite = (Entity**) malloc(50 * sizeof(Entity*));

    for (int i = 0; i < 50; i++) {
        tab_entite[i] = (Entity*) malloc(sizeof(Entity));
        if(tab_entite[i] == NULL){  
            for(i=i-1 ; i >= 0 ; i--) 
                 free(tab_entite[i]);
            std::cout << "Erreur allocation";
            exit(EXIT_FAILURE);
        }
    }

    //Initialisation du tableau
    for (int i = 0; i < 50; i++) {
        //std::cout << &(tab[i]) << endl;
        tab_entite[i]->set_health(0);
        tab_entite[i]->set_position(0, 0);
        tab_entite[i]->set_value(0);
        //std::cout << tab[i]->get_health() << endl;
    }
    return tab;
}

//Fonction pour ajouter une bombe (l'ajoute au tableau accessoirement)
void World::add_entite(int x, int y, int life, int value) {
    //std::cout << "add_bomb" << endl;
    //std::cout << tab_bomb << endl;
    int taille = (tab_entite[0]->get_health())+1; //on recupere l'indice d'insertion
    //std::cout << "ouioui" << endl;
    tab_entite[0]->set_health(taille);
    tab_entite[taille]->set_position(x, y);
    tab_entite[taille]->set_health(life);
    tab_entite[taille]->set_value(value);
}

void World::add_entite(Entity* b) {
    
   // std::cout << tab_bomb << endl;
    int taille = tab_entite[0]->get_health()+1; //on recupere l'indice d'insertion
    //std::cout << taille << endl;
    tab_entite[0]->set_health(taille);
    //std::cout << "add_bomb" << endl;
    tab_entite[taille]->set_health(b->get_health());
    tab_entite[taille]->set_position(b->get_x_position(), b->get_y_position());
    tab_entite[taille]->set_value(b->get_value());
}

//Fonction qui verifie si un joueur est mort
void World::check_entite() {
    int taille = tab_entite[0]->get_health();
    //le temps d'une bombe est ecoulée on la fait péter
    for (int i = 1; i <= taille; i++) {

        if (tab_entite[i]->get_health() <= 0) { 
            //une unité est morte
            //si c'est le perso fin de partie
            //si c'est un monstre
            //std::cout << "valeur : " << tab_entite[i]->get_value() << endl;
            if(tab_entite[i]->get_value() == 2) { //on le supprime du tableau
                if (taille == i){
                    //il s'agit du dernier élément du tableau, on décrémente
                    //ajout de points ?
                    tab_entite[0]->set_health(taille - 1);
                }
                else{
                    //on met le dernier élément à la place de celle qui a explosé
                    int x_last = tab_entite[taille]->get_x_position();
                    int y_last = tab_entite[taille]->get_y_position();
                    int life = tab_entite[taille]->get_health();
                    int valeur = tab_entite[taille]->get_value();

                    tab_entite[0]->set_health(taille - 1);
                    tab_entite[i]->set_health(life);
                    tab_entite[i]->set_position(x_last, y_last);
                    tab_entite[i]->set_value(valeur);
                }
            }
        }
    }
}

void World::print(Entity** tab){
    int taille = tab[0]->get_health(); //on met la taille ici 

    if (taille == 0) std::cout << "Tableau vide" << endl; 

    for(int i = 1; i <= taille; i++) {
        int x_bombe = tab[i]->get_x_position();
        int y_bombe = tab[i]->get_y_position();
        int vie = tab[i]->get_health();
        int valeur = tab[i]->get_value();

        std::cout << x_bombe << " " << y_bombe << " " << vie << " " << "(" << valeur << ")" << endl;
    }
}

//Fonction qui test si le tableau est vide
bool World::tab_entite_vide() {
    if (tab_entite[0]->get_health() == 0) return true;
    else return false;
}



//###############################################################
//###################### TABLEAU DE BOMBES ######################
//###############################################################
// Fonctions qui permettent de gérer tableau de bombes
void World::free_tab(Bomb** b) {
    for (int i = 0; i < 50; i++) {
        free(b[i]);
    }
    free(b);
}

//Initialisation et création du tableau
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
        tab_bomb[i]->set_health(0);
        tab_bomb[i]->set_position(0, 0);
        tab_bomb[i]->setTime(0);
        tab_bomb[i]->setSize(0);
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

//Fonction qui test si le tableau est vide
bool World::tab_vide() {
    if (tab_bomb[0]->get_health() == 0) return true;
    else return false;
}

//Fonction pour ajouter une bombe (l'ajoute au tableau accessoirement)
void World::add_bomb(int x, int y, int time, int size) {
    int taille = (tab_bomb[0]->get_health())+1; //on recupere l'indice d'insertion
    tab_bomb[0]->set_health(taille);
    tab_bomb[taille]->set_position(x, y);
    tab_bomb[taille]->setTime(time);
    tab_bomb[taille]->setSize(size);
}

void World::add_bomb(Bomb* b) {

    int taille = tab_bomb[0]->get_health()+1; //on recupere l'indice d'insertion
    tab_bomb[0]->set_health(taille);
    tab_bomb[taille]->set_health(b->get_health());
    tab_bomb[taille]->set_position(b->get_x_position(), b->get_y_position());
    tab_bomb[taille]->setSize(b->getSize());
    tab_bomb[taille]->setTime(b->getTime());
}

//Fonction qui commande l'explosion d'une bombe
void World::explode(int indice) {
    //position de la bombe
    int x = tab_bomb[indice]->get_x_position();
    int y = tab_bomb[indice]->get_y_position();
    int portee = tab_bomb[indice]->getSize();
    
    //isHurtbyaBomb()  -> infliger degats entity
    //Break()          -> casser les murs sur le trajet de l'explosion de la bombe
    

    //il faut detecter la taille d'explosion modulo les murs incassables (pas de degats au dela)
    //on récupère la position actuelle de la bombe
    int max_explosion_x = tab_bomb[indice]->get_x_position();
    int max_explosion_y = tab_bomb[indice]->get_y_position();
    int min_explosion_x = tab_bomb[indice]->get_x_position();
    int min_explosion_y = tab_bomb[indice]->get_y_position();


    //on cherche si de la position actuelle jusqu'à la taille de l'explosion il y'a un mur incassable
    Tile* tuile = nullptr;

    tuile = map->get_tile(x+1, y);
    while(tuile != nullptr && !(tuile->is_ubreakable_wall())) {
        max_explosion_x += 1;
        tuile = map->get_tile(max_explosion_x+1, y);
    }

    tuile = map->get_tile(x-1, y);
    while(tuile != nullptr && !(tuile->is_ubreakable_wall())) {
        min_explosion_x -= 1;
        tuile = map->get_tile(min_explosion_x-1, y);
    }

    tuile = map->get_tile(x, y+1);
    while(tuile != nullptr && !(tuile->is_ubreakable_wall())) {
        max_explosion_y += 1;
        tuile = map->get_tile(x, max_explosion_y+1);
    }

    tuile = map->get_tile(x, y-1);
    while(tuile != nullptr && !(tuile->is_ubreakable_wall())) {
        min_explosion_y -= 1;
        tuile = map->get_tile(x, min_explosion_y-1);
    }
    //à la suite des while on a les max et min de l'explosion tant qu'elle ne recontre rien d'incassable

    //INFLIGER LES DEGATS
    for(int i = x - portee; i <= x + portee; i++) { 
        //si on croise une tile cassable on la transforme en floor
        tuile = map->get_tile(i, y);
        if (i <= max_explosion_x && i >= min_explosion_x && !(tuile->is_ubreakable_wall())) {
            //std::cout << i << " " << y << endl;
            map->setTile(i, y, '0');
        }
        //on parcourt le tableau d'entités
        for (int j = 1; j <= tab_entite[0]->get_health(); j++) {
            if (tab_entite[j]->get_x_position() == i && tab_entite[j]->get_y_position() == y) {
                int vie = tab_entite[j]->get_health();
                tab_entite[j]->set_health(vie-1);
            }
        }
    }

    //boucle sur la colonne
    for(int i = y - portee; i <= y + portee; i++) { 
        tuile = map->get_tile(x, i);
        //si on croise une tile cassable on la transforme en floor
        if (i <= max_explosion_y && i >= min_explosion_y && !(tuile->is_ubreakable_wall())) {
            //std::cout << x << " " << i << endl;
            map->setTile(x, y, '0');
        }
        //on parcourt le tableau d'entités
        for (int j = 1; j <= tab_entite[0]->get_health(); j++) {
            if (tab_entite[j]->get_x_position() == x && tab_entite[j]->get_y_position() == i) {
                int vie = tab_entite[j]->get_health();
                tab_entite[j]->set_health(vie-1);
            }
        }
    }

    //Supprimer la bombe du tableau
    int taille = tab_bomb[0]->get_health();
    if (taille == indice) { 
        //il s'agit de la dernière bombe du tableau, on décrémente
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
        add_bomb(x, y, 2, 2);
    }
    
}