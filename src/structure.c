#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "../headers/structure.h"

#define stacksize 3000



/* @requires nothing
@assigns aucun
@ensures retourne une pile vide */

stack creation_stack(){
  stack r;
  r.top=-1;
  return r;
}



/* @requires une pile r valide
@assigns memoire pour la pile main
@ensures affiche la pile*/
void display_card(stack *r) {
  int i=-1;

printf ("***********************************");
while(i != r->top && r->top!=-1) 
{
    i++;
    printf ("****************\n");
    if (r->t[i].num < 10)
    {
      printf ("*    Num:0%d    *",r->t[i].num);
    }
    else
    {
      printf ("*    Num:%d    *",r->t[i].num);
    }
    printf ("*     %s      *",r->t[i].nom);
    if (r->t[i].cout < 10)
    {
      printf ("*    Coût:0%d    *\n",r->t[i].cout);
    }
    else
    {
      printf ("*    Cout:%d    *\n",r->t[i].cout);
    }
    printf ("***********************************");
      

    
    

}
printf ("****************\n");

}


/* @requires une pile r valide
@assigns aucun
@ensures retourne 1 si la pile est vide*/
int is_stack_empty(stack r) {
  return (r.top<0);
}

/* @requires une pile r valide
@assigns memoire utilise pour la pile
@ensures rajoute l'element a au sommet de la pile*/
void push_stack(stack *r,Cartes a ) {
  r->top=r->top+1;
  r->t[r->top]=a;
}

/* @requires une pile r valide
@assigns memoire pour la pile main
@ensures Dépilement qui a pour effet de retirer l'élement au sommet de la pile et le retourne*/
Cartes pop_stack(stack *r) {

  Cartes p;
  if (is_stack_empty(*r)) {
   p.num=-1;
   p.dev=0;
   p.dura=0;
  }

  else {

     p=r->t[r->top];
    r->top=r->top-1;
  }

  return p;
}

/* @requires une pile r valide
@assigns memoire pour la pile main
@ensures affiche la pile*/
void display_stack(stack *r) {
    display_card(r);
}

/* @requires une pile maPile et un entier i valident
@assigns memoire pour la pile main
@ensures renvoie la ieme carte de la pile*/
Cartes trouver(stack *maPile, int choisi){
  Cartes renvoye;
  if(maPile->top==-1){
    renvoye.num=-1;
    return renvoye;
  }
  else{
    for(int i=0;i<maPile->top+1;i++){
    if (maPile->t[i].num==choisi){
      return maPile->t[i];
    }
  }
   renvoye.num=-1;
  }
 return renvoye; 
}

/* @requires une pile maPile et un entier i valident
@assigns memoire pour la pile main
@ensures renvoie la ieme carte de la pile*/
int trouver_num(stack *maPile, int num_carte){
  int renvoye;
  if(maPile->top==-1){
    renvoye=-1;
    return renvoye;
  }
  else{
    for(int i=0;i<maPile->top+1;i++){
    if (maPile->t[i].num==num_carte){
      return i;
    }
  }
   renvoye=-1;
  }
 return renvoye; 
}

/* @requires une pile main et un entier i valident
@assigns memoire pour la pile main
@ensures renvoie la ieme carte de la pile*/
Cartes pop_ieme_carte (int i, stack *main){
  stack pile_intermediaire=creation_stack();
  int taille_stack=main->top;
  Cartes aa;
  while(taille_stack != i){
    aa=pop_stack(main);
    push_stack(&pile_intermediaire, aa);
    taille_stack--;
  }
  Cartes carte_arenvoyer=pop_stack(main);
  while(!is_stack_empty(pile_intermediaire)){
    aa=pop_stack(&pile_intermediaire);
    push_stack(main, aa);
  }
  return carte_arenvoyer;
}

/* @requires une pile r valide
@assigns aucun
@ensures affiche la la taille de pile r */
int size_stack(stack *r){
  return r->top;
}


/* @requires nothing
@assigns aucun
@ensures retourne une pile vide */
stack_int creation_stack_int(){
  stack_int r;
  r.top=-1;
  return r;
}

/* @requires une pile r valide
@assigns aucun
@ensures retourne 1 si la pile est vide*/
int is_stack_empty_int(stack_int* r) {
  return (r->top<0);
}

