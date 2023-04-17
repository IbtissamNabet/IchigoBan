/**
 * @file Gardien.h
 
 * @brief Module gérant les fonctionalités relatives à la création d'un personnage(joueur) et controler ses action pour 
 pouvoir pousser les fraises dans leurs emplacements cibles.
   

*/

//_______________________________________________________________________________________________________________________________________________________________
#ifndef GARD_
#define GARD_
#include"Position.h"
#include"Labyrinthe.h"

/**
 
 * @brief la class Gardien represente le joueur elle contient la position du joueur qui permettera de gérere ses déplacement .

*/
class Gardien {
    
public :
Position pos_gardien; 

 /**
    @brief <B>Construit</B> un objet Gardien .
    Le  constructeur crée un objet Gardien par defaut a la premiere case du tableau 2D
*/
Gardien();
//___________________________________________________________________________________________________________________________________________________________________
/**
    @brief
    La fonction getPositionGardien récupere la position du joueur  
*/
Position  getPositionGardien()const;
//___________________________________________________________________________________________________________________________________________________________________
/**
    @brief
    La procedure setPositionGardien modofie la position du joueur en la mettant a la position donnée en paramétre 
    @param p: la nouvelle position du Gardien  
*/

void  setPositionGardien(const Position & p);
//___________________________________________________________________________________________________________________________________________________________________
/**
    @brief
    La procedure gauche permet de faire bouger le gardien a gauche (a la case d'à coté ) 
    @param l: le labyrinthe ou deplacer le gardien 
*/
void gauche(const Labyrinthe & l);
//___________________________________________________________________________________________________________________________________________________________________
/**
    @brief
    La procedure droite permet de faire bouger le gardien a droite(a la case d'à coté ) 
    @param l: le labyrinthe ou deplacer le gardien 
*/
void droite(const Labyrinthe & l );
//___________________________________________________________________________________________________________________________________________________________________
/**
    @brief
    La procedure haut permet de faire bouger le gardien en haut (a la case du  dessus) 
    @param l: le labyrinthe ou deplacer le gardien 
*/
void haut(const Labyrinthe & l );
//___________________________________________________________________________________________________________________________________________________________________
/**
    @brief
    La procedure gauche permet de faire bouger le gardien a en bas  (a la case du bas ) 
    @param l: le labyrinthe ou deplacer le gardien 
*/
void bas(const Labyrinthe &l);


void testRegression(const Labyrinthe & l);



};

#endif
