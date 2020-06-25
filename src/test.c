#include "../headers/interface.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"

int init_suite(void) { return 0; } 
int clean_suite(void) { return 0; } 


void test_structure(){

  stack A = creation_stack();
  CU_ASSERT_EQUAL(A.top,-1); 
}

void test_creation_plateau(){
  Joueur joueur1;
  Joueur joueur2;
    joueur1.n_joueur=1;
    joueur2.n_joueur=2;
    joueur1.dd=0;
    joueur2.dd=0;
    joueur1.dev_eleve=1; 
    joueur1.dura_eleve=1; 
    joueur2.dev_eleve=1; 
    joueur2.dura_eleve=1;
  Plateau P = create_plateau(joueur1,joueur2);
  CU_ASSERT_TRUE(size_stack(&P.fise1) == -1);
  CU_ASSERT_TRUE(size_stack(&P.fisa1) == -1);
  CU_ASSERT_TRUE(size_stack(&P.fise2) == -1);
  CU_ASSERT_TRUE(size_stack(&P.fisa2) == -1);
  CU_ASSERT_TRUE(size_stack(&P.defausse1) == -1);
  CU_ASSERT_TRUE(size_stack(&P.defausse2) == -1);
  CU_ASSERT_TRUE(size_stack(&P.main1) == -1);
  CU_ASSERT_TRUE(size_stack(&P.main2) == -1);
  CU_ASSERT_TRUE(P.n_tour == 0);
  CU_ASSERT_TRUE(size_stack(&P.deck1)+1 == 42);
  CU_ASSERT_TRUE(size_stack(&P.deck2)+1 == 42);

}

void test_ajout_carte_eleve(){
  Joueur joueur1;
  Joueur joueur2;
    joueur1.n_joueur=1;
    joueur2.n_joueur=2;
    joueur1.dd=0;
    joueur2.dd=0;
    joueur1.dev_eleve=1; 
    joueur1.dura_eleve=1; 
    joueur2.dev_eleve=1; 
    joueur2.dura_eleve=1;
  Plateau P = plateau_test(joueur1,joueur2,10);
  Cartes fise_test1;
        fise_test1.num=32;
        fise_test1.dev=joueur1.dev_eleve;
        fise_test1.dura=joueur2.dura_eleve;
  Cartes fise_test2;
        fise_test2.num=32;
        fise_test2.dev=joueur2.dev_eleve;
        fise_test2.dura=joueur2.dura_eleve;
  Cartes fisa_test1;
        fisa_test1.num=33;
        fisa_test1.dev=joueur1.dev_eleve;
        fisa_test1.dura=joueur2.dura_eleve;
  Cartes fisa_test2;
        fisa_test2.num=33;
        fisa_test2.dev=joueur2.dev_eleve;
        fisa_test2.dura=joueur2.dura_eleve;
  CU_ASSERT_TRUE(size_stack(&P.fise1) == 4);
  CU_ASSERT_TRUE(size_stack(&P.fise2) == 4);
  CU_ASSERT_TRUE(size_stack(&P.fisa1) == 4);
  CU_ASSERT_TRUE(size_stack(&P.fisa2) == 4);
  
  jouerEleve(joueur1,&P,fise_test1);
  CU_ASSERT_TRUE(size_stack(&P.fise1) == 5);

  jouerEleve(joueur1,&P,fisa_test1);
  CU_ASSERT_TRUE(size_stack(&P.fisa1) == 5);

  jouerEleve(joueur2,&P,fise_test2);
  CU_ASSERT_TRUE(size_stack(&P.fise2) == 5);

  jouerEleve(joueur2,&P,fisa_test2);
  CU_ASSERT_TRUE(size_stack(&P.fisa2) == 5);

}

