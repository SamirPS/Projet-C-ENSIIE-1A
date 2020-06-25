#include <stdio.h>
#include <stdlib.h>
#include "../headers/plateau.h"


void jouerEleve(Joueur J,Plateau *x, Cartes ajouer){
  if (J.n_joueur==1){
    if(ajouer.num == 32) { 
      push_stack(&x->fise1,ajouer); 
      }
      
    else {
      push_stack(&x->fisa1,ajouer);
      }
  }
  else{
    if(ajouer.num == 32) {
      push_stack(&x->fise2,ajouer);
    }
    else { push_stack(&x->fisa2,ajouer);
  }
}
}

void JouerCarteMain(Joueur* J,Plateau *x, Cartes* ajouer){

  int n_tour = x->n_tour;
  if (J->n_joueur==1){
    if (ajouer->num <= 20 && ajouer->num >= 1) /* Le joueur compte jouer une carte perso */
    { 
      if (n_tour < 6) /* Condition de jeu pour le numero de tour */
    {
      if ( size_queue(x->perso1)==1) {
        push_stack(&x->defausse1,pop_queue(x->perso1)); /* J'envoie la premiere carte jouée dans la defausse */
        push_queue(x->perso1,*ajouer);
      }
      else
      {
        push_queue(x->perso1,*ajouer);
      }
      }
      else if (n_tour < 11)
      {
        if ( size_queue(x->perso1) == 2) {
        push_stack(&x->defausse1,pop_queue(x->perso1)); /* J'envoie la premiere carte jouée dans la defausse */
        push_queue(x->perso1,*ajouer);
        }
        else
        {
          push_queue(x->perso1,*ajouer);
        }
        }
        else
        {
          if ( size_queue(x->perso1) == 3) {
        push_stack(&x->defausse1,pop_queue(x->perso1)); /* J'envoie la premiere carte jouée dans la defausse */
        push_queue(x->perso1,*ajouer);
        }
        else
        {
          push_queue(x->perso1,*ajouer);
        }
        }
        
       
      int i;
      stack new_fise; /* a chaque carte perso je recupere le tableau d'effet */
      stack new_fisa;
      for ( i = 0; i < 12; i+=1){  /* listing des effets correspondant a chaque effet */
                  switch(ajouer->effet[i]){ 
                    case 1:;  /*AE1*/
                         new_fise = creation_stack();
                        while (!is_stack_empty(x->fise1))
                          {
                            
                            Cartes new_carte = pop_stack(&x->fise1);
                            new_carte.dev +=1;
                            push_stack(&new_fise,new_carte);
                          }
                        while (!is_stack_empty(new_fise))
                        {
                          push_stack(&x->fise1, pop_stack(&new_fise));
                        }
                  
                        
                        break;


                    case 2:; /*AE2*/
                         new_fise = creation_stack();
                        while (!is_stack_empty(x->fise1))
                          {
                            
                            Cartes new_carte = pop_stack(&x->fise1);
                            new_carte.dura+=1;
                            push_stack(&new_fise,new_carte);
                          }
                        while (!is_stack_empty(new_fise))
                        {
                          push_stack(&x->fise1, pop_stack(&new_fise));
                        }

                        break;



                      case 3:; /*AA1*/
                         new_fisa = creation_stack();
                        while (x->fisa1.top != -1)
                          {
                            
                            Cartes new_carte = pop_stack(&x->fisa1);
                            new_carte.dev +=1;
                            push_stack(&new_fisa,new_carte);
                          }
                        while (new_fisa.top != -1)
                        {
                          push_stack(&x->fisa1, pop_stack(&new_fisa));
                        }
                        break;



                      case 4:; /*AA2*/
                         new_fisa = creation_stack();
                        while (!is_stack_empty(x->fisa1))
                          {
                            
                            Cartes new_carte = pop_stack(&x->fisa1);
                            new_carte.dura+=1;
                            push_stack(&new_fisa,new_carte);
                          }

                        while (!is_stack_empty(new_fisa))
                        {
                          push_stack(&x->fisa1, pop_stack(&new_fisa));
                        }
                        break;

                      case 5:; /*RE1*/
                         new_fise = creation_stack();
                        while (!is_stack_empty(x->fise2))
                          {
                            
                            Cartes new_carte = pop_stack(&x->fise2);
                            new_carte.dev-= 1;
                            push_stack(&new_fise,new_carte);
                          }
                        while (!is_stack_empty(new_fise))
                        {
                          push_stack(&x->fise2, pop_stack(&new_fise));
                        }
                        break;

                      case 6:; /*RE2*/
                         new_fise = creation_stack();
                        while (!is_stack_empty(x->fise2))
                          {
                            
                            Cartes new_carte = pop_stack(&x->fise2);
                            new_carte.dura-= 1;
                            push_stack(&new_fise,new_carte);
                          }

                        while (!is_stack_empty(new_fise))
                        {
                          push_stack(&x->fise2, pop_stack(&new_fise));
                        }

                        break;

                      case 7:; /*RA2*/
                         new_fisa = creation_stack();
                        while (!is_stack_empty(x->fisa2))
                          {
                            
                            Cartes new_carte = pop_stack(&x->fisa2);
                            new_carte.dev-= 1;
                            push_stack(&new_fisa,new_carte);
                          }
                        while (!is_stack_empty(new_fisa))
                        {
                          push_stack(&x->fisa2, pop_stack(&new_fisa));
                        }
                        break;
                      
                      case 8:; /*RA2*/
                        new_fisa = creation_stack();
                        while (!is_stack_empty(x->fisa2))
                          {
                            
                            Cartes new_carte = pop_stack(&x->fisa2);
                            new_carte.dura-= 1;
                            push_stack(&new_fisa,new_carte);
                          }
                        while (!is_stack_empty(new_fisa))
                        {
                          push_stack(&x->fisa2, pop_stack(&new_fisa));
                        }
                        break;

                    

                        
                  
                  }

      
    } 
    pop_ieme_carte(trouver_num(&x->main1,ajouer->num),&x->main1);
  }
  else /* Le joueur veut jouer une carte action */ 
  { if(ajouer->num != 0) {
    push_stack(&x->defausse1,*ajouer); /* je la met dans la pile defausse1 */ 
    jouerAction(x,J,ajouer);
    pop_ieme_carte(trouver_num(&x->main1,ajouer->num),&x->main1); 
    }
    
    }
    
  }
  else /* Joueur 2 */ 
  {
    if (ajouer->num <= 20 && ajouer->num >=1) /* Le joueur compte jouer une carte perso */
    {
      if (n_tour < 6) /* Condition de jeu pour le numero de tour */
    {
      if ( size_queue(x->perso2) == 1) {
        push_stack(&x->defausse2,pop_queue(x->perso2)); /* J'envoie la premiere carte jouée dans la defausse */
        push_queue(x->perso2,*ajouer);
      }
      else
      {
        push_queue(x->perso2,*ajouer);
      }
      }
      else if (n_tour < 11)
      {
        if ( size_queue(x->perso2) == 2) {
        push_stack(&x->defausse2,pop_queue(x->perso2)); /* J'envoie la premiere carte jouée dans la defausse */
        push_queue(x->perso2,*ajouer);
        }
        else
        {
          push_queue(x->perso2,*ajouer);
        }
        }
        else
        {
          if ( size_queue(x->perso2) ==3) {
        push_stack(&x->defausse2,pop_queue(x->perso2)); /* J'envoie la premiere carte jouée dans la defausse */
        push_queue(x->perso2,*ajouer);
        }
        else
        {
          push_queue(x->perso2,*ajouer);
        }
        }

       /* a chaque carte perso je recupere le tableau d'effet */
      int i;
      stack new_fise;
      stack  new_fisa;

      for ( i = 0; i < 12; i+=1){  /* listing des effets correspondant a chaque effet */
                  switch(ajouer->effet[i]){ 
                    case 1:;  /*AE1*/
                        new_fise = creation_stack();
                        while (!is_stack_empty(x->fise2))
                        {
                          Cartes new_carte = pop_stack(&x->fise2);
                            new_carte.dev+=1;
                            push_stack(&new_fise,new_carte);
                        }
                         while (!is_stack_empty(new_fise))
                        {
                          push_stack(&x->fise2, pop_stack(&new_fise));
                        }
                  
                        
                        break;


                    case 2:; /*AE2*/
                         new_fise = creation_stack();
                        while (!is_stack_empty(x->fise2))
                          {
                            
                            Cartes new_carte = pop_stack(&x->fise2);
                            new_carte.dura+=1;
                            push_stack(&new_fise,new_carte);
                          }
                        while (!is_stack_empty(new_fise))
                        {
                          push_stack(&x->fise2, pop_stack(&new_fise));
                        }

                        break;



                      case 3:; /*AA1*/
                        new_fisa = creation_stack();
                        while (x->fisa2.top != -1)
                          {
                            
                            Cartes new_carte = pop_stack(&x->fisa2);
                            new_carte.dev+=1;
                            push_stack(&new_fisa,new_carte);
                          }
                        while (new_fisa.top != -1)
                        {
                          push_stack(&x->fisa2, pop_stack(&new_fisa));
                        }
                        break;



                      case 4:; /*AA2*/
                        new_fisa = creation_stack();
                        while (!is_stack_empty(x->fisa2))
                          {
                            
                            Cartes new_carte = pop_stack(&x->fisa2);
                            new_carte.dura+=1;
                            push_stack(&new_fisa,new_carte);
                          }

                        while (!is_stack_empty(new_fisa))
                        {
                          push_stack(&x->fisa2, pop_stack(&new_fisa));
                        }
                        break;

                      case 5:; /*RE1*/
                        new_fise = creation_stack();
                         while (!is_stack_empty(x->fise1))
                          {
                            
                            Cartes new_carte = pop_stack(&x->fise1);
                            new_carte.dev-= 1;
                            push_stack(&new_fise,new_carte);
                          }
                        while (!is_stack_empty(new_fise))
                        {
                          push_stack(&x->fise1, pop_stack(&new_fise));
                        }
                        break;

                      case 6:; /*RE2*/
                        new_fise = creation_stack();
                        while (!is_stack_empty(x->fise1))
                          {
                            
                            Cartes new_carte = pop_stack(&x->fise1);
                            new_carte.dura-= 1;
                            push_stack(&new_fise,new_carte);
                          }

                        while (!is_stack_empty(new_fise))
                        {
                          push_stack(&x->fise1, pop_stack(&new_fise));
                        }

                        break;

                      case 7:; /*RA2*/
                        new_fisa = creation_stack();
                        while (!is_stack_empty(x->fisa1))
                          {
                            
                            Cartes new_carte = pop_stack(&x->fisa1);
                            new_carte.dev-= 1;
                            push_stack(&new_fisa,new_carte);
                          }
                        while (!is_stack_empty(new_fisa))
                        {
                          push_stack(&x->fisa1, pop_stack(&new_fisa));
                        }
                        break;
                      
                      case 8:; /*RA2*/
                        new_fisa = creation_stack();
                        while (!is_stack_empty(x->fisa1))
                          {
                            
                            Cartes new_carte = pop_stack(&x->fisa1);
                            new_carte.dura-= 1;
                            push_stack(&new_fisa,new_carte);
                          }
                        while (!is_stack_empty(new_fisa))
                        {
                          push_stack(&x->fisa1, pop_stack(&new_fisa));
                        }
                        break;

                    

                        
                  
                  }

      
    }
    pop_ieme_carte(trouver_num(&x->main2,ajouer->num),&x->main2);
  }
  else /* Le joueur veut jouer une carte action */ 
  {
    if(ajouer->num != 0) {
    push_stack(&x->defausse2,*ajouer); /* je la met dans la pile defausse1 */ 
    jouerAction(x,J,ajouer);
    pop_ieme_carte(trouver_num(&x->main2,ajouer->num),&x->main2); 
    }
    }
    
  }
  
  

}

