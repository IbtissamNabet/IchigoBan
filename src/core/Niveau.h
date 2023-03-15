/**
 * @file Niveau.h
 * @brief Module gérant un niveau du jeu Ichigo'Ban   
*/

using namespace std;;


#ifndef _NIVEAU_H
#define _NIVEAU_H

#include <vector>
#include "Labyrinthe.h"
#include "Position.h"

/**
 * @brief la class Niveau contient le numero du niveau, le labyrinthe, la position initiale des emplacements cible et des fraises, le nombre de fraises.
*/

class Niveau {

private :
    int num, nbFraises;
	Labyrinthe lab;
	std::vector <Position> pos_EmpCibles;
    std::vector <Position> posInit_Fraises;

public:
/**
    @brief <B>Construit</B> un niveau .
*/
    Niveau();
//___________________________________________________________________________________________________________________________________________________________________

/**   
    @brief la fonction getNum renvoie le numero du niveau
*/
    int getNum();
//________________________________________________________________________________________________________________________________________________________________________

/**
    @brief la fonction setNum met la valeur du numero du niveau selon la valeur passée en paramètre
    @param n: le numero du niveau
*/
    void setNum(int n);

//________________________________________________________________________________________________________________________________________________________________________

/**   
    @brief la fonction getNbFraises renvoie le nombre de fraise du niveau
*/
    int getNbFraises();
//________________________________________________________________________________________________________________________________________________________________________

/**
    @brief la fonction setNbFraises met le nombre de fraises avec la valeur en paramètre
    @param n: nb fraises
*/
    void setNbFraises(int n);
//________________________________________________________________________________________________________________________________________________________________________

/**   
    @brief la fonction getLab renvoie le labyrinthe
*/
    const Labyrinthe& getLab() const;

//________________________________________________________________________________________________________________________________________________________________________
/**   
    @brief la fonction getPos_EmpCibles renvoie le tableau contenant la position des emplacements cible
*/
    vector <Position>getPos_EmpCibles();
//________________________________________________________________________________________________________________________________________________________________________

/**   
    @brief la fonction getPosInit_Fraises renvoie le tableau contenant la position initiale des fraises
*/
    vector <Position>getPosInit_Fraises();
//________________________________________________________________________________________________________________________________________________________________________

/**
    La procedure ajouterFraise ajoute une fraise dans le niveau
    @param p: la position initiale de la nouvelle fraise
*/
    void ajouterFraise(const Position & p);
//___________________________________________________________________________________________________________________________________________________________________

/**
    La procedure ajouterEmpCible ajoute un emplacement cible dans le niveau
    @param p: la position de la nouvelle emplacement cible
*/
    void ajouterEmpCible(const Position & p);

/**
    La procedure modifLab met à jour le labyrinthe en y ajoutant les nouvelles emplacements cibles
    @param p: la position de la nouvelle emplacement cible
*/
    void modifLab();

/**
     * @brief Effectue une série de tests vérifiant que le module fonctionne sans problémes 
*/
   void testRegression() const ;
};

#endif