void test_disparition_cartes_FISA(){
  Joueur joueur1;
  Joueur joueur2;
    joueur1.n_joueur=1;
    joueur2.n_joueur=2;
    joueur1.dd=0;
    joueur2.dd=0;
    joueur1.dev_eleve=1; 
    joueur1.dura_eleve=1; 
    joueur2.dev_eleve=1; 
    joueur2.dura_eleve=1;
  Plateau P = plateau_test(joueur1,joueur2,10);
  joueur1.PE = Calcul_PE(joueur1,P);
  joueur2.PE = Calcul_PE(joueur2,P);

  CU_ASSERT_EQUAL(joueur1.PE,5);
  CU_ASSERT_EQUAL(joueur2.PE,5);

  new_tour(&P);
  joueur1.PE = Calcul_PE(joueur1,P);
  joueur2.PE = Calcul_PE(joueur2,P);

  CU_ASSERT_EQUAL(joueur1.PE,15);
  CU_ASSERT_EQUAL(joueur2.PE,15);

}



 void test_augmentation_perso(){
  Joueur joueur1;
  Joueur joueur2;
    joueur1.n_joueur=1;
    joueur2.n_joueur=2;
    joueur1.dd=0;
    joueur2.dd=0;
    joueur1.dev_eleve=1; 
    joueur1.dura_eleve=1; 
    joueur2.dev_eleve=1; 
    joueur2.dura_eleve=1;
  Plateau P1 = plateau_test(joueur1,joueur2,5);

  CU_ASSERT_EQUAL(size_queue(P1.perso1),0);
  CU_ASSERT_EQUAL(size_queue(P1.perso2),0);
  
  Cartes A = initialisation(1);
  JouerCarteMain(&joueur1,&P1,&A);
  JouerCarteMain(&joueur2,&P1,&A);
  
  CU_ASSERT_EQUAL(size_queue(P1.perso1),1);
  CU_ASSERT_EQUAL(size_queue(P1.perso2),1);

  Cartes B = initialisation(2);
  JouerCarteMain(&joueur1,&P1,&B);
  JouerCarteMain(&joueur2,&P1,&B);

  CU_ASSERT_EQUAL(size_queue(P1.perso1),1);
  CU_ASSERT_EQUAL(size_queue(P1.perso2),1);

  new_tour(&P1); 

   Cartes C = initialisation(3);
  JouerCarteMain(&joueur1,&P1,&C);
  JouerCarteMain(&joueur2,&P1,&C);

  CU_ASSERT_EQUAL(size_queue(P1.perso1),2);
  CU_ASSERT_EQUAL(size_queue(P1.perso2),2);

  Cartes D = initialisation(4);
  JouerCarteMain(&joueur1,&P1,&D);
  JouerCarteMain(&joueur2,&P1,&D);

  CU_ASSERT_EQUAL(size_queue(P1.perso1),2);
  CU_ASSERT_EQUAL(size_queue(P1.perso2),2); 

  new_tour(&P1);
  new_tour(&P1);
  new_tour(&P1);
  new_tour(&P1);

  CU_ASSERT_EQUAL(size_queue(P1.perso1),2);
  CU_ASSERT_EQUAL(size_queue(P1.perso2),2);

  new_tour(&P1);

  Cartes E = initialisation(5);
  JouerCarteMain(&joueur1,&P1,&E);
  JouerCarteMain(&joueur2,&P1,&E);

  CU_ASSERT_EQUAL(size_queue(P1.perso1),3);
  CU_ASSERT_EQUAL(size_queue(P1.perso2),3);

  Cartes F = initialisation(6);
  JouerCarteMain(&joueur1,&P1,&F);
  JouerCarteMain(&joueur2,&P1,&F);

  CU_ASSERT_EQUAL(size_queue(P1.perso1),3);
  CU_ASSERT_EQUAL(size_queue(P1.perso2),3);
} 