void jouerAction(Plateau *P, Joueur* J,Cartes *C){
  switch (C->num)
  {
  case 21:
    J->dd+=1;
    break;

  case 22:
    piocher_carte(P,*J);
    break;

  case 23:;
    Cartes FISE;
    FISE.num = 32; /* Création d'une carte fise*/
    FISE.dev=J->dev_eleve;
    FISE.dura=J->dura_eleve;
    if (J->n_joueur ==1){
      push_stack(&P->fise1,FISE);
    }
    else
    {
      push_stack(&P->fise2,FISE);
    }
    J->PE +=1;
    break;

  case 24:;
    Cartes FISA; /* Création d'une carte fisa */
    FISA.num = 33; /* Création d'une carte fise*/
    FISA.dev=J->dev_eleve;
    FISA.dura=J->dura_eleve;
    if (J->n_joueur ==1){
      push_stack(&P->fisa1,FISA);
    }
    else
    {
      push_stack(&P->fisa2,FISA);
    }
    if(parite_tour(*P)){
      
      J->PE +=2;
      }

    break;

  case 25:
    J->PE += 6;
  break;

  case 26:
    if (J->n_joueur ==1){
      free(pop_stack(&P->fise2).effet);
      free(pop_stack(&P->fisa2).effet);
    }
    else
    {
      free(pop_stack(&P->fise1).effet);
      free(pop_stack(&P->fisa1).effet);
    }
    break;

    case 27:
    if (J->n_joueur == 1) {
      if (!is_queue_empty(*P->perso2))
      {
        push_stack(&P->defausse2,pop_queue(P->perso2));
      }
    }
        
    else
    {
      if (!is_queue_empty(*P->perso2))
      {
      push_stack(&P->defausse1,pop_queue(P->perso1));
      }
    }
    break;

    case 28: /* semi copié collé de create_deck() */
    if (J->n_joueur == 1)
    {
     stack tab = creation_stack();
     while (!is_stack_empty(P->defausse1))
     {
       push_stack(&tab,pop_stack(&P->defausse1));
     }
      while (!is_stack_empty(P->deck1))
     {
       push_stack(&tab,pop_stack(&P->deck1));
     }
      int taille_new_deck = size_stack(&tab);
      while (tab.top!=-1)
      {
        int a = rand()%(taille_new_deck+1);
        push_stack(&P->deck1,pop_ieme_carte(a,&tab));
        taille_new_deck-= 1;
        
      }
      }
      else
      {
     stack tab = creation_stack();
     while (!is_stack_empty(P->defausse2))
     {
       push_stack(&tab,pop_stack(&P->defausse2));
     }
      while (!is_stack_empty(P->deck2))
     {
       push_stack(&tab,pop_stack(&P->deck2));
     }
      int taille_new_deck = size_stack(&tab);
      while (tab.top!=-1)
      {
        int a = rand()%(taille_new_deck+1);
        push_stack(&P->deck2,pop_ieme_carte(a,&tab));
        taille_new_deck-= 1;
        
      }
      }
      break;

    case 29:
    J->dev_eleve+=1;
      if (J->n_joueur==1)
      {
          stack new_fisa = creation_stack();
          while (!is_stack_empty(P->fisa1))
            {

              Cartes new_carte = pop_stack(&P->fisa1);
              new_carte.dev+=1;
              push_stack(&new_fisa,new_carte);
            }
          while (!is_stack_empty(new_fisa))
          {
            push_stack(&P->fisa1, pop_stack(&new_fisa));
          }       
        stack new_fise = creation_stack();
        while (!is_stack_empty(P->fise1))
          {

            Cartes new_carte = pop_stack(&P->fise1);
            new_carte.dev+=1;
            push_stack(&new_fise,new_carte);
          }
        while (!is_stack_empty(new_fise))
        {
          push_stack(&P->fise1, pop_stack(&new_fise));
        } 
        }
        else
        {
          stack new_fisa = creation_stack();
          while (!is_stack_empty(P->fisa2))
            {

              Cartes new_carte = pop_stack(&P->fisa2);
              new_carte.dev+=1;
              push_stack(&new_fisa,new_carte);
            }
          while (!is_stack_empty(new_fisa))
          {
            push_stack(&P->fisa2, pop_stack(&new_fisa));
          }       
        stack new_fise = creation_stack();
        while (!is_stack_empty(P->fise2))
          {

            Cartes new_carte = pop_stack(&P->fise2);
            new_carte.dev+=1;
            push_stack(&new_fise,new_carte);
          }
        while (!is_stack_empty(new_fise))
        {
          push_stack(&P->fise2, pop_stack(&new_fise));
        }
        }
        
      break;

      case 30:
      J->dura_eleve+=1;
      if (J->n_joueur==1)
      {
          stack new_fisa = creation_stack();
          while (!is_stack_empty(P->fise1))
            {

              Cartes new_carte = pop_stack(&P->fise1);
              new_carte.dura+=1;
              push_stack(&new_fisa,new_carte);
            }
          while (!is_stack_empty(new_fisa))
          {
            push_stack(&P->fise1, pop_stack(&new_fisa));
          } 
          
          while (!is_stack_empty(P->fisa1))
            {

              Cartes new_carte = pop_stack(&P->fisa1);
              new_carte.dura+=1;
              push_stack(&new_fisa,new_carte);
            }
          while (!is_stack_empty(new_fisa))
          {
            push_stack(&P->fisa1, pop_stack(&new_fisa));
          } 
          
      }
      else
      { 
        stack new_fise = creation_stack();
        while (!is_stack_empty(P->fise2))
          {

            Cartes new_carte = pop_stack(&P->fise2);
            new_carte.dura+=1;
            push_stack(&new_fise,new_carte);
          }
        while (!is_stack_empty(new_fise))
        {
          push_stack(&P->fise2, pop_stack(&new_fise));
        }
        
        while (!is_stack_empty(P->fisa2))
            {

              Cartes new_carte = pop_stack(&P->fisa2);
              new_carte.dura+=1;
              push_stack(&new_fise,new_carte);
            }
          while (!is_stack_empty(new_fise))
          {
            push_stack(&P->fisa2, pop_stack(&new_fise));
          } 
      }


      break;


      case 31:
        P->fise1 = creation_stack();
        P->fise2 = creation_stack();
        P->fisa1 = creation_stack();
        P->fisa2 = creation_stack();
        break;


  default:
    break;
  }


}

  

