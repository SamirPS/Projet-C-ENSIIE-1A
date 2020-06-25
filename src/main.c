#include "../headers/interface.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <curses.h>


void jouer(Joueur* A,Plateau *plateau){
        
        /*Fonction permettant de jouer au jeu  */

        newphase(*A); //Affiche nouvelle phase du Joueur A 

        /*Permet de savoir le nombre de cartes 
          Eleves et autres piochees par A */

        int nbeleve=nb_eleves_phase(plateau,*A);     
        int nbdecartepioche=nombre_cartes_piochees(plateau,*A);

        int i;

        
        /*Boucle permettant de piocher les cartes dans la main 
        de A */

        for(i=0;i<nbdecartepioche;i++){

            piocher_carte(plateau,*A);
           

        }

        Cartes carteajouer;

         /*Boucle permettant de choisir si la carte eleve
           pioche est une FISE ou FISA */

        for (i=0;i<nbeleve;i++) {
            carteajouer=choix_carte_Eleve(*A,*plateau);
            jouerEleve(*A,plateau,carteajouer); /* A déterminer plus tard (rajoutée lors du lot B) */
           
        }

        int finphase=-1;    

        /*On affiche les cartes que A peut jouer en fct
          des PE or jouer une carte diminue les PE et donc
          le joueur n'aura plus de PE et donc il va choisir 
          la carte fin de phase  */
        afficher_plateau(*A,plateau);
        A->PE=Calcul_PE(*A,*plateau);
        while(finphase!=0){    //num carte =0 signifie carte fin_phase
            carteajouer=choix_carte(A,plateau);
            JouerCarteMain(A,plateau,&carteajouer);
            finphase=carteajouer.num;
            if(finphase==0){
                break;
            }
            afficher_plateau(*A,plateau);
        }


}



int main(){
    
    // Creation des joueurs 

    Joueur joueur1;
    Joueur joueur2;
    joueur1.n_joueur=1;
    joueur2.n_joueur=2;
    joueur1.dd=0;
    joueur2.dd=0;
    joueur1.dev_eleve=1; /* ajouté au lot B */
    joueur1.dura_eleve=1; /* ajouté au lot B */
    joueur2.dev_eleve=1; /* ajouté au lot B */
    joueur2.dura_eleve=1; /* ajouté au lot B */


    int debut=debutval(); // On choisit qui commence si 0 alors joueur1 sinon joueur2 

    Plateau plateau = create_plateau(joueur1,joueur2); // Creation du plateau

    int resultat = fin_de_partie(plateau, joueur1, joueur2);
    /*  
        0 signifie que la partie n'est pas terminée
        1 signifie que le joueur 1 a gagné
        2 signifie que le joueur 2 a gagné
        3 signifie que la partie est nulle
    */

  

    /*A chaque tour de la boucle nbdetour augmentent de 1 et 
      si une personne gagne ou egalite (au bout de 30 tours) alors 
      resultat ne vaut plus 0 et donc on sort de la boucle  */


    while (resultat == 0) {   

        new_tour(&plateau);         //affiche le message "un nouveau tour commence"
        

        
        if (debut){

            jouer(&joueur2,&plateau);
            system("clear");
            printtour(plateau);
            jouer(&joueur1,&plateau);

            
        }

        else {

            jouer(&joueur1,&plateau);
            system("clear");
            printtour(plateau);
            jouer(&joueur2,&plateau);
            
            
           
        }


        system("clear");
        debut=changedebut(debut); // pour l'alternance des phases 

        //fin tour
        fin_de_tour(&plateau,&joueur1,&joueur2);
        
        //verifie si le match n'est pas terminé
        resultat=fin_de_partie(plateau, joueur1, joueur2);

        
    }
    
    resultatpartie(resultat);
    liberation_memoire_plateau(&plateau);
    
    return 0;
}