void test_calcul_DD(){
  Joueur joueur1;
  Joueur joueur2;
    joueur1.n_joueur=1;
    joueur2.n_joueur=2;
    joueur1.dd=0;
    joueur2.dd=0;
    joueur1.dev_eleve=1; 
    joueur1.dura_eleve=1; 
    joueur2.dev_eleve=1; 
    joueur2.dura_eleve=1;
  Plateau P1 = plateau_test(joueur1,joueur2,6);

  CU_ASSERT_EQUAL(nb_carte_eleveFISA(joueur1,&P1)+1,5);
  CU_ASSERT_EQUAL(nb_carte_eleveFISA(joueur2,&P1)+1,5);
  CU_ASSERT_EQUAL(nb_carte_eleveFISE(joueur1,&P1)+1,5);
  CU_ASSERT_EQUAL(nb_carte_eleveFISE(joueur2,&P1)+1,5);


  CU_ASSERT_EQUAL(compteur_developpement(&P1,joueur1),5); 
  CU_ASSERT_EQUAL(compteur_developpement(&P1,joueur2),5); 
  CU_ASSERT_EQUAL(compteur_durab(&P1,joueur1),5); 
  CU_ASSERT_EQUAL(compteur_durab(&P1,joueur2),5);

  new_tour(&P1);

  CU_ASSERT_EQUAL(compteur_developpement(&P1,joueur1),10); 
  CU_ASSERT_EQUAL(compteur_developpement(&P1,joueur2),10); 
  CU_ASSERT_EQUAL(compteur_durab(&P1,joueur1),10); 
  CU_ASSERT_EQUAL(compteur_durab(&P1,joueur2),10);

  fin_de_tour(&P1,&joueur1,&joueur2);

  CU_ASSERT_EQUAL(joueur1.dd,0); 
  CU_ASSERT_EQUAL(joueur2.dd,0);

  Cartes A = initialisation(21); /* Carte ajouter 1 DD */
  JouerCarteMain(&joueur1,&P1,&A);
  JouerCarteMain(&joueur2,&P1,&A);

  CU_ASSERT_EQUAL(joueur1.dd,1); 
  CU_ASSERT_EQUAL(joueur2.dd,1);

  int i;
  for (i = 0; i < 5; i+=1) /* Ajout de 5 cartes FISE ches le joueur 1 */ 
  {
    Cartes eleve1;
      eleve1.dev=joueur1.dev_eleve;
      eleve1.dura=joueur1.dura_eleve;
    push_stack(&P1.fise1,eleve1);
  }

  fin_de_tour(&P1,&joueur1,&joueur2);

  CU_ASSERT_EQUAL(compteur_developpement(&P1,joueur1),15); 
  CU_ASSERT_EQUAL(compteur_developpement(&P1,joueur2),10); 
  CU_ASSERT_EQUAL(compteur_durab(&P1,joueur1),15); 
  CU_ASSERT_EQUAL(compteur_durab(&P1,joueur2),10);

  CU_ASSERT_EQUAL(joueur1.dd,6); /* A ce stade, le joueur 1 devrait avoir gagné 5 DD car 15-10 */
  CU_ASSERT_EQUAL(joueur2.dd,1); /* Le J2 lui prends 0 DD car 10-15 < 0 */

}

void test_effets_perso_UNIQUE(){
  Joueur joueur1;
  Joueur joueur2;
    joueur1.n_joueur=1;
    joueur2.n_joueur=2;
    joueur1.dd=0;
    joueur2.dd=0;
    joueur1.dev_eleve=1; 
    joueur1.dura_eleve=1; 
    joueur2.dev_eleve=1; 
    joueur2.dura_eleve=1;
  Plateau P1 = plateau_test(joueur1,joueur2,3);

  CU_ASSERT_EQUAL(compteur_developpement(&P1,joueur1),10); 
  CU_ASSERT_EQUAL(compteur_developpement(&P1,joueur2),10); 
  CU_ASSERT_EQUAL(compteur_durab(&P1,joueur1),10); 
  CU_ASSERT_EQUAL(compteur_durab(&P1,joueur2),10);



  Cartes A = initialisation(1); /* Test Carte "Thomas Lim" */
  JouerCarteMain(&joueur1,&P1,&A);

  CU_ASSERT_EQUAL(compteur_developpement(&P1,joueur1),15); /* On teste l'effet AA1 -> (5*2)+5 = 15 */ 
  CU_ASSERT_EQUAL(compteur_developpement(&P1,joueur2),10); 
  CU_ASSERT_EQUAL(compteur_durab(&P1,joueur1),10); 
  CU_ASSERT_EQUAL(compteur_durab(&P1,joueur2),10);





  Cartes B = initialisation(2); /* Test Carte "Marie Szafranski" */
  JouerCarteMain(&joueur1,&P1,&B);

  CU_ASSERT_EQUAL(compteur_developpement(&P1,joueur1),15);  
  CU_ASSERT_EQUAL(compteur_developpement(&P1,joueur2),10); 
  CU_ASSERT_EQUAL(compteur_durab(&P1,joueur1),15); /* On teste l'effet AA2 -> (5*2)+5 = 15 */
  CU_ASSERT_EQUAL(compteur_durab(&P1,joueur2),10);




  Cartes C = initialisation(3); /* Test Carte "Alain Faye" */
  JouerCarteMain(&joueur1,&P1,&C);

  CU_ASSERT_EQUAL(compteur_developpement(&P1,joueur1),20); /* On teste l'effet AA2 -> (5*2)+(5*2) = 20 */
  CU_ASSERT_EQUAL(compteur_developpement(&P1,joueur2),10); 
  CU_ASSERT_EQUAL(compteur_durab(&P1,joueur1),15); 
  CU_ASSERT_EQUAL(compteur_durab(&P1,joueur2),10);




  Cartes D = initialisation(4); /* Test Carte "Christophe Mouilleron" */
  JouerCarteMain(&joueur1,&P1,&D);

  CU_ASSERT_EQUAL(compteur_developpement(&P1,joueur1),20); 
  CU_ASSERT_EQUAL(compteur_developpement(&P1,joueur2),10); 
  CU_ASSERT_EQUAL(compteur_durab(&P1,joueur1),20); 
  CU_ASSERT_EQUAL(compteur_durab(&P1,joueur2),10);




  Cartes E = initialisation(5); /* Test Carte "Stefania Dumbrava" */
  JouerCarteMain(&joueur2,&P1,&E);                     /* C'est maintenant le J2 qui va retirer des points */ 
  JouerCarteMain(&joueur1,&P1,&E);                     /* Ainsi que le J1 */

  CU_ASSERT_EQUAL(compteur_developpement(&P1,joueur1),15); /* On repasse a 15 */
  CU_ASSERT_EQUAL(compteur_developpement(&P1,joueur2),5);  /* on descend a 5 */
  CU_ASSERT_EQUAL(compteur_durab(&P1,joueur1),20); 
  CU_ASSERT_EQUAL(compteur_durab(&P1,joueur2),10);


  Cartes F = initialisation(6); /* Test Carte "Julien Forest" */
  JouerCarteMain(&joueur2,&P1,&F);

  CU_ASSERT_EQUAL(compteur_developpement(&P1,joueur1),15); 
  CU_ASSERT_EQUAL(compteur_developpement(&P1,joueur2),5); 
  CU_ASSERT_EQUAL(compteur_durab(&P1,joueur1),15); 
  CU_ASSERT_EQUAL(compteur_durab(&P1,joueur2),10);



  Cartes G = initialisation(7); /* Test Carte "Nicolas Brunel" */
  JouerCarteMain(&joueur2,&P1,&G);

  CU_ASSERT_EQUAL(compteur_developpement(&P1,joueur1),10); 
  CU_ASSERT_EQUAL(compteur_developpement(&P1,joueur2),5); 
  CU_ASSERT_EQUAL(compteur_durab(&P1,joueur1),15); 
  CU_ASSERT_EQUAL(compteur_durab(&P1,joueur2),10);
  


  Cartes H = initialisation(8); /* Test Carte "Laurence Bourard" */
  JouerCarteMain(&joueur2,&P1,&H);

  CU_ASSERT_EQUAL(compteur_developpement(&P1,joueur1),10); 
  CU_ASSERT_EQUAL(compteur_developpement(&P1,joueur2),5); 
  CU_ASSERT_EQUAL(compteur_durab(&P1,joueur1),10); 
  CU_ASSERT_EQUAL(compteur_durab(&P1,joueur2),10);

}


