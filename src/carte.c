#include <stdio.h>
#include <stdlib.h>
#include "../headers/carte.h"

int isAction(Cartes c){
return (21 <=c.num && c.num<=31);
}

int isPersonnel(Cartes c){
return (1<=c.num && c.num<=20);
}

int isEleve(Cartes c){
return (32<=c.num && c.num<=33);
}

Cartes initialisation(int n){
  Cartes c;
  c.num = n;

  switch(n){
    case 1:
      c.cout = 3;
      c.effet = (int *) calloc(12,sizeof(int *));
      c.effet[0]=1;
      c.dura = 0;
      c.dev = 0;
      c.nom = "T.Lim";
      break;
    case 2:
      c.cout = 3;
      c.effet = (int *) calloc(12,sizeof(int *));
      c.effet[0]=2;
      c.dura = 0;
      c.dev = 0;
      c.nom = "M.Sza";
      break;
    case 3:
      c.cout = 3;
      c.effet = (int *) calloc(12,sizeof(int *));
      c.effet[0]=3;
      c.dura = 0;
      c.dev = 0;
      c.nom = "A.Fay";
      break;
    case 4:
      c.cout = 3;
      c.effet = (int *) calloc(12,sizeof(int *));
      c.effet[0]=4;
      c.dura = 0;
      c.dev = 0;
      c.nom = "C.Mou";
      break;
    case 5:
      c.cout = 3;
      c.effet = (int *) calloc(12,sizeof(int *));
      c.effet[0]=5;
      c.dura = 0;
      c.dev = 0;
      c.nom = "S.Dum";
      break;
    case 6:
      c.cout = 3;
      c.effet = (int *) calloc(12,sizeof(int *));
      c.effet[0]=6;
      c.dura = 0;
      c.dev = 0;
      c.nom = "J.For";
      break;
    case 7:
      c.cout = 3;
      c.effet = (int *) calloc(12,sizeof(int *));
      c.effet[0]=7;
      c.dura = 0;
      c.dev = 0;
      c.nom = "N.Bru";
      break;
    case 8:
      c.cout = 3;
      c.effet = (int *) calloc(12,sizeof(int *));
      c.effet[0]=8;
      c.dura = 0;
      c.dev = 0;
      c.nom = "L.Bou";
      break;
    case 9:
      c.cout = 5;
      c.effet = (int *) calloc(12,sizeof(int *));
      c.effet[0]=1;
      c.effet[1]=3;
      c.dura = 0;
      c.dev = 0;
      c.nom = "D.Wat";
      break;
    case 10:
      c.cout = 5;
      c.effet = (int *) calloc(12,sizeof(int *));
      c.effet[0]=2;
      c.effet[1]=4;
      c.dura = 0;
      c.dev = 0;
      c.nom = "Vit.Y";
      break;
    case 11:
      c.cout = 5;
      c.effet = (int *) calloc(12,sizeof(int *));
      c.effet[0]=5;
      c.effet[1]=7;
      c.dura = 0;
      c.dev = 0;
      c.nom = "K.Goi";
      break;
    case 12:
      c.cout = 5;
      c.effet = (int *) calloc(12,sizeof(int *));
      c.effet[0]=6;
      c.effet[1]=8;
      c.dura = 0;
      c.dev = 0;
      c.nom = "V.Jea";
      break;
    case 13:
      c.cout = 7;
      c.effet = (int *) calloc(12,sizeof(int *));
      c.effet[0]=11;
      c.effet[1]=11;
      c.dura = 0;
      c.dev = 0;
      c.nom = "M.Mer";
      break;
    case 14:
      c.cout = 8;
      c.effet = (int *) calloc(12,sizeof(int *));
      c.effet[0]=9;
      c.effet[1]=9;
      c.effet[2]=11;
      c.effet[3]=12;
      c.dura = 0;
      c.dev = 0;
      c.nom = "A.Lig";
      break;
    case 15:
      c.cout = 8;
      c.effet = (int *) calloc(12,sizeof(int *));
      c.effet[0]=10;
      c.effet[1]=10;
      c.effet[2]=11;
      c.effet[3]=12;
      c.dura = 0;
      c.dev = 0;
      c.nom = "C.Dub";
      break;
    case 16:
      c.cout = 10;
      c.effet = (int *) calloc(12,sizeof(int *));
      c.effet[0]=1;
      c.effet[1]=2;
      c.effet[2]=6;
      c.effet[3]=10;
      c.dura = 0;
      c.dev = 0;
      c.nom = "E.Lej";
      break;
    case 17:
      c.cout = 10;
      c.effet = (int *) calloc(12,sizeof(int *));
      c.effet[0]=3;
      c.effet[1]=4;
      c.effet[2]=8;
      c.effet[3]=10;
      c.dura = 0;
      c.dev = 0;
      c.nom = "C.Mat";
      break;
    case 18:
      c.cout = 15;
      c.effet = (int *) calloc(12,sizeof(int *));
      c.effet[0]=1;
      c.effet[1]=1;
      c.effet[2]=2;
      c.effet[3]=2;
      c.effet[4]=12;
      c.dura = 0;
      c.dev = 0;
      c.nom = "K.Sal";
      break;
    case 19:
      c.cout = 15;
      c.effet = (int *) calloc(12,sizeof(int *));
      c.effet[0]=3;
      c.effet[1]=3;
      c.effet[2]=4;
      c.effet[3]=4;
      c.effet[4]=10;
      c.dura = 0;
      c.dev = 0;
      c.nom = "A.Sag";
      break;
    case 20:
      c.cout = 20;
      c.effet = (int *) calloc(12,sizeof(int *));
      c.effet[0]=1;
      c.effet[1]=1;
      c.effet[2]=2;
      c.effet[3]=2;
      c.effet[4]=3;
      c.effet[5]=3;
      c.effet[6]=4;
      c.effet[7]=4;
      c.effet[8]=9;
      c.effet[9]=10;
      c.effet[10]=11;
      c.effet[11]=12;
      c.effet[12]=12;
      c.dura = 0;
      c.dev = 0;
      c.nom = "L.Pré";
      break;
    case 21:
      c.cout = 2;
      c.effet = (int *) calloc(12,sizeof(int *));
      c.effet[0]=13;
      c.dura = 0;
      c.dev = 0;
      c.nom = "DevDu";
      break;
    case 22:
      c.cout = 2;
      c.effet = (int *) calloc(12,sizeof(int *));
      c.effet[0]=14;
      c.dura = 0;
      c.dev = 0;
      c.nom = "Rcrtm";
      break;
    case 23:
      c.cout = 3;
      c.effet = (int *) calloc(12,sizeof(int *));
      c.effet[0]=15;
      c.dura = 0;
      c.dev = 0;
      c.nom = "RFise";
      break;
    case 24:
     
      c.cout = 3;
      c.effet = (int *) calloc(12,sizeof(int *));
      c.effet[0]=16;
      c.dura = 0;
      c.dev = 0;
      c.nom = "RFisa";
      break;
    case 25:
      c.cout = 4;
      c.effet = (int *) calloc(12,sizeof(int *));
      c.effet[0]=17;
      c.dura = 0;
      c.dev = 0;
      c.nom = "NRJVr";
      break;
    case 26:
      c.cout = 5;
      c.effet = (int *) calloc(12,sizeof(int *));
      c.effet[0]=18;
      c.dura = 0;
      c.dev = 0;
      c.nom = "Diplo";
      break;
    case 27:
      c.cout = 5;
      c.effet = (int *) calloc(12,sizeof(int *));
      c.effet[0]=19;
      c.dura = 0;
      c.dev = 0;
      c.nom = "Dchrg";
      break;
    case 28:
      c.cout = 10;
      c.effet = (int *) calloc(12,sizeof(int *));
      c.effet[0]=20;
      c.dura = 0;
      c.dev = 0;
      c.nom = "Recyc";
      break;
    case 29:
      c.cout = 10;
      c.effet = (int *) calloc(12,sizeof(int *));
      c.effet[0]=21;
      c.dura = 0;
      c.dev = 0;
      c.nom = "0 Pap";
      break;
    case 30:
      c.cout = 10;
      c.effet = (int *) calloc(12,sizeof(int *));
      c.effet[0]=22;
      c.dura = 0;
      c.dev = 0;
      c.nom = "RVégé";
      break;
    case 31:
      c.cout = 10;
      c.effet = (int *) calloc(12,sizeof(int *));
      c.effet[0]=23;
      c.dura = 0;
      c.dev = 0;
      c.nom = "Ferme";
      break;
  }
return c;
}
