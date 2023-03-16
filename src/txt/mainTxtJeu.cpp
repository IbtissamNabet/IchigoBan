#include "Jeu.h"
#include "winTxt.h"
#include "txtJeu.h"
#include <unistd.h>

int main () {
	termClear();
	Jeu jeu;
	txtBoucle(jeu);
	
    
	return 0;
}