stack recup_deck(Joueur J, Plateau P) {
  int n_j = J.n_joueur;
  if (n_j == 1) {
    return P.deck1;
  }
  return P.deck2;
  }

stack recup_main(Joueur J, Plateau P) {
  int n_j = J.n_joueur;
  if (n_j == 1) {
    return P.main1;
  }
  return P.main2;
  }

stack recup_defausse(Joueur J, Plateau P) {
  int n_j = J.n_joueur;
  if (n_j == 1) {
    return P.defausse1;
  }
  return P.defausse2;
  }

int nb_carte_eleveFISE(Joueur J, Plateau *P){
  int n_j = J.n_joueur;
  if (n_j == 1) {
    return size_stack(&P->fise1);
  }
  else
  {
    return size_stack(&P->fise2);
  }
  
}

int nb_carte_eleveFISA(Joueur J, Plateau *P){
  int n_j = J.n_joueur;
  if (n_j == 1) {
    return size_stack(&P->fisa1);
  }
  else
  {
    return size_stack(&P->fisa2);
  }
  
}

int parite_tour(Plateau P){ /* renvoie 1 si le numero de tour est pair, 0 sinon */
  return (abs(1-P.n_tour%2));
}

int Calcul_PE(Joueur J,Plateau P){
  int fise,fisa;
  fise=0;
  fisa=0;
  if (parite_tour(P)){
    if(nb_carte_eleveFISE(J,&P)==-1){
      return 0;
    }
    return nb_carte_eleveFISE(J,&P)+1;
    }

  else
    {
      if(nb_carte_eleveFISE(J,&P)!=-1){
        fise=nb_carte_eleveFISE(J,&P)+1;
      }

       if(nb_carte_eleveFISA(J,&P)!=-1){
        fisa=nb_carte_eleveFISA(J,&P)+1;
      }
          
      return (fise+2*fisa);
    }
    
  
}

