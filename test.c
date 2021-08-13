#include<stdio.h>
int main()
{
	int i = 10;printf("%d\t",i);
	while(i)
	{
		if(i%2) continue;
		printf("%d\t",i);
		i--;
	}
}
