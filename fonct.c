E createElement(int n)
{
	E e = (E)malloc(sizeof(Element));
	e->val = n;
	e->suiv = NULL;
	return e;
}

L listevide()
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
