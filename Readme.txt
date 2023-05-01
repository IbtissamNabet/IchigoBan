# LIFAP4 Conception et Developpement d'Applications


# ICHIGO'BAN 

## Table de matiéres 
1. [Presentation du jeu](#Presentation)
2. [Fonctionnalités et Régles du Jeu ]
3. [Comment jouer]
4. [Comment compiler et exécuter le jeu]
5. [Code et Gestion des fichiers ](#arborescence)
6. [Documentation du code]


## Presentation du jeu 

Ichigo'Ban est un jeu de puzzle inspiré du jeu classique SOKOBAN ,dans lequel un Gardien doit pousser des fraises jusqu'à leur emplacement cible. 
Le jeu est composé de plusieurs (5) niveaux avec des configurations de plus en plus difficiles.

***
Ichigo'Ban est Crée par IBTISSAM NABET P2208660 et HANITRINIRINA SAROBIDY p2102840 .

Lien git du projet : https://forge.univ-lyon1.fr/p2208660/IchigoBan/

## Fonctionnalités et Régles du Jeu 
      *** Fonctionnalités 
. Pousse des fraises a leurs emplacements cibles .
. Niveaux prédéfinies avec des configurations de plus en plus difficiles.
. Musique .

      *** Régles du Jeu 
. Le joueur ne peut pas pousser 2 fraises à la fois.
. Le joueur doit placer toutes les fraises dans leurs emplacements cibles pour passer au niveau superieur.
. Lorsque le joueur est cincée il peut refaire et rejouer la partie .

## Comment jouer

** Aves SDL 
. Utilisez les touches fléchées pour déplacer le Gardien dans les quatre directions du terrains.
. Utilisez la touche R du clavier pour rejouer une partie 

** En texte 
. Utilisez les touches " e : pour haut , s : pour gauche , f: pour droite , d pour bas, et q : pour quitter" 

. Pousser les fraises pour les placer sur leur emplacement cible.
. Le niveau est terminé lorsque toutes les caisses ont été placées sur leur emplacement cible et un 
   autre niveau est chargé.

## Comment compiler et exécuter le jeu

** pour compiler 
. ça se fait avec make et tout les codes seront compilés

** pour executer 
. en mode texte : il suffit de tapper la commande ./bin/txtjeu
. avec SDL2 : il suffit de tapper la commande ./bin/sdljeu


## Code et Gestion des fichiers

Ce code est construit de manière à avoir les fonctionalités de base regroupées dans des classes noyau.
puis d'avoir une surcouche pour l'affichage : texte/console, SDL2.

L'organistion des fichiers du Jeu Ichigo'Ban est la suivante.

. IchigoBan/src/core  : les classes de base du Jeu IchigoBan.
ça compile sans dépendance(comme les librairies d'affichage ) à part les lib du système.

. IchigoBan/src/txt  : les classes s'occupant de faire tourner le Jeu (core) et de l'afficher sur la console en mode texte,
grace a la classe  winTxt qui permet l'utilisation d'une fenêtre texte et des évènements claviers.

. IchigoBan/src/SDL2  : les classes s'occupant de faire tourner le jeu  (core) et permet l'affichage graphique avec SDL2.

. IchigoBan/doc : le fichier doxygen qui permet de générer la documentation du code
              : le pptx propre au projets(avec le diagramme UML ,Diagramme de Gantt)

. IchigoBan/data      : les assets (images du personnage,fraises,terrain..., sons, fichiers des niveaux,etc.)

. IchigoBan/bin       : répertoire où les executables seront compilés

. IchigoBan/obj       : répertoire comportant les compilations intermédiaires (.o)

## Documentation du code 
 la documentation du jeu est genérée avec doxygen (dossier IchigoBan/doc/html) 
 