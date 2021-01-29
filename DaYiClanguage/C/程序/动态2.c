#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char name[100];
	char *description;
	char *p;
	
	strcpy(name,"Zara Ali");
	
	description=(char*)malloc(30*sizeof(char));
	
	if(description==NULL)
	{
		fprintf(stderr,"Error-unble to allocate");
	}
	else{
	
		strcpy(description,"Zara ali a DPS student");
		
}
printf("%p\n",description);
	p=(char*)realloc(description,100*sizeof(char));
	if(p==NULL)
	{
		printf("Error!\n");
	}
	else{
		
		strcat(description,"She is in calss 10th");
}
	printf("Name=%s\n",name);
	printf("Description:%s\n",p);
	printf("%p\n",p);
	printf("%p\n",description);
	printf("%s\n",p);
	free(p);
}
