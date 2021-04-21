#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char data;
	struct node *next;
} linkstrnode;
typedef linkstrnode *linkstring;


linkstring create() {
	char ch;
	linkstring s, head, r;
	head = r = (linkstring)malloc(sizeof(linkstrnode));
	head->next = NULL;
	printf("������һ���ַ���:\n");
	while ((ch = getchar()) != '\n') {
		s = (linkstrnode *) malloc(sizeof(linkstrnode));
		s->data = ch;
		r->next = s;
		r = s;
	}
	r->next = NULL;
	return head;
}

void print(linkstring s) { // s��һ��ָ��
	linkstring p = s->next; // ��ʼָ��
	while (p) {
		printf("%c", p->data);
		p = p->next;
	}
	printf("\n");
}

void delList(linkstring s) {
	linkstring p = s;
	while (s) {
		free(p);
		p = s->next;
	}
}


