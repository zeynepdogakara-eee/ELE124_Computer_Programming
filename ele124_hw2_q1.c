#include <stdio.h>
#include <string.h>
void compressString(char *str);

 int main()
 {
 	char str[1000];
 	printf("Enter a string:");
    scanf("%s",str);
    compressString(str);
    return 0;
 }
 
 void compressString(char *str)
 {
 	int length=strlen(str);
 	for(size_t i=0;i<length;i++)
 	{
 		int count=1;
	    while(i<length-1 && str[i]==str[i+1])
	    {
	    	i++;
	   	    count++;
	    }
	    printf("%c%d",str[i],count);
	}	
 }
 
 
 
 
 