int fin_de_partie(Plateau P, Joueur joueur1, Joueur joueur2){ /* A utiliser a la fin de chaque TOUR !!! */
  int DD1 = joueur1.dd;
  int DD2 = joueur2.dd;
  if (DD1 >= 20 && DD1 > DD2){
    return 1 ;
  }
  else if (DD2 >= 20 && DD2 > DD1){
    return 2;
  }
   else if (P.n_tour < 30){
     return 0;
   }
   return 3;
  
}

void fin_de_tour(Plateau* P,Joueur * joueur1,Joueur * joueur2){
    int Dev1=0;
    int Dura1=0;
    int Dev2 =0;
    int Dura2 =0;
    int i;
    stack temporaire = creation_stack();


    while (!is_stack_empty(P->fise1))
      {
        
        Cartes new_carte = pop_stack(&P->fise1);
        Dev1 += new_carte.dev;
        Dura1 += new_carte.dura;
        push_stack(&temporaire,new_carte);
      }

    while (!is_stack_empty(temporaire))
    {
      push_stack(&P->fise1, pop_stack(&temporaire));
    }



    while (!is_stack_empty(P->fise2))
      {
        
        Cartes new_carte = pop_stack(&P->fise2);
        Dev2 += new_carte.dev;
        Dura2 += new_carte.dura;
        push_stack(&temporaire,new_carte);
      }

    while (!is_stack_empty(temporaire))
    {
      push_stack(&P->fise2, pop_stack(&temporaire));
    }



    
    if (!parite_tour(*P)) {

          while (!is_stack_empty(P->fisa1))
      {
        
        Cartes new_carte = pop_stack(&P->fisa1);
        Dev1 += new_carte.dev;
        Dura1 += new_carte.dura;
        push_stack(&temporaire,new_carte);
      }

    while (!is_stack_empty(temporaire))
    {
      push_stack(&P->fisa1, pop_stack(&temporaire));
    }



    while (!is_stack_empty(P->fisa2))
      {
        
        Cartes new_carte = pop_stack(&P->fisa2);
        Dev2 += new_carte.dev;
        Dura2 += new_carte.dura;
        push_stack(&temporaire,new_carte);
      }

    while (!is_stack_empty(temporaire))
    {
      push_stack(&P->fisa2, pop_stack(&temporaire));
    }
      }

    int DD1 = Dev1 - Dura2;
    int DD2 = Dev2 - Dura1;

    

    /* Verification si le joueur 1 en question n'a pas de carte perso ajoutant des DD */ 
  
    
    
    int taille_perso = size_queue(P->perso1);
    

    for ( i = 0; i < taille_perso; i+=1) /* boucle de parcours de la pile perso1 (qui contient toutes les cartes perso) */ 
    { 
      Cartes a    = pop_queue(P->perso1) ;
      
       /* a chaque carte perso je recupere le tableau d'effet */
      int j;
      for ( j = 0; j < 12; j+=1){
        switch (a.effet[j])
        {
          case 9:
            DD1+=1;
            break;
        
          case 10:
            DD2--;
          break;

          default:
          break;
        }
      }
      
      push_queue(P->perso1,a);
    }
    
    
    /* Verification si le joueur 2 en question n'a pas de carte perso ajoutant des DD */ 
    taille_perso = size_queue(P->perso2);

    for ( i = 0; i < taille_perso; i+=1) /* boucle de parcours de la pile perso1 (qui contient toutes les cartes perso) */ 
    { 
      
      Cartes a    = pop_queue(P->perso2) ;
       /* a chaque carte perso je recupere le tableau d'effet */
      int j;
      for ( j = 0; j < 12; j+=1){
        switch (a.effet[j])
        {
          case 9:
            DD2+=1;
            break;
        
          case 10:
            DD1--;
          break;

          default:
          break;
        }
      }
      push_queue(P->perso2,a);
    }
    if(DD1>=0) {
      joueur1->dd += DD1;
    }
    if(DD2>=0) {
      joueur2->dd += DD2;
    }
}

