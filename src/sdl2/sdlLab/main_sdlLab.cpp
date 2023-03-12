#include "sdlLab.h"

int main (int argc, char** argv) {

    Labyrinthe ter;
	SdlLab sdl_ter(ter);
	sdl_ter.sdlLabBoucle();
	return 0;
}

