#include <stdio.h>
#include <stdlib.h>
typedef struct sargal
{
    int tel,point,nombre,reste;

}sargal;
sargal *creation(int tel)
{
    sargal*C=(sargal*)malloc(sizeof(sargal));
    C->tel=tel;
    C->point=0;
    C->nombre=0;
    C->reste=0;
    return C;
}
void mettreAjour(sargal*C,int solde)
{
    C->point += (int)solde/100;
    C->nombre++;
    C->reste += solde%100;
}
int nombreDErecharge(sargal*C)
{
    return C->nombre;
}
int nombreDEpoint(sargal*C)
{
    return C->point;
}
void consulterCompte(sargal*C)
{
    printf("votre compte est de %d\n",nombreDEpoint(C));
}
void cadeaux(sargal *C,int choix)
{
    switch(choix)
    {
        case 1:
            if (nombreDEpoint(C)<100)
            {
                printf("point insuffisant\n");
                break;
            }
            C->point-=100;
            printf("vous avez une passe internet\n");
        break;
        case 2:
            if (nombreDEpoint(C)<50)
            {
                printf("point insuffisant\n");
                break;
            }
            C->point-=50;
            printf("Illimité 50 points et reste %d\n",nombreDEpoint(C));
        break;
        case 3:
            if (nombreDEpoint(C)<25)
            {
                printf("point insuffisant\n");
                break;
            }
            C->point-=25;
            printf("valider et vous reste %d points\n",nombreDEpoint(C));
        break;
        default:
            printf("non pris en charge\n");
    }
}
    void choice(sargal *C,int n)
    {
        if(n=1)
            consulterCompte(C);
        else
        {
            if(n=2)
            {
                printf("1: passe internet\n");
                printf("2:minutes d'appel\n");
                printf("3:SMS gratuits\n");
                int a;
                scanf("%d",&a);
                cadeaux(C,a);
            }
            else
            printf("non pris en charge\n");
        }
    }
int main()
{
    sargal*S=creation(771234567);
    printf("1:consulter le nombre de points\n");
    printf("2:choisir des cadeaux\n");
    int a;
    scanf("%d",&a);
    choice(S,a);
    return 0;
}