void create_deck(Joueur J, Plateau *P){
  int i;
  int a =0;
  stack_int tab = creation_stack_int();
  int cc = souhait_deck();
  for (i = 1 ; i < 21 ; i+=1){
    push_stack_int(&tab,i);
  }

  push_stack_int(&tab,21);
  push_stack_int(&tab,21);
  push_stack_int(&tab,21);
  push_stack_int(&tab,22);
  push_stack_int(&tab,22);
  push_stack_int(&tab,22);
  push_stack_int(&tab,23);
  push_stack_int(&tab,23);
  push_stack_int(&tab,24);
  push_stack_int(&tab,24);
  push_stack_int(&tab,25);
  push_stack_int(&tab,25);
  push_stack_int(&tab,26);
  push_stack_int(&tab,26);
  push_stack_int(&tab,27);
  push_stack_int(&tab,27);
  push_stack_int(&tab,27);
  push_stack_int(&tab,27);
  push_stack_int(&tab,28);
  push_stack_int(&tab,29);
  push_stack_int(&tab,30);
  push_stack_int(&tab,31);

 

  if (J.n_joueur == 1)
  {
    while (tab.top != 0)
  {
    
    if (cc==0){
      a = rand()%(tab.top+1);
    
    }
    else {
      int dd=edit_deck_choix_cartes(tab);
      while(trouver_num_int(&tab, dd)==-1){
        dd=edit_deck_choix_cartes(tab);
      }
      a = trouver_num_int(&tab, dd);
    }
    int b = pop_ieme_carte_int(&tab,a);
    push_stack(&P->deck1,initialisation(b));
  }
  push_stack(&P->deck1,initialisation(pop_stack_int(&tab)));
    
  }
  
  else
  {
    while (tab.top != 0)
  {
    if (cc==0){
      
      a = rand()%(tab.top+1);
      
    }
    else {
      int dd=edit_deck_choix_cartes(tab);
      while(trouver_num_int(&tab, dd)==-1){
        dd=edit_deck_choix_cartes(tab);
      }
      a = trouver_num_int(&tab, dd);
    }
    int b = pop_ieme_carte_int(&tab,a);
    push_stack(&P->deck2,initialisation(b));
  }
  push_stack(&P->deck2,initialisation(pop_stack_int(&tab)));
  }
}

