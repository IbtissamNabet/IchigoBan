#include "sdlLab.h"

int main (int argc, char** argv) {

	
    Jeu game;
	SdlLab sdl_Jeu(game);
	sdl_Jeu.sdlLabBoucle();
	return 0;
}

