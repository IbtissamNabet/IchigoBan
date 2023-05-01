/**
 * @file txtJeu.h
 * @brief Module gérant l'affichage texte du jeu IchigoBan
*/
#ifndef _TXTJEU_H
#define _TXTJEU_H
#include "Jeu.h"
#include"winTxt.h"
#include"txtJeu.h"



/**
 * @brief Fonction qui affiche tout les éléments du jeu dans une fenetre texte
 * @param win fenetre texte
 * @param jeu Jeu
 */
void txtAff(WinTXT & win, const Jeu & jeu);

/**
 * @brief Fonction qui gère l'affichage en mode texte et les actions du joueurs via les touches tout le long des parties du jeu
 * @param jeu Jeu
 */
void txtBoucle (Jeu & jeu);



#endif