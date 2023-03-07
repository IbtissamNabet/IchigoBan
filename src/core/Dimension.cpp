#include "Dimension.h"

Dimension::Dimension(){
    largeur=0;
    hauteur=0;
}

float Dimension::getHauteur() const {
    return hauteur;
}

float Dimension::getLargeur() const {
    return largeur;
}

void Dimension::setHauteur(float H){
    hauteur=H;
}

void Dimension::setLargeur(float L){
    largeur=L;
}