/*Création deck*/
/*  @requires : 
    @assign: aucun
    @ensure : demande à l'utilisateur si il veut creer un deck ou utiliser un deck aleatoirement fait  */ 
int souhait_deck(){
  int b;
  char actuel[256];
  char * endptr;
  printf("Voulez vous créer un deck personnalisé (tapez 1) ou avoir un deck aléatoire (tapez 0) : ");
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
  while (b!=1 && b!=0){
    return souhait_deck();
  }
  //si b=1 alors il creer son deck si c'est 0 on creer un deck aleatoirement
  return b;
}

/*  @requires : 
    @assign: aucun
    @ensure : */ 
int edit_deck_choix_cartes(stack_int tab) {
  char actuel[256];
  char * endptr;
  
  printf("  - Quel carte vous voulez mettre dans votre deck parmis ces cartes la: \n");
  display_stack_int(&tab);
  printf(" (Le nom des cartes seront rajouté ultérieurement!)");
  printf("\nTapez le numéro de la carte que vous souhaitez : ");
  fgets(actuel, 256, stdin);
  strtol(actuel, &endptr, 10);

  /*On sort de la boucle quand l'utilisateur a entre un entier */
  while (actuel == endptr)
            {
                    printf("Erreur cette carte n'existe pas, veuillez entrer un entier ");
                    fgets(actuel, 256, stdin);
                    strtol(actuel, &endptr, 10);
            }

  return strtol(actuel, &endptr, 10);
}
  

Plateau create_plateau(Joueur J1, Joueur J2){
  Plateau new_P;
  new_P.n_tour=0;
  new_P.main1 = creation_stack();
  new_P.main2 = creation_stack();
  new_P.deck1 = creation_stack();
  new_P.deck2 = creation_stack();
  create_deck(J1,&new_P);
  create_deck(J2,&new_P);
  new_P.defausse1 = creation_stack();
  new_P.defausse2 = creation_stack();
  new_P.fise1 = creation_stack();
  new_P.fise2 = creation_stack();
  new_P.fisa1 = creation_stack();
  new_P.fisa2 = creation_stack();
  new_P.perso1 = creation();
  new_P.perso2 = creation();
  
  
  return new_P;
}



void liberation_memoire_plateau(Plateau* P){

  while(!is_queue_empty(*P->perso1)){
    free(pop_queue(P->perso1).effet);
  }

   while(!is_queue_empty(*P->perso2)){
    free(pop_queue(P->perso2).effet);
  }

  free(P->perso1);
  free(P->perso2);

   while(!is_stack_empty(P->main1)){
    free(pop_stack(&P->main1).effet);
  }

   while(!is_stack_empty(P->main2)){
    free(pop_stack(&P->main2).effet);
  }

   while(!is_stack_empty(P->deck1)){
    free(pop_stack(&P->deck1).effet);
  }
   while(!is_stack_empty(P->deck2)){
    free(pop_stack(&P->deck2).effet);
  }

   while(!is_stack_empty(P->fise1)){
    free(pop_stack(&P->fise1).effet);
  }
   while(!is_stack_empty(P->fise2)){
    free(pop_stack(&P->fise2).effet);
  }

   while(!is_stack_empty(P->fisa1)){
    free(pop_stack(&P->fisa1).effet);
  }
   while(!is_stack_empty(P->fisa2)){
    free(pop_stack(&P->fisa2).effet);
  }
   while(!is_stack_empty(P->defausse1)){
    free(pop_stack(&P->defausse1).effet);
  }
   while(!is_stack_empty(P->defausse2)){
    free(pop_stack(&P->defausse2).effet);
  }


}


 



