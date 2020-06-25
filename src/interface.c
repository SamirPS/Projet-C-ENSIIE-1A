#include "../headers/interface.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

/*  @requires : aucun
    @assign: aucun     
    @ensure : affiche un message de nouveau tour*/

void new_tour(Plateau* P) {
  P->n_tour++;
  printf("Le tour  %d  commence \n",P->n_tour);
  
}

int debutval(){
  srand(time(NULL)); 
  return rand()%2;
}

void printtour(Plateau P){
  printf("Nous sommes au tour %d \n",P.n_tour);

}

int changedebut(int debut){
  return 1-debut;
}

/*  @requires : Le joueur qui joue la nouvelle phase  
    @assign: aucun
    @ensure : affiche un message de nouvelle phase */

void newphase(Joueur J) {
  printf("Le joueur %i commence une nouvelle phase \n",J.n_joueur);
}

/*  @requires : entier indicateur de l'issue de partie ou non. 
    @assign: aucun 
    @ensure : affiche le resultat de la partie */

void resultatpartie(int fin_de_partie) {
  if (fin_de_partie==1) printf("Le joueur 1 gagne \n");
  else if (fin_de_partie==2) printf("e joueur 2 gagne \n");
  else printf("Match nul \n");
}

/*  @requires : Le joueur qui choisit sa carte 
    @assign: aucun 
    @ensure : La carte choisie par le joueur va dans la pile correspondante dans le plateau  */

Cartes choix_carte_Eleve(Joueur J, Plateau P){
  char actuel[256];
  char * endptr;
  int b;
  Cartes eleve;
  printf(" FISE ou FISA ? (entrez 1 pour FISE ou 2 pour FISA)");
  fgets(actuel, 256, stdin);
  strtol(actuel, &endptr, 10);
        /*On sort de la boucle quand l'utilisateur a entre un entier */
  while (actuel == endptr)
            {
                    printf("Erreur ,veuillez entrer un entier ");
                    fgets(actuel, 256, stdin);
                    strtol(actuel, &endptr, 10);
            }


  b=strtol(actuel, &endptr, 10);

  while(b!=1 && b!=2 ){
    return choix_carte_Eleve(J,P);
  }
  if (b==1){
    eleve.num=32;}
  else if (b==2){
    eleve.num=33;}

  eleve.cout=0;
  eleve.effet = (int *) calloc(12,sizeof(int *));
  eleve.effet[0]=24;
  eleve.dura=J.dura_eleve;
  eleve.dev=J.dev_eleve;
  
  return eleve;
}

/*  @requires : Le joueur qui choisit sa carte et le plateau 
    @assign: aucun 
    @ensure : La carte choisie par le joueur (potentiellement carte nouvelle phase) */

Cartes choix_carte(Joueur* J,Plateau *P) {
  int b;
  Cartes carte_a_jouer;
  char actuel[256];
  char * endptr;
  carte_a_jouer.dev=0;
  carte_a_jouer.dura=0;
  printf("Quelle carte voulez-vous jouer  vous avez %d PE ? (entrez le numéro de la carte ou 0 si vous voulez finir la phase)",J->PE);

  fgets(actuel, 256, stdin);
  strtol(actuel, &endptr, 10);
        /*On sort de la boucle quand l'utilisateur a entre un entier */
  while (actuel == endptr)
            {
                    printf("Erreur ,veuillez entrer un entier ");
                    fgets(actuel, 256, stdin);
                    strtol(actuel, &endptr, 10);
            }


  b=strtol(actuel, &endptr, 10);


  if (b==0) {
    carte_a_jouer.cout=0;
    carte_a_jouer.num=0;
    J->PE-=carte_a_jouer.cout;
    return carte_a_jouer;
    
    }

  else if (J->n_joueur==1) {
    carte_a_jouer=trouver(&P->main1,b);
    if(carte_a_jouer.num==-1){

		printf("Cette carte n'est pas dans votre main \n");
		return choix_carte(J,P);
    }

	else if (carte_a_jouer.cout>J->PE){

		printf("Vous n'avez pas assez de PE pour jouer cette carte \n");
		return choix_carte(J,P);
    }

	else {
    J->PE-=carte_a_jouer.cout;
    return carte_a_jouer;
    }
    
    }


  else {
    carte_a_jouer=trouver(&P->main2,b);
    if(carte_a_jouer.num==-1){
		printf("Cette carte n'est pas dans votre main \n");
		return choix_carte(J,P);}
	else if (carte_a_jouer.cout>J->PE){
		printf("Vous n'avez pas assez de PE pour jouer cette carte \n");
		return choix_carte(J,P);}
    else {J->PE-=carte_a_jouer.cout;
    return carte_a_jouer;}}

    
}

/*  @requires : Les élements des deux joueurs, l'état du plateau.
    @assign: aucun 
    @ensure : affiche le plateau correspondant a la phase correspondante */

void afficher_plateau(Joueur J,Plateau *P){
  if(J.n_joueur==1){
  printf("Voici votre main \n");
  display_stack(&P->main1);
  printf("\n");


  printf("Voici vos perso \n");
  display_queue(P->perso1);
  printf("\n");

 


 printf("Voici votre nb de fise %d \n",nb_carte_eleveFISE(J,P)+1);


  printf("Voici votre nb de fisa %d \n",nb_carte_eleveFISA(J,P)+1);


  printf("Votre adversaire possède %d FISE et %d FISA\n",size_stack(&P->fise2)+1,size_stack(&P->fisa2)+1);


  printf("Voici votre nb de fisa %d \n",nb_carte_eleveFISA(J,P)+1);


  printf("Voici les perso des adversaires \n");
  display_queue(P->perso2);
  printf("\n");

  printf("Vous avez %d DD\n",J.dd);

  printf("Vous avez %d carte(s) dans la defausse\n",size_stack(&P->defausse1)+1);

  printf("Vous avez %d carte(s) dans votre deck\n",size_stack(&P->deck1)+1);

  

   printf("\n");

  }


  if(J.n_joueur==2){
  printf("Voici votre main \n");
  display_stack(&P->main2);
  printf("\n");

  printf("Voici vos perso \n");
  display_queue(P->perso2);
  printf("\n");

  

  printf("Voici votre nb de fise %d \n",nb_carte_eleveFISE(J,P)+1);

  printf("Voici votre nb de fisa %d \n",nb_carte_eleveFISA(J,P)+1);

  printf("Votre adversaire possède %d FISE et %d FISA\n",size_stack(&P->fise1)+1,size_stack(&P->fisa1)+1);

  printf("Voici les perso de votre adversaire \n");
  display_queue(P->perso1);
  printf("\n");

  printf("Vous avez %d DD\n",J.dd);

  printf("Vous avez %d carte(s) dans la defausse\n",size_stack(&P->defausse2)+1);


  printf("Vous avez %d carte(s) dans votre deck\n",size_stack(&P->deck2)+1);
  

  printf("\n");
  
  }

}