void test_effets_perso_MULTIPLES_1(){
  Joueur joueur1;
  Joueur joueur2;
    joueur1.n_joueur=1;
    joueur2.n_joueur=2;
    joueur1.dd=0;
    joueur2.dd=0;
    joueur1.dev_eleve=1; 
    joueur1.dura_eleve=1; 
    joueur2.dev_eleve=1; 
    joueur2.dura_eleve=1;
  Plateau P1 = plateau_test(joueur1,joueur2,3);
  int i;
  for (i = 0; i < 5; i+=1) /* Ajout de 5 cartes FISE et FISA dans les piles */ 
  {
    Cartes eleve1;
    Cartes eleve2;
      eleve1.dev=joueur1.dev_eleve;
      eleve2.dev=joueur2.dev_eleve;
      eleve1.dura=joueur1.dura_eleve;
      eleve2.dura=joueur2.dura_eleve;
    push_stack(&P1.fise1,eleve1);
    push_stack(&P1.fise2,eleve2);
  }
  for (i = 0; i < 5; i+=1)
  {
    Cartes fisa1;
    Cartes fisa2;
      fisa1.dev=joueur1.dev_eleve;
      fisa2.dev=joueur2.dev_eleve;
      fisa1.dura=joueur1.dura_eleve;
      fisa2.dura=joueur2.dura_eleve;
    push_stack(&P1.fisa1,fisa1);
    push_stack(&P1.fisa2,fisa2);
  }
  /* A partir d'ici, chaque joueur possede 10 cartes FISE et FISA */ 
  CU_ASSERT_EQUAL(compteur_developpement(&P1,joueur1),20); 
  CU_ASSERT_EQUAL(compteur_developpement(&P1,joueur2),20); 
  CU_ASSERT_EQUAL(compteur_durab(&P1,joueur1),20); 
  CU_ASSERT_EQUAL(compteur_durab(&P1,joueur2),20);


  Cartes A = initialisation(9); /* Test Carte "Dimitri Watel" */
  JouerCarteMain(&joueur2,&P1,&A);

  CU_ASSERT_EQUAL(compteur_developpement(&P1,joueur1),20); 
  CU_ASSERT_EQUAL(compteur_developpement(&P1,joueur2),40); 
  CU_ASSERT_EQUAL(compteur_durab(&P1,joueur1),20); 
  CU_ASSERT_EQUAL(compteur_durab(&P1,joueur2),20); 



  Cartes B = initialisation(10); /* Test Carte "Vitera Y" */
  JouerCarteMain(&joueur2,&P1,&B);

  CU_ASSERT_EQUAL(compteur_developpement(&P1,joueur1),20); 
  CU_ASSERT_EQUAL(compteur_developpement(&P1,joueur2),40); 
  CU_ASSERT_EQUAL(compteur_durab(&P1,joueur1),20); 
  CU_ASSERT_EQUAL(compteur_durab(&P1,joueur2),40); 


  Cartes C = initialisation(11); /* Test Carte "Kevin Goilard" LE SANG ! */
  JouerCarteMain(&joueur1,&P1,&C);   /* Le joueur 1 joue afin de ramener les deux joueurs a egalité */

  CU_ASSERT_EQUAL(compteur_developpement(&P1,joueur1),20); 
  CU_ASSERT_EQUAL(compteur_developpement(&P1,joueur2),20); 
  CU_ASSERT_EQUAL(compteur_durab(&P1,joueur1),20); 
  CU_ASSERT_EQUAL(compteur_durab(&P1,joueur2),40);


  Cartes D = initialisation(12); /* Test Carte "Vincent Jeannas" */
  JouerCarteMain(&joueur1,&P1,&D);  

  CU_ASSERT_EQUAL(compteur_developpement(&P1,joueur1),20); 
  CU_ASSERT_EQUAL(compteur_developpement(&P1,joueur2),20); 
  CU_ASSERT_EQUAL(compteur_durab(&P1,joueur1),20); 
  CU_ASSERT_EQUAL(compteur_durab(&P1,joueur2),20);




  fin_de_tour(&P1,&joueur1,&joueur2);
  CU_ASSERT_EQUAL(joueur1.dd,0); 
  CU_ASSERT_EQUAL(joueur2.dd,0);




  Cartes E = initialisation(14); /* Test Carte "Anne-Laure Ligozat" */
  JouerCarteMain(&joueur2,&P1,&E);  

  fin_de_tour(&P1,&joueur1,&joueur2);

  CU_ASSERT_EQUAL(joueur1.dd,0);  
  CU_ASSERT_EQUAL(joueur2.dd,2); /* La carte ajoute 2 DD a celui qui la joue */



  Cartes F = initialisation(15); /* Test Carte "Catherine Dubois" */
  JouerCarteMain(&joueur1,&P1,&F);  

  fin_de_tour(&P1,&joueur1,&joueur2);


  CU_ASSERT_EQUAL(joueur1.dd,0);  
  CU_ASSERT_EQUAL(joueur2.dd,2); /* La carte ajoute 2 DD a celui qui la joue et on lui en retire 2 donc le nombre de DD reste inchangé */

}