int nombre_cartes_piochees(Plateau* P,Joueur joueur_qui_joue){
  if (P->n_tour == 1)
  {
    return 2 ;
  }
  else
  {

    if (joueur_qui_joue.n_joueur == 1){ /* Cas du joueur 1 */
    
    int count                    =  1;
    int taille_perso             =  size_queue(P->perso1);
    int i;
    for ( i =  0; i < taille_perso; i+=1) /* boucle de parcours de la pile perso1 (qui contient toutes les cartes perso) */ 
    {
      Cartes a= pop_queue(P->perso1);
       /* a chaque carte perso je recupere le tableau d'effet */
      int j;
      for ( j=  0; j < 12; j+=1){
        if (a.effet[j] == 11)
        count            += 1;
      }
      push_queue(P->perso1,a);
    }
     return count;

    }
    else /* Cas du joueur 2 */
    {

    int count                    =  1;
    int taille_perso             =  size_queue(P->perso2);
    int i;
    for ( i =  0; i < taille_perso; i+=1) /* boucle de parcours de la pile perso1 (qui contient toutes les cartes perso) */ 
    {
      Cartes a= pop_queue(P->perso2);
       /* a chaque carte perso je recupere le tableau d'effet */
      int j;
      for ( j=  0; j < 12; j+=1){
        if (a.effet[j] == 11)
        count            += 1;
      }
      push_queue(P->perso2,a);
    }
     return count;
    
    }

    }
   
  }

  void piocher_carte(Plateau *P,Joueur joueur_qui_joue){
    if (joueur_qui_joue.n_joueur == 1){
      Cartes carte_piochee1 = pop_stack(&P->deck1);
      push_stack(&P->main1,carte_piochee1); 
    }
    else if(joueur_qui_joue.n_joueur==2)
    {
      Cartes carte_piochee2 = pop_stack(&P->deck2);
      push_stack(&P->main2,carte_piochee2); 
    }
    
  }

  int nb_eleves_phase(Plateau* P,Joueur J){ /* COPIER COLLER DE LA FONCTION nb_piochees_cartes */
    if (J.n_joueur == 1){ /* Cas du joueur 1 */
    int count = 1;
    int i;
    queue* perso1 = creation();

    
    if(P->perso1->first!=NULL){
    
    int taille_perso = size_queue(P->perso1);

    for ( i = 0; i < taille_perso; i+=1) /* boucle de parcours de la pile perso1 (qui contient toutes les cartes perso) */ 
    { 
      
      Cartes a    = pop_queue(P->perso1) ;
      int j;
      for ( j = 0; j < 12; j+=1){
        switch (a.effet[j])
        {
          case 12:
            count += 1;
            break;
            
        }
      }
      push_queue(perso1,a);
    }
    

    while(!is_queue_empty(*perso1)){
      push_queue(P->perso1,pop_queue(perso1));
    }
    }
      free(perso1);
     return count;
    }

    else /* Cas du joueur 2 */
    {
    int count = 1;
    int i;
    queue* perso2 = creation();

    
    if(P->perso2->first!=NULL){
    
    int taille_perso = size_queue(P->perso2);

    for ( i = 0; i < taille_perso; i+=1) /* boucle de parcours de la pile perso1 (qui contient toutes les cartes perso) */ 
    { 
      
      Cartes a    = pop_queue(P->perso2) ;
       /* a chaque carte perso je recupere le tableau d'effet */
      int j;
      for ( j = 0; j < 12; j+=1){
        switch (a.effet[j])
        {
          case 12:
            count += 1;
            break;
        }
      }
      push_queue(perso2,a);
    }
    

    while(!is_queue_empty(*perso2)){
      push_queue(P->perso2,pop_queue(perso2));
    }
    }
    free(perso2);
     return count;
    
    } }














































/* COMMENCONS LES FONCTIONS DE TEST */ 


