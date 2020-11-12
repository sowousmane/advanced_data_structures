#ifndef BINOMIALE_H
#define BINOMIALE_H

#define FALSE 0
#define TRUE 1
/*creaton de notre tas*/
typedef struct node {
    int n;// nombre qui se trouve dans notre noeud c'est-a-dire la racine
    int degree; //la taille de du tas
    struct node* parent;//noeud parent
    struct node* child;//noeud fils i
    struct node* sibling;//noeud freres de i

}node ;
typedef struct  tas_bino {
    node **tas;
} tas_bino;
tas_bino * init_tas();
// creation d'une structure tas cette fonction ne prend rien et renvoie un tas binomial initialisé à null
struct node* MAKE_bin_HEAP();

// cette fonction ne renvoie rien elle se charge de lier deux tas et donc cela augmente le degre du tas
void bin_LINK(struct node*, struct node*);

// elle prend en argument un entier et en cree un tas mais avec un seul element
struct node* CREATE_NODE(int);

//elle renvoie une structure d'un tas, cette fonction prend en argument 2 tas  les unis et en renvoie un.
//struct node* bin_HEAP_UNION(struct node*, struct node*);
struct node* bin_HEAP_UNION(struct node* , struct node* );
//elle renvoie une structure d'un tas, cette fonction prend en argument 2 tas  insert le premier dans le second c'est-a-dire
// fait une union des deux tas
struct node* bin_HEAP_INSERT(struct node*, struct node*);
//
struct node* bin_HEAP_MERGE(struct node* , struct node* );
//supprime la racine d'un tas
struct node* bin_HEAP_EXTRACT_MIN(struct node*);
//
int REVERT_LIST(struct node*);
// afficher notre tas
int DISPLAY(struct node*);
// pour rechercher une clé
struct node* FIND_NODE(struct node*, int);
// pour faire le swap des une clé d'une autre
int bin_HEAP_DECREASE_KEY(struct node*, int, int);
//suppression d'un tas à la fin du programme
int bin_HEAP_DELETE(struct node*, int);

#endif
