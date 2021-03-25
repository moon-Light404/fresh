#include <stdlib.h>
#include <stdio.h>
typedef int datatype;

typedef struct link_node {
	datatype info;
	struct link_node *next;
} node;

typedef node *linklist;

linklist creatbystack() {
	linklist head, s;
	datatype x;
	head = NULL;
	printf("请输入若干整数序列:\n");
	scanf("%d", &x);
	while (x != 0) {
		s = (linklist)malloc(sizeof(node));
		s->info = x;
		s->next = head;
		head = s;
		scanf("%d", &x);
	}
	return head;
}

linklist creatbyqueue() {
	linklist head, r, s;
	datatype x;
	head = r = NULL;
	printf("请输入若干整数序列:\n");
	scanf("%d", &x);
	while (x != 0) {
		s = (linklist)malloc(sizeof(node));
		s->info = x;
		if (head == NULL)
			head = s;
		else
			r -> next = s;
		r = s;
		scanf("%d", &x);
	}
	if (r)
		r->next = NULL;
	return head;
}

void print(linklist head) {
	linklist p;
	int i = 0;
	p = head;
	printf("List is:\n");
	while (p) {
		printf("%5d", p->info);
		p = p->next;
		i++;
		if (i % 10 == 0)
			printf("\n");
	}
	printf("\n");
}

void delList(linklist head) {
	linklist p = head;
	while (p) {
		head = p->next;
		free(p);
		p = head;
	}
}