void test_effets_perso_MULTIPLES_2(){
  Joueur joueur1;
  Joueur joueur2;
    joueur1.n_joueur=1;
    joueur2.n_joueur=2;
    joueur1.dd=0;
    joueur2.dd=0;
    joueur1.dev_eleve= 1; 
    joueur1.dura_eleve=1; 
    joueur2.dev_eleve=1; 
    joueur2.dura_eleve=1;
  Plateau P1 = plateau_test(joueur1,joueur2,3);
  int i;
  for (i = 0; i < 5; i+=1) /* Ajout de 5 cartes FISE et FISA dans les piles */ 
  {
    Cartes eleve1;
    Cartes eleve2;
      eleve1.dev=joueur1.dev_eleve;
      eleve2.dev=joueur2.dev_eleve;
      eleve1.dura=joueur1.dura_eleve;
      eleve2.dura=joueur2.dura_eleve;
    push_stack(&P1.fise1,eleve1);
    push_stack(&P1.fise2,eleve2);
  }
  for (i = 0; i < 5; i+=1)
  {
    Cartes fisa1;
    Cartes fisa2;
      fisa1.dev=joueur1.dev_eleve;
      fisa2.dev=joueur2.dev_eleve;
      fisa1.dura=joueur1.dura_eleve;
      fisa2.dura=joueur2.dura_eleve;
    push_stack(&P1.fisa1,fisa1);
    push_stack(&P1.fisa2,fisa2);
  }
  /* A partir d'ici, chaque joueur possede 10 cartes FISE et FISA */ 
  CU_ASSERT_EQUAL(compteur_developpement(&P1,joueur1),20); 
  CU_ASSERT_EQUAL(compteur_developpement(&P1,joueur2),20); 
  CU_ASSERT_EQUAL(compteur_durab(&P1,joueur1),20); 
  CU_ASSERT_EQUAL(compteur_durab(&P1,joueur2),20);

  fin_de_tour(&P1,&joueur1,&joueur2);

  CU_ASSERT_EQUAL(joueur1.dd,0);  
  CU_ASSERT_EQUAL(joueur2.dd,0);


  Cartes A = initialisation(16); /* Test Carte "Eric Lejeune" */
  JouerCarteMain(&joueur1,&P1,&A);

  CU_ASSERT_EQUAL(compteur_developpement(&P1,joueur1),30); 
  CU_ASSERT_EQUAL(compteur_developpement(&P1,joueur2),20); 
  CU_ASSERT_EQUAL(compteur_durab(&P1,joueur1),30); 
  CU_ASSERT_EQUAL(compteur_durab(&P1,joueur2),10);

  fin_de_tour(&P1,&joueur1,&joueur2);

  CU_ASSERT_EQUAL(joueur1.dd,20);  
  CU_ASSERT_EQUAL(joueur2.dd,0);



  Cartes B = initialisation(17); /* Test Carte "Christine Mathias" */
  JouerCarteMain(&joueur1,&P1,&B);

  CU_ASSERT_EQUAL(compteur_developpement(&P1,joueur1),40); 
  CU_ASSERT_EQUAL(compteur_developpement(&P1,joueur2),20); 
  CU_ASSERT_EQUAL(compteur_durab(&P1,joueur1),40); 
  CU_ASSERT_EQUAL(compteur_durab(&P1,joueur2),0);

  fin_de_tour(&P1,&joueur1,&joueur2);
    
  CU_ASSERT_EQUAL(joueur1.dd,60);  
  CU_ASSERT_EQUAL(joueur2.dd,0);  



  Cartes C = initialisation(18);  /* Test Carte "Katrin Salhab"  */
  JouerCarteMain(&joueur2,&P1,&C);   


  CU_ASSERT_EQUAL(compteur_developpement(&P1,joueur1),40); 
  CU_ASSERT_EQUAL(compteur_developpement(&P1,joueur2),40); 
  CU_ASSERT_EQUAL(compteur_durab(&P1,joueur1),40); 
  CU_ASSERT_EQUAL(compteur_durab(&P1,joueur2),20); 



  
  Cartes D = initialisation(19);  /* Test Carte "Abass Sagna"  */
  JouerCarteMain(&joueur2,&P1,&D);   


  CU_ASSERT_EQUAL(compteur_developpement(&P1,joueur1),40); 
  CU_ASSERT_EQUAL(compteur_developpement(&P1,joueur2),60); 
  CU_ASSERT_EQUAL(compteur_durab(&P1,joueur1),40); 
  CU_ASSERT_EQUAL(compteur_durab(&P1,joueur2),40); 


  Cartes E = initialisation(20);  /* Test Carte "Laurent Prével"  */
  JouerCarteMain(&joueur2,&P1,&E);   


  CU_ASSERT_EQUAL(compteur_developpement(&P1,joueur1),40); 
  CU_ASSERT_EQUAL(compteur_developpement(&P1,joueur2),100); 
  CU_ASSERT_EQUAL(compteur_durab(&P1,joueur1),40); 
  CU_ASSERT_EQUAL(compteur_durab(&P1,joueur2),80); 

  fin_de_tour(&P1,&joueur1,&joueur2);


  CU_ASSERT_EQUAL(joueur1.dd,60);  
  CU_ASSERT_EQUAL(joueur2.dd,60);  

}



