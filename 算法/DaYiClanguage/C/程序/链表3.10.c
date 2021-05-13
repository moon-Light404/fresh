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
	printf("请输入书名: ");
	scanf("%s", book->title);
	printf("请输入作者: " );
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
        printf("书名:%s",book->title);
        printf("作者:%s",book->author);
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
		printf("内存分配失败\n");
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
        printf("是否需要录入数据？y/n");
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
    printf("请问是否需要打印图书信息Y/N");
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

