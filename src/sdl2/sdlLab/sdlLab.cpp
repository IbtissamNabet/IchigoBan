#include <cassert>
#include <time.h>
#include "sdlLab.h"
#include <stdlib.h>

#include <iostream>
using namespace std;

const int TAILLE_SPRITE = 32;

SdlLab::SdlLab (const Labyrinthe & terrain) : lab(terrain) {
    // Initialisation de la SDL

    ///ouvrir le module des fonctions videos 
    SDL_Init(SDL_INIT_VIDEO);
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
    if( !(IMG_Init(imgFlags) & imgFlags)) {
        cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

	int dimx, dimy;
	dimx = lab.getDim().getLargeur();
	dimy = jeu.getDim().getHauteur();
	dimx = dimx * TAILLE_SPRITE;
	dimy = dimy * TAILLE_SPRITE;

    // Creation de la fenetre
    window = SDL_CreateWindow("Pacman", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, dimx, dimy, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (window == nullptr) {
        cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << endl; 
        SDL_Quit(); 
        exit(1);
    }

    //
    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);

    // IMAGES
    im_mur.loadFromFile("data/mur.png",renderer);
    im_vide.loadFromFile("data/vide.png",renderer);
    im_empcible.loadFromFile("data/empcible.png",renderer);

}

SdlLab::~SdlLab () {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void SdlLab::sdlLabAfficher () {
	//Remplir l'écran de blanc
    SDL_SetRenderDrawColor(renderer, 230, 240, 255, 255);
    SDL_RenderClear(renderer);

    Position p;
	int x,y;


    // Afficher les murs, les emplacements cibles et les emplacements vides
	for (x=0;x<lab.getDim().getLargeur();++x){
		for (y=0;y<lab.getDim().getHauteur();++y){
            p(x,y);
			if (lab.getTypeLab(p)=='#')
				im_mur.draw(renderer,x*TAILLE_SPRITE,y*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);
			else if (lab.getTypeLab(p)=='.')
				im_vide.draw(renderer,x*TAILLE_SPRITE,y*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);
            else if (lab.getTypeLab(p)=='*')
            	im_empcible.draw(renderer,x*TAILLE_SPRITE,y*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);
        }
    }


    // Ecrire un titre par dessus
    SDL_Rect positionTitre;
    positionTitre.x = 270;positionTitre.y = 49;positionTitre.w = 100;positionTitre.h = 30;
    SDL_RenderCopy(renderer,font_im.getTexture(),nullptr,&positionTitre);

}

void SdlLab::sdlLabBoucle(){
    SDL_Event events;
	bool quit = false;
	while (!quit) {
		while (SDL_PollEvent(&events)) {        
			if (events.type == SDL_QUIT) quit = true;      
        }  

		// on affiche le jeu sur le buffer cach�
		sdlLabAfficher();

		// on permute les deux buffers 
        SDL_RenderPresent(renderer); 
    }
}

