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
 * @class Niveau
 * @brief la class Niveau contient le numero du niveau, le labyrinthe, la position initiale des emplacements cible et des fraises, le nombre de fraises.
 */

class Niveau {

private :
    int num, nbFraises;
	Labyrinthe lab;
	std::vector <Position> pos_EmpCibles;
    std::vector <Position> posInit_Fraises;
    Position posInit_Gardien;

public:

    /**
     * @brief <B>Construit</B> un niveau
     * les données num et nbFraises valent 0
     */
    Niveau();

    /**
     * @brief Accesseur de l'attribut num du niveau
     * @return un entier représentant le numéro du niveau
     */
    int getNum();

    /**
     * @brief Mutateur de l'attribut num du niveau
     * @param n un entier à affecter à num  
     */
    void setNum(int n);

    /**
     * @brief Accesseur de l'attribut nbFraises du niveau
     * @return un entier représentant le nombre de fraises du niveau
     */
    int getNbFraises() const;

    /**
     * @brief Mutateur de l'attribut nbFraises du niveau
     * @param n un entier à affecter à nbFraises 
     */
    void setNbFraises(int n);

    /**   
     * @brief la fonction getLab renvoie l'attribut lab du niveau
     * @return un objet de type Labyrinthe
     */
    const Labyrinthe& getLab() const;

    /**   
     * @brief la fonction setLab modifie le labyrinthe selon l'entier entré en paramètre
     * @param n: entier correspondant au numéro du niveau
     */
    void setLab(int n);

    /**   
     * @brief Accesseur de l'attribut pos_EmpCibles représentant les positions des emplacements cibles du niveau
     * @return un tableau dynamique de position
     */
    vector <Position>getPos_EmpCibles();

    /**   
     * @brief Accesseur de l'attribut posInit_Fraises représentant les positions initiales des fraises du niveau
     * @return un tableau dynamique de position
     */
    vector <Position>getPosInit_Fraises();

    /**   
     * @brief Accesseur de l'attribut posInit_Gardien représentant la position initiale du gardien dans le niveau
     * @return une position
     */
    Position getPosInit_Gardien()const;

    /**
     * @brief procedure ajouterFraise ajoute une fraise dans le niveau
     * @param p: la position initiale de la nouvelle fraise
    */
    void ajouterFraise(const Position & p);

    /**
     * @brief procedure ajouterEmpCible ajoute un emplacement cible dans le niveau
     * @param p: la position de la nouvelle emplacement cible
     */
    void ajouterEmpCible(const Position & p);

    void testRegression() const ;
};

#endif