void test_effets_actions(){
  Joueur joueur1;
  Joueur joueur2;
    joueur1.n_joueur=1;
    joueur2.n_joueur=2;
    joueur1.dd=0;
    joueur2.dd=0;
    joueur1.dev_eleve=1; 
    joueur1.dura_eleve=1; 
    joueur2.dev_eleve=1; 
    joueur2.dura_eleve=1;
  Plateau P1 = plateau_test(joueur1,joueur2,3);
  int i;
  for (i = 0; i < 5; i+=1) /* Ajout de 5 cartes FISE et FISA dans les piles */ 
  {
    Cartes eleve1;
    Cartes eleve2;
      eleve1.dev=joueur1.dev_eleve;
      eleve2.dev=joueur2.dev_eleve;
      eleve1.dura=joueur1.dura_eleve;
      eleve2.dura=joueur2.dura_eleve;
    push_stack(&P1.fise1,eleve1);
    push_stack(&P1.fise2,eleve2);
  }
  for (i = 0; i < 5; i+=1)
  {
    Cartes fisa1;
    Cartes fisa2;
      fisa1.dev=joueur1.dev_eleve;
      fisa2.dev=joueur2.dev_eleve;
      fisa1.dura=joueur1.dura_eleve;
      fisa2.dura=joueur2.dura_eleve;
    push_stack(&P1.fisa1,fisa1);
    push_stack(&P1.fisa2,fisa2);
  }
  /* A partir d'ici, chaque joueur possede 10 cartes FISE et FISA */ 
  CU_ASSERT_EQUAL(compteur_developpement(&P1,joueur1),20); 
  CU_ASSERT_EQUAL(compteur_developpement(&P1,joueur2),20); 
  CU_ASSERT_EQUAL(compteur_durab(&P1,joueur1),20); 
  CU_ASSERT_EQUAL(compteur_durab(&P1,joueur2),20);

  fin_de_tour(&P1,&joueur1,&joueur2);

  CU_ASSERT_EQUAL(joueur1.dd,0);  
  CU_ASSERT_EQUAL(joueur2.dd,0);

  Cartes A = initialisation(21);  /* Test Carte "Cours Développement Durable" */
  JouerCarteMain(&joueur2,&P1,&A);   


  CU_ASSERT_EQUAL(joueur2.dd,1);  
  CU_ASSERT_EQUAL(joueur1.dd,0);




  Cartes B = initialisation(23);   /* Test Carte "Rentrée FISE"  */
  JouerCarteMain(&joueur1,&P1,&B);   

  CU_ASSERT_EQUAL(size_stack(&P1.fise1)+1,11);
  CU_ASSERT_EQUAL(size_stack(&P1.fise2)+1,10);
  CU_ASSERT_EQUAL(size_stack(&P1.fisa1)+1,10);
  CU_ASSERT_EQUAL(size_stack(&P1.fisa2)+1,10); 


  
  Cartes C = initialisation(24);  /* Test Carte "Rentrée FISA"  */
  JouerCarteMain(&joueur1,&P1,&C); 

  CU_ASSERT_EQUAL(size_stack(&P1.fise1)+1,11);
  CU_ASSERT_EQUAL(size_stack(&P1.fise2)+1,10);
  CU_ASSERT_EQUAL(size_stack(&P1.fisa1)+1,11);
  CU_ASSERT_EQUAL(size_stack(&P1.fisa2)+1,10);


  joueur1.PE = Calcul_PE(joueur1,P1);
  joueur2.PE = Calcul_PE(joueur2,P1);

  CU_ASSERT_EQUAL(joueur1.PE,33);  
  CU_ASSERT_EQUAL(joueur2.PE,30);

  
   Cartes D = initialisation(25);  /* Test Carte "Energie verte"  */
  JouerCarteMain(&joueur1,&P1,&D); 

  CU_ASSERT_EQUAL(joueur1.PE,39);  /* 33+6 = 38 */
  CU_ASSERT_EQUAL(joueur2.PE,30);

  

  Cartes E = initialisation(26);   /* Test Carte "Diplomation"  */
  JouerCarteMain(&joueur1,&P1,&E);   

  CU_ASSERT_EQUAL(size_stack(&P1.fise1)+1,11);
  CU_ASSERT_EQUAL(size_stack(&P1.fisa1)+1,11);
  CU_ASSERT_EQUAL(size_stack(&P1.fise2)+1,9);
  CU_ASSERT_EQUAL(size_stack(&P1.fisa2)+1,9);


  CU_ASSERT_EQUAL(compteur_developpement(&P1,joueur1),22); 
  CU_ASSERT_EQUAL(compteur_developpement(&P1,joueur2),18); 
  CU_ASSERT_EQUAL(compteur_durab(&P1,joueur1),22); 
  CU_ASSERT_EQUAL(compteur_durab(&P1,joueur2),18); 



  Cartes F = initialisation(29);   /* Test Carte "Zero Papier"  */
  JouerCarteMain(&joueur1,&P1,&F);  

  CU_ASSERT_EQUAL(size_stack(&P1.fise1)+1,11);
  CU_ASSERT_EQUAL(size_stack(&P1.fisa1)+1,11);
  CU_ASSERT_EQUAL(size_stack(&P1.fise2)+1,9);
  CU_ASSERT_EQUAL(size_stack(&P1.fisa2)+1,9); 


  CU_ASSERT_EQUAL(compteur_developpement(&P1,joueur1),44); 
  CU_ASSERT_EQUAL(compteur_developpement(&P1,joueur2),18); 
  CU_ASSERT_EQUAL(compteur_durab(&P1,joueur1),22); 
  CU_ASSERT_EQUAL(compteur_durab(&P1,joueur2),18); 


  Cartes G = initialisation(30);   /* Test Carte "Repas végétarien"  */
  JouerCarteMain(&joueur2,&P1,&G);  

  CU_ASSERT_EQUAL(size_stack(&P1.fise1)+1,11);
  CU_ASSERT_EQUAL(size_stack(&P1.fisa1)+1,11);
  CU_ASSERT_EQUAL(size_stack(&P1.fise2)+1,9);
  CU_ASSERT_EQUAL(size_stack(&P1.fisa2)+1,9); 


  CU_ASSERT_EQUAL(compteur_developpement(&P1,joueur1),44); 
  CU_ASSERT_EQUAL(compteur_developpement(&P1,joueur2),18); 
  CU_ASSERT_EQUAL(compteur_durab(&P1,joueur1),22); 
  CU_ASSERT_EQUAL(compteur_durab(&P1,joueur2),36);


  Cartes H = initialisation(31);   /* Test Carte "Fermeture annuelle"  */
  JouerCarteMain(&joueur2,&P1,&H);  

  CU_ASSERT_EQUAL(size_stack(&P1.fise1)+1,0);
  CU_ASSERT_EQUAL(size_stack(&P1.fisa1)+1,0);
  CU_ASSERT_EQUAL(size_stack(&P1.fise2)+1,0);
  CU_ASSERT_EQUAL(size_stack(&P1.fisa2)+1,0); 


  CU_ASSERT_EQUAL(compteur_developpement(&P1,joueur1),0); 
  CU_ASSERT_EQUAL(compteur_developpement(&P1,joueur2),0); 
  CU_ASSERT_EQUAL(compteur_durab(&P1,joueur1),0); 
  CU_ASSERT_EQUAL(compteur_durab(&P1,joueur2),0);
}




