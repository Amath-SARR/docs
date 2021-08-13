 #include<stdio.h>
#include<stdlib.h>
typedef struct Element
{
	int val;
	struct Element *suiv;
}Element, *E;

typedef struct Liste
{
	Element *tete;
	Element *queue;
	int taille;
}Liste, *L;

E createElement(int n)
{
	E e = (E)malloc(sizeof(Element));
	e->val = n;
	e->suiv = NULL;
	return e;
}

L listevide()
{
	L l = (L)malloc(sizeof(Liste));
	l->queue = NULL;
	l->tete = NULL;
	l->taille = 0;
	return l;
}

L listvide(L l)
{
	//L l = (L)malloc(sizeof(Liste));
	l->queue = NULL;
	l->tete = NULL;
	l->taille = 0;
	return l;
}
L createListe(L l, int n)
{
    E a = createElement(n);
    l->queue = l->tete = a;
    a->suiv = NULL;
    l->taille++;
}

void ajoutDeb(L l, int n)
{
    E a = createElement(n);
    if(l->tete == NULL)
	{
		l->queue = a;
		l->tete = a;
	}
	else
	{
		a->suiv = l->tete;
		l->tete = a;
	}
	l->taille++;
}

void ajoutfin(L l , int n )
{
	E a = createElement(n);
    if(l->queue == NULL)
	{
		l->queue->suiv = a;
		l->queue = a;		
	}
	else
	{
		a->suiv = l->tete;
		l->queue->suiv = a;
	}
	l->taille++;
}

void ajoufin(L l ,int n)
{
  E m=createElement(n);
  l->queue->suiv=m;
  l->queue=m;
  l->taille++;
}

L ajoutDans(L l, int n)
{
	E a = createElement(n);
    if(l->tete == NULL)
	{
		l->queue = a; l->tete = a;
	}
	else
	{
		a->suiv = l->tete;
		l->tete = a;
	}
	l->taille++;

	E i = l->tete, j;
	for(; i->suiv != NULL; i=i->suiv)
	{
		for(j=i->suiv; j != NULL; j=j->suiv)
		{
			if(i->val > j->val)
			{
				int tmp = i->val;
				i->val = j->val;
				j->val = tmp;
			}
		}
	}
	return l;
}

void afficheListe(L l)
{
    if(l->tete == NULL)
        printf("La liste est vide ");
    else
    {
        E tmp = l->tete;
        while(tmp!=NULL)
        {
            printf(" %d-> ",tmp->val);
            tmp = tmp->suiv;
        }
    }

}
void show(L suite)
{
    E p;
    p=suite->tete;
    while(p!=NULL)
    {
        printf(" %d ",p->val);
        p=p->suiv;
    }
}

void nbElement(L l)
{
	E e = l->tete;	int cpt = 0;
	while(e != NULL)
	{
		cpt++;
		e = e->suiv;
	}
    printf("\nLe nombre d'element de la liste est %d\n",cpt);
}

//Calcul du nnombre d'occurence
void occurence(L l , int n)
{
	E a = l->tete;	int cpt = 0;
	while(a!=NULL)
	{
		if(n == a->val)
			cpt++;
		a = a->suiv;
	}
	printf("\nLe nombre d'occurence de %d est %d \n",n,cpt);
}

//supprimer debut
void supDeb(L l)
{
	E a = l->tete;
	if(a)
	{
		l->tete = l->tete->suiv;
		a->suiv = NULL;
		free(a);
		l->taille--;
	}
	else
		printf("\nLa liste est vide");
}

//supprimer fin
void supFin(L l)
{
	E asup = l->queue;
	E tmp = l->tete;
	if(tmp)
	{
		while(tmp->suiv != l->queue)
			tmp = tmp->suiv;
		l->queue = tmp;
		tmp->suiv = NULL;
		free(asup);
		l->taille--;
	}
	else
		printf("\nLa liste est vide \n");
	
}

void listeOrder(L l)
{
	int tmp = l->tete->val;
	while(tmp != NULL)
	{
		if(tmp < tmp)
	}
}
int main()
{
	Liste *l = (L)malloc(sizeof(Liste));
	
//	ajoutDeb(l, 7);		
		
    printf("La liste est \n");
    createListe(l, 29);
    ajoutDeb(l, 5);
    ajoutDeb(l, 5);
	ajoufin(l,4);
	ajoutDans(l, -1);
	ajoutDans(l, 0);
	
	afficheListe(l);
	nbElement(l);
	occurence(l , 5);
	printf("\n Apres suppresion l'element de debut et de fin de la liste \n");
	supDeb(l);
	supFin(l);
	afficheListe(l);
	l = listevide();
	if(l == NULL)
		printf("La liste est vide\n");
		
	else
		printf("La liste est pleine\n");
	//show(l);
   	return 0;
}
