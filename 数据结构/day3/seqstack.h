#include <stdlib.h>
#include <stdio.h>
#define MAXSIZE 100
typedef int datatype;

typedef struct {
	datatype a[MAXSIZE];
	int top;
} sequence_stack;


void init(sequence_stack *st) {
	st->top = 0;
}

int empty(sequence_stack st) {
	return (st.top ? 0 : 1);
}

datatype read(sequence_stack st) {
	if (empty(st)) {
		printf("\nÕ»ÊÇ¿ÕµÄ");
		exit(1);
	} else
		return st.a[st.top - 1];
}

void push(sequence_stack *st, datatype x) {
	if (st->top == MAXSIZE) {
		printf("\nThe sequence stack is full");
		exit(1);
	}
	st->a[st->top] = x;
	st->top++;
}

int pop(sequence_stack *st) {
	if (st->top == 0) {
		printf("\nThe sequence stack is empty");
		exit(1);
	}
	return st->a[--st->top];
}