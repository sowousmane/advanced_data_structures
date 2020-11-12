#include <stdlib.h>
#include <stdio.h>
#include <math.h> 
#include "tas_bino.h"
// creation de deux structures globales pour nos manipulations
struct node * H = NULL;
struct node *Hr = NULL;

// initializtion of the heap
tas_bino * init_tas()
{
    tas_bino * h=malloc(sizeof(tas_bino));
	h->tas=malloc(sizeof(node*));
	
	return h;
}
// creation d'une structure tas cette ne prend rien et renvoie un tas binomial initialisé à null
struct node* MAKE_bin_HEAP() {
    struct node* np;
    np = NULL;
    return np;
}


// cette fonction ne renvoie rien elle se charge de lier deux tas et donc cela augmente le degre du tas
void bin_LINK(struct node* y, struct node* z) {
    y->parent = z;
    y->sibling = z->child;
    z->child = y;
    z->degree = z->degree + 1;
}

// elle prend en argument un entier et en cree un tas mais avec un seul element
struct node* CREATE_NODE(int k) {

    struct node* p;//nouveau noeud que nous retournons;
    p = (struct node*) malloc(sizeof(struct node));//allocation du noeud
    p->n = k;
    return p;
}

 
//elle renvoie une structure d'un tas, cette fonction prend en argument 2 tas  les unis et en renvoie un.
struct node* bin_HEAP_UNION(struct node* H1, struct node* H2) {
    struct node* x;
    struct node* prev_x;//pour le frère gauche de x
    struct node* next_x;//pour le frère droit de x
    struct node* H = MAKE_bin_HEAP(); // un tas pour nos manipulations
    H = bin_HEAP_MERGE(H1, H2);
    if (H == NULL)
        return H;
    prev_x = NULL;
    x = H;
    next_x = x->sibling;
    while (next_x != NULL) {

        if ((x->degree != next_x->degree) || ((next_x->sibling != NULL)

                && (next_x->sibling)->degree == x->degree)) {

            prev_x = x;

            x = next_x;

        } else {

            if (x->n <= next_x->n) {

                x->sibling = next_x->sibling;

                bin_LINK(next_x, x);

            } else {

                if (prev_x == NULL)

                    H = next_x;

                else

                    prev_x->sibling = next_x;

                bin_LINK(x, next_x);

                x = next_x;

            }

        }

        next_x = x->sibling;

    }

    return H;

}

 // on cree un nouveau tas contenant un seul element et qui fait l'union des deux tas reçu en argument 

struct node* bin_HEAP_INSERT(struct node* H, struct node* x) {

    struct node* H1 = MAKE_bin_HEAP();

    x->parent = NULL;

    x->child = NULL;

    x->sibling = NULL;

    x->degree = 0;

    H1 = x;

    H = bin_HEAP_UNION(H, H1);

    return H;

}

 // cette fonction permet de fusionner deux tas binomiaux en un seul tas trié par degré de la racine des deux tas pris en argument.

struct node* bin_HEAP_MERGE(struct node* H1, struct node* H2) {

    struct node* H = MAKE_bin_HEAP();

    struct node* y;

    struct node* z;

    struct node* a;

    struct node* b;

    y = H1;

    z = H2;

    if (y != NULL) {

        if (z != NULL && y->degree <= z->degree){
            H = y;
	}
        else if (z != NULL && y->degree > z->degree){
            H = z;
	}
        else{
            H = y;
	}
    } 
    else{
        H = z;
    }
    while (y != NULL && z != NULL) {

        if (y->degree < z->degree) {

            y = y->sibling;

        } else if (y->degree == z->degree) {

            a = y->sibling;

            y->sibling = z;

            y = a;

        } else {

            b = z->sibling;

            z->sibling = y;

            z = b;

        }

    }

    return H;

}

 

int DISPLAY(struct node* H) {




    if (H == NULL) {

        printf("\nHEAP EMPTY");

        return 0;

    }

    printf("\nTHE ROOT NODES ARE:-\n");
    while (H != NULL) {

        printf("%d", H->n);

        if (H->sibling != NULL)

            printf("-->");

        H = H->sibling;

    }

    printf("\n");
    return 1;
}

 

struct node* bin_HEAP_EXTRACT_MIN(struct node* H1) {
    int min=0;
    struct node* t = NULL;
    struct node* x = H1;
    struct node* p;
    if (x == NULL) {
        printf("\nNOTHING TO EXTRACT");
        return x;
    }
    p = x;
    min=x->n;
    while (p->sibling != NULL) {
        if ((p->sibling)->n < min) {
            min = (p->sibling)->n;
            t = p;
            x = p->sibling;
        }
        p = p->sibling;
    }
    if (t == NULL && x->sibling == NULL)
        H1 = NULL;
    else if (t == NULL)
        H1 = x->sibling;
    else if (t->sibling == NULL)
        t = NULL;
    else
        t->sibling = x->sibling;
    if (x->child != NULL) {
        REVERT_LIST(x->child);
        (x->child)->sibling = NULL;
    }
    H = bin_HEAP_UNION(H1, Hr);
    return x;
}

 

int REVERT_LIST(struct node* y) {

    if (y->sibling != NULL) {

        REVERT_LIST(y->sibling);

        (y->sibling)->sibling = y;

    } else {

        Hr = y;

    }
    return 1;
}

 

struct node* FIND_NODE(struct node* H, int k) {

    struct node* x = H;

    struct node* p = NULL;

    if (x->n == k) {

        p = x;

        return p;

    }

    if (x->child != NULL && p == NULL) {

        p = FIND_NODE(x->child, k);

    }

 

    if (x->sibling != NULL && p == NULL) {

        p = FIND_NODE(x->sibling, k);

    }

    return p;

}

 
// cette fonction nous permet d'effectuer une suppression dans notre fonction bin_HEAP_DELETE elle prend en argument 
//un tas, l'element à diminuer et lde combien on veut le diminuer
int bin_HEAP_DECREASE_KEY(struct node* H, int i, int k) {

    int temp;

    struct node* p;

    struct node* y;

    struct node* z;

    p = FIND_NODE(H, i);

    if (p == NULL) {

        printf("\nINVALID CHOICE OF KEY TO BE REDUCED");

        return 0;

    }

    if (k > p->n) {

        printf("\nSORY!THE NEW KEY IS GREATER THAN CURRENT ONE");

        return 0;

    }

    p->n = k;

    y = p;

    z = p->parent;

    while (z != NULL && y->n < z->n) {

        temp = y->n;

        y->n = z->n;

        z->n = temp;

        y = z;

        z = z->parent;

    }

    printf("\nKEY REDUCED SUCCESSFULLY!");
    return 1;
}

 

int bin_HEAP_DELETE(struct node* H, int k) {

    struct node* np;

    if (H == NULL) {

        printf("\nHEAP EMPTY");

        return 0;

    }

 

    bin_HEAP_DECREASE_KEY(H, k, -1000001);

    np = bin_HEAP_EXTRACT_MIN(H);

    if (np != NULL)

        printf("\nNODE DELETED SUCCESSFULLY");

    return 1;
	
}







