#include<stdio.h>
#include <time.h>
#include<stdlib.h>
#include "tas_bino.h"
#include"analyzer.h"
#include<math.h>

/*11608883
  11708934*/
  
int main(int argc, char ** argv){
  int i;

  struct node* tas_binomial = MAKE_bin_HEAP();
  // Analyse du temps pris par les opérations.
  analyzer_t * time_analysis = analyzer_create();
  // Analyse du nombre de copies faites par les opérations.
  analyzer_t * copy_analysis = analyzer_create();
  // Analyse de l'espace mémoire inutilisé.
  analyzer_t * memory_analysis = analyzer_create(); 
  // Mesure de la durée d'une opération.
  struct timespec before, after;
  clockid_t clk_id = CLOCK_REALTIME;
  // utilisé comme booléen pour savoir si une allocation a été effectuée.
  //char memory_allocation; 
	
  //INSERTION CROISSANTE (Decommenter pour utiliser)
	/*
  for(i = 0; i <  1000 ; i++){
    // Ajout d'un élément et mesure du temps pris par l'opération.
    //clock_gettime(clk_id, &before);
    bin_HEAP_INSERT(tas_binomial, CREATE_NODE(i));
    //bin_HEAP_EXTRACT_MIN(tas_binomial);
    //clock_gettime(clk_id, &after);

    // Enregistrement du temps pris par l'opération
   // analyzer_append(time_analysis, after.tv_nsec - before.tv_nsec);
    // Enregistrement du nombre de copies efféctuées par l'opération.
    // S'il y a eu réallocation de mémoire, il a fallu recopier tout le tableau.
    //analyzer_append(copy_analysis, (memory_allocation)? i:1 );
    // Enregistrement de l'espace mémoire non-utilisé.
   // analyzer_append(memory_analysis,arraylist_capacity(a)-arraylist_size(a));
  }*/

  //INSERTION Aleatoire(Decommenter pour utiliser)
	
    srand(time(NULL)); 
    int nombre;
    for(i = 0; i <  1000000 ; i++){
      // Ajout d'un élément et mesure du temps pris par l'opération.
      nombre = rand()%(1000000-0+1) + 0 ;
      clock_gettime(clk_id, &before);
      bin_HEAP_INSERT(tas_binomial, CREATE_NODE(nombre));
      //memory_allocation = arraylist_pop_back(a);
      clock_gettime(clk_id, &after);
      // Enregistrement du temps pris par l'opération
      analyzer_append(time_analysis, after.tv_nsec - before.tv_nsec);
      // Enregistrement du nombre de copies efféctuées par l'opération.
      // S'il y a eu réallocation de mémoire, il a fallu recopier tout le tableau.
      //analyzer_append(copy_analysis, (memory_allocation)? i:1 );
      // Enregistrement de l'espace mémoire non-utilisé.
      // analyzer_append(memory_analysis,arraylist_capacity(a)-arraylist_size(a));
  }

  /*// Affichage de quelques statistiques sur l'expérience.
  fprintf(stderr, "Total cost: %Lf\n", get_total_cost(time_analysis));
  fprintf(stderr, "Average cost: %Lf\n", get_average_cost(time_analysis));
  fprintf(stderr, "Variance: %Lf\n", get_variance(time_analysis));
  fprintf(stderr, "Standard deviation: %Lf\n", get_standard_deviation(time_analysis));

  // Sauvegarde les données de l'expérience.
  save_values(time_analysis, "./plots/dynamic_array_time_c.plot");
  //save_values(copy_analysis, "../plots/dynamic_array_copy_c.plot");
  //save_values(memory_analysis, "../plots/dynamic_array_memory_c.plot");

  // Nettoyage de la mémoire avant la sortie du programme
 // heap_free(tas_binomial);
  analyzer_destroy(time_analysis);
  analyzer_destroy(copy_analysis);
  analyzer_destroy(memory_analysis);*/
  return EXIT_SUCCESS;
}