Plateau plateau_test(Joueur J1, Joueur J2, int num){ /* Plateau vide avec 5 cartes FISE ET FISA pour chaque eleve */ 
  Plateau new_P;
  new_P.n_tour=num;
  new_P.main1 = creation_stack();
  new_P.main2 = creation_stack();
  new_P.deck1 = creation_stack();
  new_P.deck2 = creation_stack();
  create_deck(J1,&new_P);
  create_deck(J2,&new_P);
  new_P.defausse1 = creation_stack();
  new_P.defausse2 = creation_stack();
  new_P.fise1 = creation_stack();
  new_P.fise2 = creation_stack();
  new_P.fisa1 = creation_stack();
  new_P.fisa2 = creation_stack();
  new_P.perso1 = creation();
  new_P.perso2 = creation();
  int i;
  for (i = 0; i < 5; i+=1) /* Creation de 5 cartes FISE et FISA dans les piles */ 
  {
    Cartes eleve1;
    Cartes eleve2;
      eleve1.dev=J1.dev_eleve;
      eleve2.dev=J2.dev_eleve;
      eleve1.dura=J1.dura_eleve;
      eleve2.dura=J2.dura_eleve;
    push_stack(&new_P.fise1,eleve1);
    push_stack(&new_P.fise2,eleve2);
  }
  for (i = 0; i < 5; i+=1)
  {
    Cartes fisa1;
    Cartes fisa2;
      fisa1.dev=J1.dev_eleve;
      fisa2.dev=J2.dev_eleve;
      fisa1.dura=J1.dura_eleve;
      fisa2.dura=J2.dura_eleve;
    push_stack(&new_P.fisa1,fisa1);
    push_stack(&new_P.fisa2,fisa2);
  }

  while (!is_stack_empty(new_P.deck1))
  {
    push_stack(&new_P.main1,pop_stack(&new_P.deck1));
  }
  while (!is_stack_empty(new_P.deck2))
  {
    push_stack(&new_P.main2,pop_stack(&new_P.deck2));
  }
  return new_P;
}






int compteur_developpement(Plateau *P,Joueur J){
  int Dev = 0;
  if (J.n_joueur==1)
  { 
      stack temporaire = creation_stack();
      while (!is_stack_empty(P->fise1))
      {
          Cartes new_carte = pop_stack(&P->fise1);
          Dev += new_carte.dev;
          push_stack(&temporaire,new_carte);
      }

    while (!is_stack_empty(temporaire))
    {
      push_stack(&P->fise1, pop_stack(&temporaire));
    }

    if (!parite_tour(*P)) {

      while (!is_stack_empty(P->fisa1))
      {
        
        Cartes new_carte = pop_stack(&P->fisa1);
        Dev += new_carte.dev;
        push_stack(&temporaire,new_carte);
      }

    while (!is_stack_empty(temporaire))
    {
      push_stack(&P->fisa1, pop_stack(&temporaire));
    }
}
  }

  else
  {
    
    stack temporaire = creation_stack();
    while (!is_stack_empty(P->fise2))
      {
        Cartes new_carte = pop_stack(&P->fise2);
        Dev += new_carte.dev;
        push_stack(&temporaire,new_carte);
      }

    while (!is_stack_empty(temporaire))
    {
      push_stack(&P->fise2, pop_stack(&temporaire));
    }

    if (!parite_tour(*P)) {

        while (!is_stack_empty(P->fisa2))
      {
        
        Cartes new_carte = pop_stack(&P->fisa2);
        Dev += new_carte.dev;
        push_stack(&temporaire,new_carte);
      }

    while (!is_stack_empty(temporaire))
    {
      push_stack(&P->fisa2, pop_stack(&temporaire));
    }
  }
  
  } 
  return Dev;
  }

  
 int compteur_durab(Plateau *P,Joueur J){
  int Durab = 0;
  if (J.n_joueur==1)
  { 
      stack temporaire = creation_stack();
      while (!is_stack_empty(P->fise1))
      {
          Cartes new_carte = pop_stack(&P->fise1);
          Durab += new_carte.dura;
          push_stack(&temporaire,new_carte);
      }

    while (!is_stack_empty(temporaire))
    {
      push_stack(&P->fise1, pop_stack(&temporaire));
    }

    if (!parite_tour(*P)) {

      while (!is_stack_empty(P->fisa1))
      {
        
        Cartes new_carte = pop_stack(&P->fisa1);
        Durab += new_carte.dura;
        push_stack(&temporaire,new_carte);
      }

    while (!is_stack_empty(temporaire))
    {
      push_stack(&P->fisa1, pop_stack(&temporaire));
    }
}
  }

  else
  {
    
    stack temporaire = creation_stack();
    while (!is_stack_empty(P->fise2))
      {
        Cartes new_carte = pop_stack(&P->fise2);
        Durab += new_carte.dura;
        push_stack(&temporaire,new_carte);
      }

    while (!is_stack_empty(temporaire))
    {
      push_stack(&P->fise2, pop_stack(&temporaire));
    }

    if (!parite_tour(*P)) {

        while (!is_stack_empty(P->fisa2))
      {
        
        Cartes new_carte = pop_stack(&P->fisa2);
        Durab += new_carte.dura;
        push_stack(&temporaire,new_carte);
      }

    while (!is_stack_empty(temporaire))
    {
      push_stack(&P->fisa2, pop_stack(&temporaire));
    }
  }
  
  } 
  return Durab;
  } 




  




  




  
  



