#include<stdio.h>
#include <time.h>
#include<stdlib.h>
#include "arraylist.h"
#include "analyzer.h"
#include "tas_bino.h"


int main(int argc, char ** argv){
  int i,j;
  struct tas_bino* tas_binomial = init_tas();
  //allocation du noeud
  struct tas_bino *tass=init_tas();
  //struct node* tas2[10];
//creation du premier tas
for(i = 0; i < 10 ; i++)
    // Ajout d'un élément et mesure du temps pris par l'opération.
    tass= bin_HEAP_INSERT(tas_binomial, CREATE_NODE(i));
   
  
  //creation du deuxieme tas
   /*//tass->tas[0]= bin_HEAP_INSERT(tas_binomial, CREATE_NODE(7));
    tass->tas[1]= bin_HEAP_INSERT(tas_binomial, CREATE_NODE(1));
    tass->tas[2]= bin_HEAP_INSERT(tas_binomial, CREATE_NODE(3));
    tass->tas[3]= bin_HEAP_INSERT(tas_binomial, CREATE_NODE(2));
    tass->tas[4]= bin_HEAP_INSERT(tas_binomial, CREATE_NODE(15));
   
  
 //=======================================
  */ // Affichage du tas
    for(int i=0; i < 10 ; i++)
      DISPLAY(tass->tas[i]);
//=======================================

  //=======================================================
  //                 Union de deux tas
  

//==========================================================
  //  Extract the min of the heap
//===========================================================

  return EXIT_SUCCESS;
}
