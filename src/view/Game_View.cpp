//
// Created by thifl on 10/11/2021.
//

#include "Game_View.h"
#include <iostream>

const int BAN_H = 64;
const int WIN_H = 640;
const int WIN_W = 640;
const short TILE_BORDER = 16;
const short TILE_SIZE = 3;
const short RECT_SIZE = TILE_SIZE + 2;
const short BOMB_SIZE = 50;
const char* filename = "src/ressources/PixelPackTOPDOWN1BIT-export.bmp";
const char* playerfile = "src/ressources/HEROS_PixelPackTOPDOWN1BIT_Dog Idle D.bmp";
const char* bombfile = "src/ressources/item1BIT_bomb-export.bmp";
const char* enemyfile = "src/ressources/enemy.bmp";
const char* breakwall = "src/ressources/breakwall.bmp";
const char* heart = "src/ressources/heart.bmp";
const char* end1 = "src/ressources/go_1.bmp";
const char* end2 = "src/ressources/go_2.bmp";

//Tous ces objets devraient etre des attributs de Game_View mais pour une raison obscure, une segfault apparait si on met
// un seul de ces objets en attribut
typedef struct obj {
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture *tileset;
    SDL_Texture *player;
    SDL_Texture *enemy;
    SDL_Texture *bomb;
    SDL_Texture *wall;
    SDL_Texture *heart;
    SDL_Texture *badend;
    SDL_Texture *goodend;
    SDL_Rect *tabtile;
    int cpt;
} obj_t;
obj_t o {nullptr, nullptr, nullptr};

void Game_View::show(const Game &game) {
    game.show();
}

