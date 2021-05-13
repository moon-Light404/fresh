#include<stdio.h>
#include<stdlib.h>
struct Book
{
	char title[125];
	char author[40];
	struct Book *next;
	
};
void getInput(struct Book *book)
{
	printf("����������: ");
	scanf("%s", book->title);
	printf("����������: " );
	scanf("%s",book->author);
}
void printBook(struct Book* head)
{
    struct Book* book;
    int count =1;
    
    book=head;
    while(book!=NULL)
    {
        printf("Book%d:",count);
        printf("����:%s",book->title);
        printf("����:%s",book->author);
        book=book->next;
        count++;
    }
}
void releaseBook(struct Book* head)
{
    while(head!=NULL)
    {
        free(head);
        head=head->next;
    }
}
void addBook(struct Book **head)   
    
{
    
	struct Book* book,*temp;
	book=(struct Book *)malloc(sizeof(struct Book));
	if(book==NULL)
	{
		printf("�ڴ����ʧ��\n");
		exit(1);
	}
	
	getInput(book); 
	
	if(*head!=NULL)
	{
		temp=*head;
		*head=book;
		book->next=temp;  
	}
	else{
		*head=book;
		book->next=NULL; 
		
	}
	
	
	
}
int main(void)
{
	struct Book *head= NULL;
	
	
    int ch;
    while(1)
    {
        printf("�Ƿ���Ҫ¼�����ݣ�y/n");
        do{
            ch=getchar();
        }while (ch!='y' && ch!='n');
        if(ch== 'y')
        {
            addBook(&head);
        }
        else{
            break;
        }
    }
    printf("�����Ƿ���Ҫ��ӡͼ����ϢY/N");
    do{
            ch=getchar();
        }while (ch!='y' && ch!='n');
    if(ch=='y')
    {
        printBook(head);
    }
    releaseBook(head);
	return 0;
}

