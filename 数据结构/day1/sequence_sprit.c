#include "sequlist.h"

// �������ŵ�L2�У�ż���ŵ�L3��
void sprit(sequence_list *L1, sequence_list *L2, sequence_list *L3) {
	// ��ʼ��size Ϊ0
	initseqlist(L2);
	initseqlist(L3);
	for (int i = 0; i < L1->size; i++) { // ����L1�е�����
		if (L1->a[i] % 2 == 0 ) { // ż��
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