void Game_View::init() {
    //Initialisation SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0 )
    {
        fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        exit(EXIT_FAILURE);
    }

    //Creation fenetre + rendu
    o.window = SDL_CreateWindow("Bomberman",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,WIN_W,WIN_H,SDL_WINDOW_SHOWN);
    o.renderer = SDL_CreateRenderer(o.window, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(o.renderer, 0, 0, 0, 255);

    //Creation du tileset
    SDL_Surface* tmp = SDL_LoadBMP(filename);
    o.tileset = SDL_CreateTextureFromSurface(o.renderer, tmp);
    SDL_FreeSurface(tmp);

    //Creation du player(
    tmp = SDL_LoadBMP(playerfile);
    Uint32 colorkey = SDL_MapRGB( tmp->format, 192, 255, 238); //Constantes poru la transparence
    SDL_SetColorKey(tmp, SDL_TRUE,colorkey);
    o.player = SDL_CreateTextureFromSurface(o.renderer, tmp);
    SDL_FreeSurface(tmp);

    //Creation de la bombe
    tmp = SDL_LoadBMP(bombfile);
    o.bomb = SDL_CreateTextureFromSurface(o.renderer, tmp);
    SDL_FreeSurface(tmp);

    //Creation du wall
    tmp = SDL_LoadBMP(breakwall);
    o.wall = SDL_CreateTextureFromSurface(o.renderer, tmp);
    SDL_FreeSurface(tmp);

    //Creation des rectangles
    o.tabtile = new SDL_Rect[RECT_SIZE];
    o.tabtile[0] = {0,16, TILE_BORDER, TILE_BORDER};
    o.tabtile[1] = {80, 0, TILE_BORDER, TILE_BORDER};
    //Tile [2] = Tile du breakable wall
    o.tabtile[3] = {0,0,TILE_BORDER, TILE_BORDER};

    //Creation de l'ennemi
    tmp = SDL_LoadBMP(enemyfile);
    colorkey = SDL_MapRGB( tmp->format, 255, 0, 0); //Constantes poru la transparence
    SDL_SetColorKey(tmp, SDL_TRUE,colorkey);
    o.enemy = SDL_CreateTextureFromSurface(o.renderer, tmp);
    SDL_FreeSurface(tmp);

    //Coeur
    tmp = SDL_LoadBMP(heart);
    colorkey = SDL_MapRGB( tmp->format, 27, 0, 255); //Constantes poru la transparence
    SDL_SetColorKey(tmp, SDL_TRUE,colorkey);
    o.heart = SDL_CreateTextureFromSurface(o.renderer, tmp);
    SDL_FreeSurface(tmp);

    //Bad ending
    tmp = SDL_LoadBMP(end1);
    o.badend = SDL_CreateTextureFromSurface(o.renderer, tmp);
    SDL_FreeSurface(tmp);

    //Good ending
    tmp = SDL_LoadBMP(end2);
    o.goodend = SDL_CreateTextureFromSurface(o.renderer, tmp);
    SDL_FreeSurface(tmp);
}

void Game_View::refresh(const Game& game){
    SDL_RenderClear(o.renderer);
    show_map(game);
    show_bombs(game);
    show_player(game);
    show_enemy(game);
    show_hearts(game);
    SDL_RenderPresent(o.renderer);
}

void Game_View::show_player(const Game& game) {
    int x = game.get_player()->get_x_position();
    int y = game.get_player()->get_y_position();
    SDL_Rect Rect_dest = {0,0,TILE_BORDER*2,TILE_BORDER*2};
    Rect_dest.x = x*TILE_BORDER*2;
    Rect_dest.y = y*TILE_BORDER*2;
    SDL_RenderCopy(o.renderer,o.player,&(o.tabtile[3]),&Rect_dest);
}

void Game_View::show_enemy(const Game& game) {
    int x = game.get_enemy()->get_x_position();
    int y = game.get_enemy()->get_y_position();
    SDL_Rect Rect_dest = {0,0,TILE_BORDER*2,TILE_BORDER*2};
    Rect_dest.x = x*TILE_BORDER*2;
    Rect_dest.y = y*TILE_BORDER*2;
    SDL_RenderCopy(o.renderer,o.enemy,&(o.tabtile[3]),&Rect_dest);
}

void Game_View::show_map(const Game& game) {
    //std::cout << "pout";
    //fflush(stdout);
    int i,j;
    Map* map = game.get_map();
    SDL_Rect Rect_dest = {0,0,TILE_BORDER*2,TILE_BORDER*2};
    for(i=0;i<map->get_size();i++){
        for(j=0;j<map->get_size();j++){
            Rect_dest.x = i*TILE_BORDER*2;
            Rect_dest.y = j*TILE_BORDER*2;
            Tile* t = map->get_tile(i,j);
            if (t == nullptr){
                std::cout << "pointeur null\n";
                exit(EXIT_FAILURE);
            }
            if(t->is_floor()){
                SDL_RenderCopy(o.renderer,o.tileset,&(o.tabtile[0]),&Rect_dest);
            }
            else if(t->is_ubreakable_wall()){
                SDL_RenderCopy(o.renderer,o.tileset,&(o.tabtile[1]),&Rect_dest);
            }
            else{
                SDL_RenderCopy(o.renderer,o.wall, nullptr,&Rect_dest);
            }
        }
    }
}

void Game_View::show_bombs(const Game& game) {
    Bomb** tab = game.get_tab_bomb();

    int taille = tab[0]->get_health();

    if (taille > 0){
        for(int i = 1; i <= taille; i++) {
            int x = tab[i]->get_x_position();
            int y = tab[i]->get_y_position();
            SDL_Rect Rect_dest = {0,0,TILE_BORDER*2,TILE_BORDER*2};
            Rect_dest.x = x*TILE_BORDER*2;
            Rect_dest.y = y*TILE_BORDER*2;
            SDL_RenderCopy(o.renderer, o.bomb, &(o.tabtile[3]), &Rect_dest);
        }
    }
}

void Game_View::show_hearts(const Game& game){
    int h = game.get_player()->get_health();
    for (int i = 0; i < h; i++){
        SDL_Rect Rect_dest = {0,0,TILE_BORDER*2,TILE_BORDER*2};
        Rect_dest.x = i*TILE_BORDER*2;
        Rect_dest.y = 0;
        SDL_RenderCopy(o.renderer, o.heart, nullptr, &Rect_dest);
    }
}

void Game_View::show_badend() {
    SDL_RenderClear(o.renderer);
    SDL_RenderCopy(o.renderer, o.badend, NULL, NULL);
    SDL_RenderPresent(o.renderer);
    SDL_Delay(2000);
}

