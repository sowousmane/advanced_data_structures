/*
	Ousmane SOW 11608883
	Souad   HADJ-ALI 11708934
*/
Rapport du tp5 sda

/******************************************************/
Nous avions le choix entre créer une structure arbre binomial puis à a partir de ce dernier créer un tas mais notre choix s’est porté sur une structure simple c’est-à-dire une structure avec une racine/nœud(un entier) un parent qui peut être nul si c’est la racine de l’arbre.
Ce nœud peut avoir un fils puis ce fils peut avoir des frères qu’on a appelé subling.
Ainsi nous avons decidé d'utiliser les listes chainées car elles sont très faciles à manupiler avec les opérations de bases.

En outre notre structure nous permet de gagner en espace mémoire.

struct node {
int n;// nombre qui se trouve dans notre noeud c'est-a-dire la racine
int degree; //la taille de l'du tas
struct node* parent;//noeud parent
struct node* child;//noeud fils i
struct node* sibling;//noeud freres de i

};



/******************************************************/

Nous avons une fonction MAKE_bin_HEAP() qui crée  une structure tas qui ne prend rien et renvoie un tas binomial initialisé à nul sa complexité est de O(1).

struct node* MAKE_bin_HEAP();



/******************************************************/
La fonction bin_LINK(struct node*, struct node*)  ne renvoie rien elle se charge de lier deux tas  qu’elle prend en argument mais ces arbres doivent avoir le même degré pour pouvoir appliquer le liens binomiale  et donc cela augmente le degré du tas resultant du lien.

void bin_LINK(struct node*, struct node*);



/******************************************************/
La fonction  create node prend en argument un entier et en crée un tas mais avec un seul élément elle renvoie donc un tas avec un éliment à l’intérieur.

struct node* CREATE_NODE(int);



/******************************************************/
La fonction UNION renvoie une structure d'un tas, cette fonction prend en argument 2 tas les unis et en renvoie un.
Au debut on cree un tas vide puis on fusionne dans ce tas les deux tas pris en argument et tout en le triant par degré de la racine des deux tas.

Ensuite on teste si le tas resultant de l'union au tout debut est vide si oui on renvoie le tas vide sinon on initialise le fils gauche de la racine à null puis la racine devient le tas et le droit prend les frères de la racine du tas resultant de la fusion au debut.
On boucle tant que le nouveau tas n'est pas vide pour faire le traitement de fusion ainsi que les liens et comparaisons.

Enfin on renvoie le tas resultant de l'union des deux tas pris en argument après traitement.

ON REMARQUE QUE: le temps d'execution de la fusion de 2 tas est en O(log(n)).

struct node* bin_HEAP_UNION(struct node*, struct node*);



/******************************************************/
Notre fonction insert tas binomial renvoie un tas, cette fonction prend en argument 2 tas insert le second dans le premier c'est-a-dire fait une union des deux tas
Ce que fait la fonction c'est de mettre les champs (  degree, parent, child, sibling) à null et mettre la valeur n du deuxieme argument dans le champs n

Sa complexité est en O(log(n))

exemple:  bin_HEAP_INSERT(tas, CREATE_NODE(1));

struct node* bin_HEAP_INSERT(struct node*, struct node*);



/******************************************************/
cette fonction permet de fusionner deux tas binomiaux en un seul tas trié par degré de la racine des deux tas pris en argument.

struct node* bin_HEAP_MERGE(struct node*, struct node*);



/******************************************************/
supprime la racine d'un tas  et renvoie l’élément extrait 
il repère le min du tas parmis les racines puis coup le tas en deux puis supprime la racine du tas reordonne le tas en creant un tas de deux arbres ou un seul s'ils ont le même degré en appellant la fonction union. 
Elle comme complexité O(log(n)) 

struct node* bin_HEAP_EXTRACT_MIN(struct node*);



/******************************************************/
Notre fonction rever_list prend en argument un tas la renverse on l’a crée pour pouvoir l’utiliser dans notre fonction extraction du minimum.
Sa complexité est de O(log(n))

int REVERT_LIST(struct node*);



/******************************************************/
Display nous permet l’affichage de notre tas  
Sa complexité est en O(log(n))

int DISPLAY(struct node*);



/******************************************************/
Comme son nom l’indique elle cherche un entier(une clé) dans un tas 
Sa complexité peut être très grande si l'element à chercher est une clé dans un tas très grand mais elle ne depasse pas O(log(n))
struct node* FIND_NODE(struct node*, int);



/******************************************************/
cette fonction nous permet d'effectuer une suppression dans notre fonction bin_HEAP_DELETE elle prend en argument un tas, l'element à diminuer et lde combien on veut le diminuer.
Une fois la valeur diminuer on trie de nouveau le tas.
sa complexité est du rang de O(log(n))

int bin_HEAP_DECREASE_KEY(struct node*, int, int);



/******************************************************/

//suppression d'un tas à la fin du programme
sa complexité est de O(log(n)) aussi car elle fait appelle à deux fonctions qui ont une complexité en log(n) mais comme ces deux fontions ne sont pas imbriquées donc la complixité est celle de la fonction qui la plus grande complexité donc log(n) 

int bin_HEAP_DELETE(struct node*, int);



/******************************************************/
		Conclusion: 
Ce TP nous a fait découvrir les tas et les arbres binomiaux avec toutes les oppérations possibles qu'on peut effectuer sur ces derniers tel que la création, insertion, extraction du plus petit élément et enfin la suppression d'un tas.
En outre, ce TP nous a permis de mettre en évidence notre capacité de recherche et d'analyse pour pouvoir retransmettre une information, ainsi la capacité de retranscrire les notions acquises en cours.
En revanche, les principaux problèmes que nous avons rencontrés étaient sur la structuration de notre tas. Ainsi, nous avons touché du doigt la difficulté d'extraction d'informations disponibles pour obtenir des notions cohèrentes pour la réalisation de l'ensemble du TP.
A partir de cette étude, nous avons constaté que les tas sont moins couteux en espace qu'en temps.Ceci car leurs implémentations permettent d'utiliser l'espace nécessaire par rapport aux données, en fonctions de l'opération effectuée.

