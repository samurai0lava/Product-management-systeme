#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
   void recherche_code(produits* t, int code_saisie){
	    int i,j;
	    j=0;
	    printf("donner le code:\n");
	    scanf ("%d",&code_saisie);
	    for (i=0;i<t->nb_produit;i++){
            if (t->produits[i].c == code_saisie){
            printf("Code %d\n",t->produits[i].c);
			printf("nom %s\n",t->produits[i].n);
			printf("stock %f",t->produits[i].s);
			printf("\n");
			j++;
            }
            if (j == 0)
                printf("le code n'existe pas");
	    }
   }
	    void recherche_stock(produits* t, int stock_saisie){
	    int i,j;
	    j=0;
	    printf("donner le stock:\n");
	    scanf ("%d",&stock_saisie);
	    for (i=0;i<t->nb_produit;i++){
            if (t->produits[i].s == stock_saisie){
                printf("nom %s",t->produits[i].n);
                j++;
            }
            if (j == 0)
                printf("le code n'existe pas");
	    }
	    }
        void recherche_nom(produits* t,char nom_saisie[64]  ){
	    int i,j;
          j=0;
          for (i=0;i<t->nb_produit;i++){
            if (strcmp(t->produits[i].n,nom_saisie) == 0){
            printf("Code %d\n",t->produits[i].c);
			printf("stock %f",t->produits[i].s);
			printf("\n");
			j++;
            }
            if (j == 0)
            printf("le nom n'existe pas");
          }
	    }
int main() {
produits t;
t.nb_produit=0; //initialisation
int ch;
int code_saisie;
char nom_saisie[64];
int stock_saisie;
do {
printf("***********************************************************************************\n");
printf("****************************SYSTEME D'AJOUT DES PRODUITS********************************\n");
printf("***********************************************************************************\n");
printf("0.ajouter un produit.\n");
printf("1.afficher un produit.\n");
printf("3.rechercher un produit par code.\n");
printf("4.rechercher un produit par stock.\n");
printf("5.rechercher un produit par nom.\n");
printf("2.exit.\n");


	scanf("%d",&ch);
	switch (ch){
			case 0: ajout(&t); break;
			case 1: afficher(&t); break;
			case 3: printf("donner le code:\n"); scanf ("%d",&code_saisie);recherche_code(&t,&code_saisie ); break;
			case 4: printf("donner le stock:\n"); scanf ("%d",&stock_saisie); recherche_stock(&t,&stock_saisie ); break;
            case 5: printf("donner le nom:");gets(nom_saisie); recherche_nom(&t, &nom_saisie ); break;

}
		} while(ch!=2);
}

