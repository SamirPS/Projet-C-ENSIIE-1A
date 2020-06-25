#ifndef structure_H
#define structure_H
#define stacksize 3000

#include "carte.h"


/*creation d'une structure pour les piles*/
struct stack {
  Cartes t[stacksize];
  int top;
};

typedef struct stack stack;




/* @requires nothing
@assigns aucun
@ensures retourne une pile vide */
stack creation_stack();


/* @requires une pile r valide
@assigns aucun
@ensures retourne 1 si la pile est vide*/
int is_stack_empty(stack r);

/* @requires une pile r valide
@assigns memoire utilise pour la pile
@ensures rajoute l'element a au sommet de la pile*/
void push_stack(stack* r,Cartes a );

/* @requires une pile r valide
@assigns
@ensures Dépilement qui a pour effet de retirer l'élement au sommet de la pile et le retourne*/
Cartes pop_stack(stack* r);

/* @requires une pile r valide
@assigns memoire pour la pile main
@ensures affiche la pile*/
void display_stack(stack* r);


/* @requires une pile maPile et un entier i valident
@assigns memoire pour la pile main
@ensures renvoie la ieme carte de la pile*/
Cartes trouver(stack* maPile, int choisi);

/* @requires une pile maPile et un entier i valident
@assigns memoire pour la pile main
@ensures renvoie la ieme carte de la pile*/
int trouver_num(stack *maPile, int num_carte);

/* @requires une pile main et un entier i valident
@assigns memoire pour la pile main
@ensures renvoie la ieme carte de la pile*/
Cartes pop_ieme_carte (int i, stack* main);

/* @requires une pile r valide
@assigns aucun
@ensures affiche la la taille de pile r */
int size_stack(stack *r);





struct stack_int {
  int t[stacksize];
  int top;
};

typedef struct stack_int stack_int;


/* @requires nothing
@assigns aucun
@ensures retourne une pile vide */
stack_int creation_stack_int();


/* @requires une pile r valide
@assigns aucun
@ensures retourne 1 si la pile est vide*/
int is_stack_empty_int(stack_int* r);

/* @requires une pile r valide
@assigns memoire pour la pile main
@ensures rajoute l'element a au sommet de la pile*/
void push_stack_int(stack_int* r,int a );

/* @requires une pile r valide
assigns memoire pour la pile main
@ensures Dépilement qui a pour effet de retirer l'élement au sommet de la pile et le retourne*/
int pop_stack_int(stack_int * r);

/* @requires une pile r valide
@assigns memoire pour la pile main
@ensures affiche la pile*/
void display_stack_int(stack_int* r);

/* @requires une pile r valide
assigns memoire pour la pile main
@ensures Dépilement qui a pour effet de retirer le ieme élement de la pile et le retourne*/
int pop_ieme_carte_int ( stack_int * pile,int i);



int trouver_num_int(stack_int *maPile, int num_carte);










typedef struct element element;

struct element {
  Cartes carte;
  element *next;
};

typedef struct queue queue;

struct queue {
  element *first;
};



/* @requires nothing
@assigns aucun
@ensures retourne une pile vide */
queue* creation();

/* @requires une file s valide
@assigns aucun
@ensures retourne 1 si la file est vide, c'est à dire les deux piles sont vides*/
int is_queue_empty(queue s);

/* @requires une file s valide
@assigns mémoire pour la file
@ensures rajoute l'element b au sommet de la pile initiale de la structure file*/
void push_queue(queue *s, Cartes nouvelle_carte);

/* @requires une file s valide
@assigns mémoire pour la file
@ensures Dépilement qui a pour effet de retirer le premier element et le retourne*/
Cartes pop_queue(queue *s);

/* @requires une file s valide
@assigns mémoire pour la file
@ensures Affiche la file s*/
void display_queue(queue *s);

/* @requires une file s valide
@assigns aucun
@ensures affiche la taille de la file s */
int size_queue(queue* s);
#endif 