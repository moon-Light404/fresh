#include "sequlist.h"

// 把奇数放到L2中，偶数放到L3中
void sprit(sequence_list *L1, sequence_list *L2, sequence_list *L3) {
	// 初始化size 为0
	initseqlist(L2);
	initseqlist(L3);
	for (int i = 0; i < L1->size; i++) { // 遍历L1中的数组
		if (L1->a[i] % 2 == 0 ) { // 偶数
			L3 ->a[L3->size++] = L1->a[i];
		} else {
			L2->a[L2->size++] = L1->a[i];
		}
	}
}

int main() {
	sequence_list L1, L2, L3;
	input(&L1);
	sprit(&L1, &L2, &L3);
	print(&L1);
	print(&L2);
	print(&L3);
	return 0;
}