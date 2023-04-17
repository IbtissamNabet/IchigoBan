/**
 * @file Fraise.h
 
 * @brief Module gérant les fonctionalités relatives à la création desfraises et controler ses action pour 
 être  poussées par le gardien dans leurs emplacements cibles.
   

*/
//_______________________________________________________________________________________________________________________________________________________________

#ifndef FRAISE_H
#define FRAISE_H

#include"Labyrinthe.h"
#include"Position.h"
#include"Gardien.h"



/**
 
 * @brief la class Fraise represente la fraise, elle contient la position de la fraise qui permettera de gérere ses déplacement .

*/

//________________________________________________________________________________________________________________________________________________________
class Fraise
{
private:
    Position pos_Fraise ;
public:

/**
    @brief <B>Construit</B> un objet Fraise.
    Le  constructeur crée un objet Fraise par defaut a la premiere case du tableau 2D
*/

    Fraise();

//___________________________________________________________________________________________________________________________________________________________________
/**
    @brief
    La fonction getPositionFraise récupere la position de la fraise 
*/
    Position  getPositionFraise()const;
//___________________________________________________________________________________________________________________________________________________________________
/**
    @brief
    La procedure setPositionFraise modofie la position de la fraise en la mettant a la position donnée en paramétre 
    @param p: la nouvelle position de la fraise  
*/

    void setPositionFraise(const Position & p);
//___________________________________________________________________________________________________________________________________________________________________
/**
    @brief
    La procedure gauche permet de faire bouger la a gauche (a la case d'à coté ) 
    @param l: le labyrinthe ou deplacer la fraise 
    @param g : pour pouvoir recupérer la position d gardien qui permétera de bouger la fraise si il est autour de la fraise 
*/
    void gauche(const Labyrinthe & l,const Gardien & g);
 //___________________________________________________________________________________________________________________________________________________________________
/**
    @brief
    La procedure droite permet de faire bouger la a droite(a la case d'à coté ) 
    @param l: le labyrinthe ou deplacer la fraise 
    @param g : pour pouvoir recupérer la position d gardien qui permétera de bouger la fraise si il est autour de la fraise 
*/
    void droite(const Labyrinthe & l,const Gardien & g);
//___________________________________________________________________________________________________________________________________________________________________
/**
    @brief
    La procedure haut permet de faire bouger la fraise vers le haut (a la case du dessus ) 
    @param l: le labyrinthe ou deplacer la fraise 
    @param g : pour pouvoir recupérer la position d gardien qui permétera de bouger la fraise si il est autour de la fraise 
*/
    void haut(const Labyrinthe & l,const Gardien & g);
//___________________________________________________________________________________________________________________________________________________________________
/**
    @brief
    La procedure haut permet de faire bouger la fraise vers le bas (a la case du dessous) 
    @param l: le labyrinthe ou deplacer la fraise 
    @param g : pour pouvoir recupérer la position d gardien qui permétera de bouger la fraise si il est autour de la fraise 
*/
    void bas(const Labyrinthe &l,const Gardien & g);



void testRegression(const Labyrinthe & l);

};






#endif
