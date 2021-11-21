//
// Created by thifl on 10/11/2021.
//

#include "Game_View.h"
#include <iostream>

const int WIN_H = 640;
const int WIN_W = 640;
const short TILE_BORDER = 16;
const short TILE_SIZE = 3;
const short RECT_SIZE = TILE_SIZE;
const char* filename = "src/ressources/PixelPackTOPDOWN1BIT-export.bmp";

//Tous ces objets devraient etre des attributs de Game_View mais pour une raison obscure, une segfault apparait si on met
// un seul de ces objets en attribut
typedef struct obj {
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture *tileset;
    SDL_Rect *tabtile;
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
    //Creation des rectangles
    o.tabtile = new SDL_Rect[RECT_SIZE];
    o.tabtile[0] = {0,16, TILE_BORDER, TILE_BORDER};
    o.tabtile[1] = {80, 0, TILE_BORDER, TILE_BORDER};
}

void Game_View::refresh(const Game& game){
    SDL_RenderClear(o.renderer);
    show_map(game);
    //show_player();
    SDL_RenderPresent(o.renderer);
}

void Game_View::show_player() {
    /**
    SDL_Rect src = {0,16,16,16};
    SDL_Rect dst = {0, 0, 16, 16};
    SDL_RenderCopy(o.renderer, o.tileset, &src, &dst);
    **/
}

void Game_View::show_map(const Game& game) {
    std::cout << "pout";
    fflush(stdout);
    int i,j;
    Map* map = game.get_map();
    SDL_Rect Rect_dest = {0,0,TILE_BORDER*4,TILE_BORDER*4};
    for(i=0;i<map->get_size();i++){
        for(j=0;j<map->get_size();j++){
            Rect_dest.x = i*TILE_BORDER*4;
            Rect_dest.y = j*TILE_BORDER*4;
            Tile* t = map->get_tile(i,j);
            if (t == nullptr){
                std::cout << "pointeur null\n";
                exit(EXIT_FAILURE);
            }
            if(t->is_floor()){
                SDL_RenderCopy(o.renderer,o.tileset,&(o.tabtile[0]),&Rect_dest);
            }
            else{
                SDL_RenderCopy(o.renderer,o.tileset,&(o.tabtile[1]),&Rect_dest);
            }
        }
    }
}

