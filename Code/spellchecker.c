#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()
{
	int arr_size = 175000;
	char *a[arr_size];
	FILE *fptr;
	fptr = fopen("Database\\words.txt","r");	// write the data file location
	char check[100];				// check word
	int size = sizeof(check);		
	int i=0,l;
	while(fgets(check, size, fptr) != NULL)		//fetching data from file
	{	
		l=strlen(check);		//length of check word
		
		
		if(check[l-1]=='\n')
			check[l-1]='\0';
		
		a[i]=strdup(check);		//strdup function
		i++;
	}
	int flag=0,j=0;
	
	char str[100],b[100],ans[100];
		printf("Enter a string to check:\n");		//user input
		gets(b);
		strcpy(str,strlwr(b));
	
		for(j=0;j<i;j++)
		{
			if(strcmp(str,a[j])==0)		//comparing 
			{
				flag=1;
				break;
			}
		}
		
		if(flag==1)
			printf("Entered string is correct\n");
		else
			printf("Entered string does not exist in dictionary\n");
		fclose(fptr);
	
}


