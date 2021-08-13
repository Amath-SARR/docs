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

void ajoutFin(L l, int n)
{
    E a = createElement(n);
    if(l->queue == NULL)
	{
		l->tete = a;
		l->queue = a;
	}
	else
	{

		l->queue->suiv  = a;
        l->queue = a;
	}
	l->taille++;
}


void show(L l)
{
    E p = NULL;
    p = l->tete;
    while(p != NULL)
    {
        printf(" %d ",p->val);
        p = p->suiv;
    }
}

int main()
{
	Liste *l = (L)malloc(sizeof(Liste));
    //createListe(l , 0);

	for(int i = 1; i <= 10; i++)
	{


        ajoutDeb(l , i);
        ajoutFin(l , i);
		//afficheListe(l);
	}
	show(l);

}
