#ifndef INTERFACE_H
#define INTERFACE_H

#include "plateau.h"


/* Fonction pour afficher en console un message signifiant qu’un nouveau tour commence ; avec toutes les
informations utiles (notamment si un nouvel espace pour les cartes Personnel est apparu) */

/*  @requires : aucun
    @assign: aucun
    @ensure : affiche un message de nouveau tour*/
void new_tour(Plateau* P);



/* Fonction pour afficher en console un message signifiant qu’une nouvelle phase commence et l’ENSIIE
associée à cette phase */

/*  @requires : Le joueur qui joue la nouvelle phase
    @assign: aucun
    @ensure : affiche un message de nouvelle phase */
void newphase(Joueur J);


/* Fonction pour afficher le plateau */

/*  @requires : Les élements des deux joueurs, l'état du plateau.
    @assign: aucun
    @ensure : affiche le plateau correspondant a la phase correspondante */    
void afficher_plateau(Joueur J,Plateau* P);

/* fonction pour demander à un joueur qui reçoit une nouvelle carte Elève s’il souhaite ajouter une carte
FISE ou FISA. */

/*  @requires : Le joueur qui choisit sa carte
    @assign: aucun
    @ensure : La carte choisie par le joueur va dans la pile correspondante dans le plateau  */ 

Cartes choix_carte_Eleve(Joueur J, Plateau P);

/* Fonction permettant de savoir quel carte le joueur veut poser sur le plateau */

/*  @requires : Le joueur qui choisit sa carte et le plateau
    @assign: aucun
    @ensure : La carte choisie par le joueur (potentiellement carte nouvelle phase) */ 
Cartes choix_carte(Joueur* J,Plateau *P);



/* Fonction pour demander à un joueur de choisir une carte de sa main ou de finir sa phase. La fonction ne
proposera que des cartes de la main qui coûtent moins cher que le nombre de PE du joueur. Si aucune carte
n’est moins chère, alors seul le choix de finir sa phase est proposé au joueur. */

/*  @requires : Le joueur qui choisit sa carte
    @assign: aucun
    @ensure : nouveau tour */ 
int choix_fin(Joueur J);

/* Fonction qui affiche le gagnant du jeu ou égalité le cas échéant */

/*  @requires : entier indicateur de l'issue de partie ou non.
    @assign: aucun
    @ensure : affiche le resultat de la partie */ 
void resultatpartie(int fin_de_partie);

/*  @requires :aucun 
    @assign: aucun
    @ensure : renvoie soit 0 soit 1 permet de savoir qu'elle joueur commence  */ 
int debutval();

/*  @requires :debut
    @assign: aucun
    @ensure : permet d'alterner les tours */ 
int changedebut(int debut);

/*  @requires :plateau
    @assign: aucun
    @ensure : affiche le numero du tour  */ 
void printtour(Plateau P);





#endif 

