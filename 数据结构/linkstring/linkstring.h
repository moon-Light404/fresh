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
	printf("请输入一个字符串:\n");
	while ((ch = getchar()) != '\n') {
		s = (linkstrnode *) malloc(sizeof(linkstrnode));
		s->data = ch;
		r->next = s;
		r = s;
	}
	r->next = NULL;
	return head;
}

void print(linkstring s) { // s是一个指针
	linkstring p = s->next; // 起始指针
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


