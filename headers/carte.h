#ifndef Carte_H
#define Carte_H


typedef struct Cartes {
  int cout;
  int num;
  int* effet;
  int dura;
  int dev;
  char* nom;
}Cartes;


/*  @requires : une carte
    @assign: aucun
    @ensure : renvoie 1 si carte action 0 sinon */

int isAction(Cartes c);

/*  @requires : une carte
    @assign: aucun
    @ensure : renvoie 1 si carte personnel 0 sinon */

int isPersonnel(Cartes c);

/*  @requires : une carte
    @assign: aucun
    @ensure : renvoie 1 si carte eleve 0 sinon */

int isEleve(Cartes c);

/*  @requires : un entier n 
    @assign: cree un tableau d'effet
    @ensure : renvoie la carte initialise si elle est correspond a un cas du case */
Cartes initialisation(int n);

#endif