/* @requires une pile r valide
@assigns memoire pour la pile main
@ensures rajoute l'element a au sommet de la pile*/
void push_stack_int(stack_int* r,int a ) {
  r->top+=1;
  r->t[r->top]=a;
}

/* @requires une pile r valide
assigns memoire pour la pile main
@ensures Dépilement qui a pour effet de retirer l'élement au sommet de la pile et le retourne*/
int pop_stack_int(stack_int* r) {
  int p;
  if (is_stack_empty_int(r)) {
    return 0;
  }
  else {
    p=r->t[r->top];
    r->top=r->top-1;
  }
  return p;
}

/* @requires une pile r valide
@assigns memoire pour la pile main
@ensures affiche la pile*/
void display_stack_int(stack_int* r) {
  int i =0;
  while(i!=r->top) {
    printf("%d ",r->t[i]);
    i+=1;
  }
}
/* @requires une pile r valide
assigns memoire pour la pile main
@ensures Dépilement qui a pour effet de retirer le ieme élement de la pile et le retourne*/
int pop_ieme_carte_int ( stack_int *pile,int i){
  stack_int pile_intermediaire=creation_stack_int();
  int taille_stack=pile->top;
  int aa=0;
  while(taille_stack != i){
    aa=pop_stack_int(pile);
    push_stack_int(&pile_intermediaire, aa);
    taille_stack--;
  }
  int int_arenvoyer=pop_stack_int(pile);
  while(!is_stack_empty_int(&pile_intermediaire)){
    aa=pop_stack_int(&pile_intermediaire);
    push_stack_int(pile, aa);
  }
  return int_arenvoyer;
}



int trouver_num_int(stack_int *maPile, int num_carte){
  int renvoye;
  if(maPile->top==-1){
    renvoye=-1;
    return renvoye;
  }
  else{
    for(int i=0;i<maPile->top;i++){
    if (maPile->t[i]==num_carte){
      return i;
    }
  }
   renvoye=-1;
  }
  return renvoye; 
}





/* @requires nothing
@assigns aucun
@ensures retourne une pile vide */
queue* creation(){
  queue* s =(queue*)malloc(sizeof(queue* ));
  s->first=NULL;
  return s;
}


/* @requires une file s valide
@assigns aucun
@ensures retourne 1 si la file est vide, c'est à dire les deux piles sont vides*/
int is_queue_empty(queue s){
  return (s.first==NULL);
}

/* @requires une file s valide
@assigns mémoire pour la file
@ensures rajoute l'element b au sommet de la pile initiale de la structure file*/
void push_queue(queue *s, Cartes nouvelle_carte){
  element *new_element = malloc(sizeof(*new_element));
  if (s == NULL || new_element == NULL) {
    exit(EXIT_FAILURE);
  }
  new_element->carte = nouvelle_carte;
  new_element->next = NULL;
  if (s->first != NULL) {
    element *element_act=s->first;
    while (element_act->next != NULL){
      element_act = element_act->next;
    }
    element_act->next = new_element;
  }
  else {
    s->first = new_element;
  }
}

/* @requires une file s valide
@assigns mémoire pour la file
@ensures Dépilement qui a pour effet de retirer le premier element et le retourne*/
Cartes pop_queue(queue *s) {
  if (s == NULL) {
    exit(EXIT_FAILURE);
  }
  Cartes carte_pop;
  if (s->first != NULL) {
    element *element_pop = s->first;
    carte_pop = element_pop->carte;
    s->first = element_pop->next;
    free(element_pop);
  }
  return carte_pop;
}

/* @requires une file s valide
@assigns mémoire pour la file
@ensures Affiche la file s*/
void display_queue(queue *s) {
  if (s == NULL){
    exit(EXIT_FAILURE);
  }
  element *element_act = s->first;
  while (element_act != NULL) {
    printf("(%d:%d)", element_act->carte.num,element_act->carte.cout);
    element_act = element_act->next;
  }
}

/* @requires une file s valide
@assigns aucun
@ensures affiche la taille de la file s */
int size_queue(queue* s){
  int r=0;
  element *element_act = s->first;
  while (element_act != NULL) {
    r+=1;
    element_act = element_act->next;
  }
  return r;
}

