#include "Dimension.h"

Dimension::Dimension(){
    largeur=0;
    hauteur=0;
}

int Dimension::getHauteur() const {
    return hauteur;
}

int Dimension::getLargeur() const {
    return largeur;
}

void Dimension::setHauteur(int H){
    hauteur=H;
}

void Dimension::setLargeur(int L){
    largeur=L;
}