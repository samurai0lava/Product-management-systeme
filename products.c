#include <stdio.h>
#include <stdlib.h>
//structure de base de donner de base du produit 
typedef struct produit{
	int c; //code de produit 
	char n[64]; //nom du produit
	float s; //stock
	
}produit;
typedef struct produits {// structure de produits
	produit* produits;
	int nb_produit;
}produits;
void ajout (produits* t){ //fonction d'ajoouter les donner de produit
    produit p;
	printf ("donner le code de produit : \n");
	scanf("%d",&p.c);
    printf ("donner le nom de produit : \n");
	scanf("%s",p.n);
	printf ("donner le stock de produit : \n");
	scanf("%f",&p.s);
if (t->nb_produit==0){
	t->produits=(produit*)malloc(sizeof(produit)); //allocation dynamique de memoire
	t->produits[t->nb_produit]=p;
	t->nb_produit++;
}
else {
	t->produits=(produit*)realloc(t->produits,(t->nb_produit+1*sizeof(produit)));//reallouer la memoire selon la vaeur de t 
	t->produits[t->nb_produit]=p;
	t->nb_produit++;	
}
}	
	void afficher(produits* t){
	int i;	
		for (i=0;i<t->nb_produit;i++){
			printf("Code %d",t->produits[i].c);
			printf("nom %s",t->produits[i].n);
			printf("stock %f",t->produits[i].s);
			printf("\n");
		}		
	}
int main() {
produits t;
t.nb_produit=0; //initialisation
int ch;
do {
printf("***********************************************************************************\n");
printf("****************************SYSTEME D'AJOUT DES PRODUITS********************************\n");
printf("***********************************************************************************\n");
printf("0.ajouter un produit.\n");
printf("1.afficher un produit.\n");
printf("2.exit.\n");

	scanf("%d",&ch);
	switch (ch){
			case 0: ajout(&t); break;
			case 1: afficher(&t); break;
	}
		} while(ch!=2);	
}
