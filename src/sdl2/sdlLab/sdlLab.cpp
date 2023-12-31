#include "Jeu.h"
#include <cassert>
#include <time.h>
#include <stdlib.h>
#include "sdlLab.h"
#include <iostream>

using namespace std;

const int TAILLE_SPRITE = 32;

Image::Image () : m_surface(nullptr), m_texture(nullptr), m_hasChanged(false) { }

Image::~Image() {
    if (m_texture != nullptr) {
        SDL_DestroyTexture(m_texture);
        m_texture = nullptr;
    }
    m_surface = nullptr;
    m_hasChanged = false;
}

void Image::loadFromFile (const char* filename, SDL_Renderer * renderer) {
    m_surface = IMG_Load(filename);
    if (m_surface == nullptr) 
    {
        string nfn = string("../") + filename;
        cout << "Error: cannot load "<< filename <<". Trying "<<nfn<<endl;
        m_surface = IMG_Load(nfn.c_str());
        if (m_surface == nullptr)

        {
            nfn = string("../") + nfn;
            m_surface = IMG_Load(nfn.c_str());
        }

    }

    if (m_surface == nullptr) 
    {
        cout<<"Error: cannot load "<< filename <<endl;
        SDL_Quit();
        exit(1);
    }

    SDL_Surface * surfaceCorrectPixelFormat = SDL_ConvertSurfaceFormat(m_surface,SDL_PIXELFORMAT_ARGB8888,0);
    SDL_FreeSurface(m_surface);
    m_surface = surfaceCorrectPixelFormat;

    m_texture = SDL_CreateTextureFromSurface(renderer,surfaceCorrectPixelFormat);
    if (m_texture == NULL) 
    {
        cout << "Error: problem to create the texture of "<< filename<< endl;
        SDL_Quit();
        exit(1);
    }

}

void Image::loadFromCurrentSurface (SDL_Renderer * renderer) {
    m_texture = SDL_CreateTextureFromSurface(renderer,m_surface);
    if (m_texture == nullptr) {
        cout << "Error: problem to create the texture from surface " << endl;
        SDL_Quit();
        exit(1);
    }

}

void Image::draw (SDL_Renderer * renderer, int x, int y, int w, int h) {
    int ok;
    SDL_Rect r;
    r.x = x;
    r.y = y;
    r.w = (w<0)?m_surface->w:w;
    r.h = (h<0)?m_surface->h:h;

    if (m_hasChanged) 
    {
        ok = SDL_UpdateTexture(m_texture,nullptr,m_surface->pixels,m_surface->pitch);
        assert(ok == 0);
        m_hasChanged = false;
    }

    ok = SDL_RenderCopy(renderer,m_texture,nullptr,&r);
    assert(ok == 0);

}

SDL_Texture * Image::getTexture() const {
    return m_texture;
}

void Image::setSurface(SDL_Surface * surf) {
    m_surface = surf;
}


SdlLab::SdlLab(){

    // Initialisation de la SDL, ouverture du module des fonctions videos 
    SDL_Init(SDL_INIT_VIDEO);
    if (SDL_Init(SDL_INIT_VIDEO) < 0) // SDL_INIT_EVERYTHING aussi
    {
        cout << endl
        << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << endl;
        SDL_Quit();
        exit(1);
    }
    else
    {
        SDL_Init(SDL_INIT_AUDIO); // initilisation de SDL2_mixer pour l'audio
        Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
        son = Mix_LoadMUS("data/son.mp3"); // chargement du fichier audio
        if (!son)
        {
            cout << "erreur de chargement du fichier audio : " << Mix_GetError() << endl;
            exit(1);
        }
        Mix_PlayMusic(son, -1); // lecture de la musique en boucle
    }


    int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;

    if( !(IMG_Init(imgFlags) & imgFlags)) 
    {
        cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << endl;
        SDL_Quit();
        exit(1);
    }
    jeu.setNiveau(0);
	int dimx, dimy;
	dimx = jeu.getNiveau().getLab().getDim().getLargeur();
	dimy = jeu.getNiveau().getLab().getDim().getHauteur();
    cout<<dimx<<" "<<dimy<<endl;
	dimx = dimx * TAILLE_SPRITE+5*TAILLE_SPRITE;
	dimy = dimy * TAILLE_SPRITE;

    // Creation de la fenetre
    window = SDL_CreateWindow("Ichigo'Ban", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, dimx, dimy, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

    if (window == nullptr) 
    {
        cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << endl; 
        SDL_Quit(); 
        exit(1);
    }

    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_SOFTWARE);


    // IMAGES
    im_mur.loadFromFile("data/mur.png",renderer);
    im_vide.loadFromFile("data/vide.png",renderer);
    im_empcible.loadFromFile("data/empcible.png",renderer);
    im_fraise.loadFromFile("data/fraise.png",renderer);
    im_gardien.loadFromFile("data/gardien.png",renderer);
    im_touches.loadFromFile("data/touches.png",renderer);

}

