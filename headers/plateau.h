#ifndef PLATEAU_H
#define PLATEAU_H


#include "structure.h"

typedef struct Joueur{
    int n_joueur;      //numero du joueur 1 ou 2
    int dd;            //les points developpements durables du Joueur n_joueur 
    int PE;
    int dura_eleve;  // Donnce la valeur par defaut de l'initialisation des cartes eleves (rajouté lors du lot B)
    int dev_eleve;
}Joueur;


typedef struct Plateau {
  int n_tour; /* Ajouté au lot B */
  stack main1;
  stack main2;
  stack deck1;
  stack deck2;
  stack defausse1;
  stack defausse2;
  stack fise1;
  stack fise2;
  stack fisa1;
  stack fisa2;
  queue* perso1;
  queue* perso2;
}Plateau;


/*
@requires aucun
@assigns mémoire allouée au nouveau plateau
@ensures renvoie un nouveau plateau avec les 2 decks de chaque joueur
*/

Plateau create_plateau(Joueur J1, Joueur J2);

/*
@requires plateau valide
@assigns libère la mémoire allouée au plateau
@ensures supprime le plateau de la mémoire
*/

void liberation_memoire_plateau(Plateau *P);



/*
@requires plateau valide
@assigns aucun
@ensures renvoie le nombre de cartes piochées
*/

int nombre_cartes_piochees(Plateau *P,Joueur joueur_qui_joue);

/*
@requires plateau valide
@assigns aucun
@ensures renvoie le nouveau plateau où la carte piochée passe du deck à la main
*/

void piocher_carte(Plateau *P,Joueur joueur_qui_joue);

/* Permet de calculer le nombre de carte Eleves que le joueur recevra 
   au debut de la phase varie entre 0 et 2 de memoire */

int nb_eleves_phase(Plateau* P, Joueur J);

/* Permet de jouer une carte Eleve FISE OU FIPA */
    
void jouerEleve(Joueur joueur1,Plateau *x,Cartes ajouer);

/* Permet de jouer une carte une carte de sa main */

void JouerCarteMain(Joueur* joueur1,Plateau *x,Cartes* ajouer);

/* Permet de Calculer les PE,on a besoin d'avoir le numero du tour 
    pour mettre en place les regles sur les tours pair et impairs */

int Calcul_PE(Joueur J,Plateau x);

/* Permet savoir si la partie fini et de savoir qui a gagne
    ou si il y a egalite 0 pour fini 1 jouer 1 gagne 2 c'est joueur 2 3 si pas fini*/

int fin_de_partie(Plateau P, Joueur joueur1,Joueur joueur2);



/* Signifie au plateau que le tour entier est termine 
    et permet aussi le calcul des DD
    
*/
void fin_de_tour(Plateau* plateau,Joueur *joueur1,Joueur *joueur2);

/*LOT B*/

/* Permet recuperer le deck du joeur */
stack recup_deck(Joueur J, Plateau P);

/* Permet recuperer la main du joeur */
stack recup_main(Joueur J, Plateau P);

//* Permet recuperer la defause du joeur */
stack recup_defausse(Joueur J, Plateau P);

int nb_carte_eleveFISE(Joueur J, Plateau *P); /*nb de cartes posées par le joueur  eleve fise */
int nb_carte_eleveFISA(Joueur J, Plateau *P); /*nb de cartes posées par le joueur  eleve fisa*/

int parite_tour(Plateau P);/* savoir si on est dans un tour pair ou impair*/
void create_deck(Joueur J, Plateau *P);/* cree le deck du joueur */
void jouerAction(Plateau *P, Joueur* J,Cartes *C); /* permet de jouer la carte action et son effet*/

Plateau plateau_test(Joueur J1, Joueur J2,int i); /* Creation de plateau de test */
int compteur_developpement(Plateau *P,Joueur J); /* Calcul des points de developpement d'un joueur J */ 
int compteur_durab(Plateau *P,Joueur J);

int souhait_deck();

/*  @requires : 
    @assign: aucun
    @ensure : */ 
int edit_deck_choix_cartes(stack_int tab);


#endif
