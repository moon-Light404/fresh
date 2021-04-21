#include "seqstack.h"

void Dto16(int m) {
	sequence_stack s;
	init(&s);
	printf("十进制%d对应的十六进制是:", m);
	while (m) {
		push(&s, m % 16);
		m = m / 16;
	}
	while (!empty(s)) {
//		printf("%d\n", read(s));
		putchar(read(s) >= 10 ? pop(&s) + 55 : pop(&s) + 48);

	}

	printf("\n");
}

int main() {
	int m;
	printf("请输入带转换的十进制数:\n");
	scanf("%u", &m);
	Dto16(m);
	return 0;
}