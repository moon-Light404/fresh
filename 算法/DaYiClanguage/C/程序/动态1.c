#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char name[100];
	char *description;
	
	strcpy(name,"Zara Ali");
	
	description=(char*)malloc(30*sizeof(char));
	
	if(description==NULL)
	{
		fprintf(stderr,"Error-unble to allocate");
	}
	else
	{
		strcpy(description,"Zara ali a DPS student");
	}
	description=(char*)realloc(description,100*sizeof(char));
	if(description==NULL)
	{
	  fprintf(stderr,"Error");	
	}
	else
	{
		stract(description,"She is in calss 10th");
	}
	printf("Name=%s\n",name);
	printf("Description:%s\n",description);
	free(description);
}
