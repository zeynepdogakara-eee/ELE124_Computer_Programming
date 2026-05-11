#include <stdio.h>
void printPattern(int n);

int main()
{
	int length;
	printf("Enter the length:\n");
	scanf("%d",&length);
	printPattern(length);
	
	return 0;
}
void printPattern(int n)
{
	if(n<=0) return;
	for(int i=0;i<n;i++)
	{
		printf("*");
	}
	printf("\n");
	printPattern(n-1);	
	
	
}







