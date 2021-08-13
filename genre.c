#include<stdio.h>

int main()
{
	char sexe[2];
	do{
		printf("Genre M ou F: ");
		scanf(" %c" ,&sexe);
	}while(sexe != 'M' || sexe != 'F');
	if(sexe == 'M' || sexe == 'F')
		printf("Ok c bon");
	return 0;
}