/* LES TESTS SONT FINIS LES GARS !!!! */

int main() {
  CU_pSuite pSuite = NULL;
  if (CUE_SUCCESS != CU_initialize_registry() )  {    
    return CU_get_error();
    }
    pSuite = CU_add_suite( "max_test_suite", init_suite, clean_suite ); 
    if ( NULL == pSuite ) {       
      CU_cleanup_registry();       
      return CU_get_error();    
      }
    if ( (NULL == CU_add_test(pSuite, "Test de la strucure", test_structure)) ||
         (NULL == CU_add_test(pSuite, "Test de la creation Plateau", test_creation_plateau)) || 
         (NULL == CU_add_test(pSuite, "Test de l'ajout d'une carte eleve", test_ajout_carte_eleve)) ||
         (NULL == CU_add_test(pSuite, "Test disparition FISA / Calcul PE", test_disparition_cartes_FISA)) ||
         (NULL == CU_add_test(pSuite, "Test augmentation perso", test_augmentation_perso)) ||
         (NULL == CU_add_test(pSuite, "Test calcul DD", test_calcul_DD)) ||
         (NULL == CU_add_test(pSuite, "Test effets des cartes perso relatifs (avec un unique effet)", test_effets_perso_UNIQUE)) ||
         (NULL == CU_add_test(pSuite, "Test effets des cartes perso (avec effets multiples) 1", test_effets_perso_MULTIPLES_1)) ||
         (NULL == CU_add_test(pSuite, "Test effets des cartes perso (avec effets multiples) 2", test_effets_perso_MULTIPLES_2)) ||
         (NULL == CU_add_test(pSuite, "Test effets des cartes actions", test_effets_actions))){
      CU_cleanup_registry();       
      return CU_get_error();
      }

    CU_basic_set_mode(CU_BRM_VERBOSE);      
    CU_basic_run_tests();      
    printf("\n");      
    CU_basic_show_failures(CU_get_failure_list());     
    printf("\n\n"); 

    CU_cleanup_registry();       
    return CU_get_error();
}
   