SdlLab::~SdlLab () {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    // Arrêt de la musique
    Mix_HaltMusic();
    // Libération de la mémoire allouée
    Mix_FreeMusic(son);
    Mix_CloseAudio(); 
}



void SdlLab::nouvellePartie() {

    SDL_SetRenderDrawColor(renderer, 230, 240, 255, 255);
    SDL_RenderClear(renderer);

    if(jeu.niv.getNum()==5) {
        im_victoire.loadFromFile("data/victoire.jpg",renderer);
        SDL_RenderClear(renderer);
        //recuperer la dimension de la fenetre 
        int larg;
        int haut;
        SDL_GetWindowSize(window,&larg,&haut);

        im_victoire.draw(renderer,0,0,larg,haut);
        SDL_RenderPresent(renderer);
        SDL_Delay(12000);
        SDL_DestroyRenderer(renderer); //on detruit le rendu actuel 
        SDL_DestroyWindow(window);
        SDL_Quit();
        exit(0);

    }

    else {
        jeu.setNiveau(jeu.niv.getNum()+1);
    }
}

void SdlLab::sdlLabAfficher () {

	//Remplir l'écran de blanc
    SDL_SetRenderDrawColor(renderer, 230, 240, 255, 255);
    SDL_RenderClear(renderer);

    Position p;
	int x,y;

    // Afficher les murs, les emplacements cibles et les emplacements vides
	for (x=0;x<jeu.getNiveau().getLab().getDim().getLargeur();++x) {
		for (y=0;y<jeu.getNiveau().getLab().getDim().getHauteur();++y) {
            p=Position(x,y);
			if (jeu.getNiveau().getLab().getTypeLab(p)==MUR)
				im_mur.draw(renderer,x*TAILLE_SPRITE,y*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);
			else if (jeu.getNiveau().getLab().getTypeLab(p)==VIDE)
				im_vide.draw(renderer,x*TAILLE_SPRITE,y*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);
            else if (jeu.getNiveau().getLab().getTypeLab(p)==EMPCIBLE)
            	im_empcible.draw(renderer,x*TAILLE_SPRITE,y*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);
        }
    }

    //Afficher le gardien
    x=jeu.getGardien().getPositionGardien().getPosX();
    y=jeu.getGardien().getPositionGardien().getPosY();
    im_gardien.draw(renderer,x*TAILLE_SPRITE,y*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);

    //Afficher les fraises
    for(int i=0; i<jeu.getNiveau().getNbFraises(); i++) {       
        x=jeu.getFraise()[i].getPositionFraise().getPosX();
        y=jeu.getFraise()[i].getPositionFraise().getPosY();
		im_fraise.draw(renderer,x*TAILLE_SPRITE,y*TAILLE_SPRITE,TAILLE_SPRITE,TAILLE_SPRITE);
    }

    //aficher les touches 
    x = (jeu.getNiveau().getLab().getDim().getLargeur());
    y = (jeu.getNiveau().getLab().getDim().getHauteur());
    im_touches.draw(renderer,x*TAILLE_SPRITE,0*TAILLE_SPRITE,TAILLE_SPRITE*5,TAILLE_SPRITE*5);

}

void SdlLab::sdlLabBoucle() {

    SDL_Event events;
	bool quit = false;
	while (!quit) {

		while (SDL_PollEvent(&events)) {        
			
            switch (events.type) {
                    
                case(SDL_QUIT):
                    quit = true;  
                    break; 

                case(SDL_KEYDOWN):
                    if(events.key.keysym.sym==SDLK_ESCAPE){
                        quit=true;
                        break;
                    }

                    if(events.key.keysym.sym==SDLK_RIGHT){
                        // Regarde si on appuyer sur la touche f
                        jeu.toucheClavier('d');
                            
                    }

                    if(events.key.keysym.sym==SDLK_LEFT){
                        // Regarde si on appuyer sur la touche d 
                        jeu.toucheClavier('g');
                            
                    }
                    
                    if(events.key.keysym.sym==SDLK_UP){
                        // Regarde si on appuyer sur la touche e 
                        jeu.toucheClavier('h');
                            
                    }
                        
                    if(events.key.keysym.sym==SDLK_DOWN){
                        // Regarde si on appuyer sur la touche d
                        jeu.toucheClavier('b');
                            
                    } 
                    if(events.key.keysym.sym==SDLK_r){
                        // Regarde si on appuyer sur la touche d
                        jeu.rejouer_partie();
                    }

                default:
                    quit=false;
            }

            if (jeu.partie_terminee()) {
                if(jeu.niv.getNum()<=5) {
                    //on est a la derniere partie
                    nouvellePartie();
                }             
            }
                    
            // on affiche le jeu sur le buffer cach�
            sdlLabAfficher();

            // on permute les deux buffers 
            SDL_RenderPresent(renderer); 
        }
    }

    SDL_Quit();
}

