#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
/*
需要输入的数据：64bit 密钥   64bit 明文
Li = Ri-1
Ri = Li-1 (+) F(Ri-1,Ki)

每一轮密钥的生成
56bit密钥(输入) -> 置换选择1(8 X 7) -> 56bit -> 分成左右C0和D0两部分 -> 分别对C0和D0移位 -> 置换选择2( 8 X 6)
移位后的结果作为下一轮子密钥的输入/置换选择2的输入
*/

// 初始明文置换表
int IP_T[64] = {
	58, 50, 42, 34, 26, 18, 10, 2,
	60, 52, 44, 36, 28, 20, 12, 4,
	62, 54, 46, 38, 30, 22, 14, 6,
	64, 56, 48, 40, 32, 24, 16, 8,
	57, 49, 41, 33, 25, 17, 9, 1,
	59, 51, 43, 35, 27, 19, 11, 3,
	61, 53, 45, 37, 29, 21, 13, 5,
	63, 55, 47, 39, 31, 23, 15, 7
};

// 逆初始置换IP-1

int IPR_T[64] = {
	40, 8, 48, 16, 56, 24, 64, 32,
	39, 7, 47, 15, 55, 23, 63, 31,
	38, 6, 46, 14, 54, 22, 62, 30,
	37, 5, 45, 13, 53, 21, 61, 29,
	36, 4, 44, 12, 52, 20, 60, 28,
	35, 3, 43, 11, 51, 19, 59, 27,
	34, 2, 42, 10, 50, 18, 58, 26,
	33, 1, 41,  9, 49, 17, 57, 25
};

// 置换选择1
int PCT_1[56] = {
	57, 49, 41, 33, 25, 17, 9,
	1, 58, 50, 42, 34, 26, 18,
	10, 2, 59, 51, 43, 35, 27,
	19, 11, 3, 60, 52, 44, 36,
	63, 55, 47, 39, 31, 23, 15,
	7, 62, 54, 46, 38, 30, 22,
	14, 6, 61, 53, 45, 37, 29,
	21, 13, 5, 28, 20, 12, 4
};

// 置换选择2
int PCT_2[48] = {
	14, 17, 11, 24, 1, 5,
	3, 28, 15, 6, 21, 10,
	23, 19, 12, 4, 26, 8,
	16, 7, 27, 20, 13, 2,
	41, 52, 31, 37, 47, 55,
	30, 40, 51, 45, 33, 48,
	44, 49, 39, 56, 34, 53,
	46, 42, 50, 36, 29, 32
};

// E盒扩展置换 扩展矩阵 32位扩展为48位
int E_T[48] = {
	32, 1,  2,  3,  4,  5,
	4,  5,  6,  7,  8,  9,
	8,  9,  10, 11, 12, 13,
	12, 13, 14, 15, 16, 17,
	16, 17, 18, 19, 20, 21,
	20, 21, 22, 23, 24, 25,
	24, 25, 26, 27, 28, 29,
	28, 29, 30, 31, 32,  1
};

// S 盒置换
int S_box[8][4][16] = {
	// S1
	14, 4,  13,  1,  2, 15, 11,  8,  3, 10,  6, 12,  5,  9,  0,  7,
	0, 15,  7,  4, 14,  2, 13,  1, 10,  6, 12, 11,  9,  5,  3,  8,
	4,  1, 14,  8, 13,  6,  2, 11, 15, 12,  9,  7,  3, 10,  5,  0,
	15, 12,  8,  2,  4,  9,  1,  7,  5, 11,  3, 14, 10,  0,  6, 13,

	// S2
	15,  1,  8, 14,  6, 11,  3,  4,  9,  7,  2, 13, 12,  0,  5, 10,
	3, 13,  4,  7, 15,  2,  8, 14, 12,  0,  1, 10,  6,  9, 11,  5,
	0, 14,  7, 11, 10,  4, 13,  1,  5,  8, 12,  6,  9,  3,  2, 15,
	13,  8, 10,  1,  3, 15,  4,  2, 11,  6,  7, 12,  0,  5, 14,  9,

	// S3
	10,  0,  9, 14,  6,  3, 15,  5,  1, 13, 12,  7, 11,  4,  2,  8,
	13,  7,  0,  9,  3,  4,  6, 10,  2,  8,  5, 14, 12, 11, 15,  1,
	13,  6,  4,  9,  8, 15,  3,  0, 11,  1,  2, 12,  5, 10, 14,  7,
	1, 10, 13,  0,  6,  9,  8,  7,  4, 15, 14,  3, 11,  5,  2, 12,

	// S4
	7, 13, 14,  3,  0,  6,  9, 10,  1,  2,  8,  5, 11, 12,  4, 15,
	13,  8, 11,  5,  6, 15,  0,  3,  4,  7,  2, 12,  1, 10, 14,  9,
	10,  6,  9,  0, 12, 11,  7, 13, 15,  1,  3, 14,  5,  2,  8,  4,
	3, 15,  0,  6, 10,  1, 13,  8,  9,  4,  5, 11, 12,  7,  2, 14,

	// S5
	2, 12,  4,  1,  7, 10, 11,  6,  8,  5,  3, 15, 13,  0, 14,  9,
	14, 11,  2, 12,  4,  7, 13,  1,  5,  0, 15, 10,  3,  9,  8,  6,
	4,  2,  1, 11, 10, 13,  7,  8, 15,  9, 12,  5,  6,  3,  0, 14,
	11,  8, 12,  7,  1, 14,  2, 13,  6, 15,  0,  9, 10,  4,  5,  3,

	// S6
	12,  1, 10, 15,  9,  2,  6,  8,  0, 13,  3,  4, 14,  7,  5, 11,
	10, 15,  4,  2,  7, 12,  9,  5,  6,  1, 13, 14,  0, 11,  3,  8,
	9, 14, 15,  5,  2,  8, 12,  3,  7,  0,  4, 10,  1, 13, 11,  6,
	4,  3,  2, 12,  9,  5, 15, 10, 11, 14,  1,  7,  6,  0,  8, 13,

	// S7
	4, 11,  2, 14, 15,  0,  8, 13,  3, 12,  9,  7,  5, 10,  6,  1,
	13,  0, 11,  7,  4,  9,  1, 10, 14,  3,  5, 12,  2, 15,  8,  6,
	1,  4, 11, 13, 12,  3,  7, 14, 10, 15,  6,  8,  0,  5,  9,  2,
	6, 11, 13,  8,  1,  4, 10,  7,  9,  5,  0, 15, 14,  2,  3, 12,

	// S8
	13,  2,  8,  4,  6, 15, 11,  1, 10,  9,  3, 14,  5,  0, 12,  7,
	1, 15, 13,  8, 10,  3,  7,  4, 12,  5,  6, 11,  0, 14,  9,  2,
	7, 11,  4,  1,  9, 12, 14,  2,  0,  6, 10, 13, 15,  3,  5,  8,
	2,  1, 14,  7,  4, 10,  8, 13, 15, 12,  9,  0,  3,  5,  6, 11
};


// P 盒置换，将S盒得到的32位数置换32位数
int P_T[32] = {
	16, 7, 20, 21,
	29, 12, 28, 17,
	1, 15, 23, 26,
	5, 18, 31, 10,
	2, 8, 24, 14,
	32, 27, 3, 9,
	19, 13, 30, 6,
	22, 11, 4, 25
};

// 左循环移位数
int Move[17] = {0, 1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};

// 将char数组转换为64位的二进制
void CharToBit(char input[], int out[], int len) {
	for (int i = 0; i < len; i++) {
		for (int j = 7; j >= 0; j--)
			out[8 * i + j] = (input[i] >> j) & 1;
//			cout << ((input[i] >> j ) & 1);
//		cout << endl;
	}
}

// 将64位二进制转化为8byte Char类型
void BitToChar(int input[], char output[], int bits) {
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			output[i] = output[i] * 2 + input[8 * i + j]; // 类似十进制的求法,用数字赋值默认转为Char型
}

// 异或操作
void XOR(int A[], int B[], int len) {
	for (int i = 0; i < len; i++)
		A[i] = A[i] ^ B[i]; // 最终异或结果为A[i]
}

// 初始IP置换
void IP(int input[64], int output[64]) {
	for (int i = 0; i < 64; i++) {
		output[i] = input[IP_T[i] - 1];
	}
}

// 扩展置换 32->48位
void E(int input[32], int output[48]) {
	for (int i = 0; i < 48; i++)
		output[i] = input[E_T[i] - 1];
}

// P 置换,S盒子处理之后就是P置换
void P(int input[32], int output[32]) {
	for (int i = 0; i < 32; i++)
		output[i] = input[P_T[i] - 1];
}

// IP逆置换
void IP_N(int input[64], int output[64]) {
	for (int i = 0; i < 64; i++)
		output[i] = input[IPR_T[i] - 1];
}



// PC1置换1
void PC_1(const int input[64], int output[56]) {
	for (int i = 0; i < 56; i++)
		output[i] = input[PCT_1[i] - 1];
}

void PC_2(int input[56], int output[48]) {
	for (int i = 0; i < 48; i++)
		output[i] = input[PCT_2[i] - 1];
}

// S盒压缩 48bit->32bit
void S(int input[48], int output[32]) {
	int SI[8], k = 0;
	for (int i = 0; i < 48; i += 6)
		SI[k] = S_box[k++][(input[i] << 1) + input[i + 5]] [(input[i + 1] << 3) + (input[i + 2] << 2) + (input[i + 3] << 1 ) +
		        (input[i + 4])];
	for (int j = 0; j < 8; j++)
		for (int i = 0; i < 4; i++)
			output[4 * j + 3 - i] = (SI[j] >> i ) & 1;
}


void F_func(int input[32], int output[32], int subkey[48]) { //完成DES算法轮变换
	int len = 48;
	int temp[48] = { 0 }, temp_1[32] = { 0 };
	E(input, temp);  //E盒扩展置换
	XOR(temp, subkey, len);  //与Ki异或
	S(temp, temp_1);         //S盒代替压缩
	P(temp_1, output);       //P盒置换
};

void RotateL(int input[28], int output[28], int leftCount) { //秘钥循环左移
	int len = 28;
	for (int i = 0; i < len; i++)
		output[i] = input[(i + leftCount) % len];
};

void  subKey_fun(int input[64], int Subkey[16][48]) { //子密钥生成
	int c[28], d[28];
	int pc_1[56] = { 0 }, pc_2[16][56] = { 0 };
	int rotatel_c[16][28] = { 0 }, rotatel_d[16][28] = { 0 };
	PC_1(input, pc_1);
	for (int i = 0; i < 28; i++) {
		c[i] = pc_1[i];
		d[i] = pc_1[i + 28];
	}
	int ans = 0;
	for (int i = 1; i <= 16; i++) {
		ans += Move[i];
		RotateL(c, rotatel_c[i - 1], ans);
		RotateL(d, rotatel_d[i - 1], ans);
	}
	for (int i = 0; i < 16; i++)
		for (int j = 0; j < 28; j++) {
			pc_2[i][j] = rotatel_c[i][j];
			pc_2[i][j + 28] = rotatel_d[i][j];
		}
	// P 置换
	for (int i = 0; i < 16; i++)
		PC_2(pc_2[i], Subkey[i]);
};

// 加密函数
void  DES_Efun(char input[8], char key_in[8], int output[64]) {
	int Ip[64] = { 0 };//存储初始置换后的矩阵
	int output_1[64] = { 0 }; //存储16轮迭代后，左右交换后合并的64bit
	int subkeys[16][48];     //存16轮子密钥
	int chartobit[64] = { 0 }, l[17][32], r[17][32], key[64];
	CharToBit(input, chartobit, 8);  //转换为64个二进制数
	IP(chartobit, Ip);               //IP初始置换,Ip存置换后的数
	CharToBit(key_in, key, 8);       //密钥转换为64位二进制数
	subKey_fun(key, subkeys);        //密钥变换
	for (int i = 0; i < 32; i++) {
		l[0][i] = Ip[i];
		r[0][i] = Ip[32 + i];
	}
	for (int i = 1; i <= 16; i++) { //16轮的迭代操作
		for (int k = 0; k < 32; k++) //下一轮的左半部分就是上一轮的右半部分
			l[i][k] = r[i - 1][k];

		F_func(r[i - 1], r[i], subkeys[i - 1]);
		XOR(r[i], l[i - 1], 32);
	}
	for (int t = 0; t < 32; t++) { //将16轮迭代后的32bit左右置换并合并
		output_1[t] = l[16][t];
		output_1[32 + t] = r[16][t];
	}
	IP_N(output_1, output);  //IP逆置换
};

// 解密函数
void  DES_Dfun(int input[64], char key_in[8], char output[8]) {
	int Ip[64] = { 0 };//存储初始置换后的矩阵
	int output_1[64] = { 0 }, output_2[64] = { 0 };
	int subkeys[16][48];  //存16轮子密钥
	int chartobit[64] = { 0 };
	int key[64], l[17][32], r[17][32];
	IP(input, Ip);              //IP初始置换
	CharToBit(key_in, key, 8);  //密钥转变为64位2进制数列
	subKey_fun(key, subkeys);   //求16轮子密钥
	for (int i = 0; i < 32; i++) {
		l[0][i] = Ip[i];
		r[0][i] = Ip[32 + i];
	}
	for (int j = 1; j <= 16; j++) { //16轮的迭代操作
		for (int k = 0; k < 32; k++)
			l[j][k] = r[j - 1][k];
		F_func(r[j - 1], r[j], subkeys[16 - j]);
		XOR(r[j], l[j - 1], 32);
	}
	for (int t = 0; t < 32; t++) { //将16轮迭代后的32bit左右置换并合并
		output_1[t] = l[16][t];
		output_1[32 + t] = r[16][t];
	}
	IP_N(output_1, output_2);  //IP逆置换
	BitToChar(output_2, output, 8);  //转变为字符形式
};

int main() {
	while (1) {
		int n, output[64] = {0};
		char MIN[10] = {0};
		char KEY[10] = {0};
		char MI[65] = {0};
		printf("1:明文加密  2:密文解密  0:结束使用\n选择功能: ");
		scanf("%d", &n);
		if (n == 0)
			break;
		else if (n == 1) {
			printf("请输入明文(8字节)\n");
			scanf("%s", MIN);
			printf("请输入密钥(8字节)\n");
			scanf("%s", KEY);
			DES_Efun(MIN, KEY, output);
			printf("密文如下:\n");
			for (int i = 0; i < 64; i++) {
				printf("%d", output[i]);
				if ((i + 1) % 8 == 0)
					printf("\n");
			}
			printf("\n");
		} else if (n == 2) {
			printf("请输入密文(8字节)\n");
			scanf("%s", MI);
			for (int i = 0; i < 64; i++)
				output[i] = MI[i] - '0';
			printf("请输入密钥(8字节)\n");
			scanf("%s", KEY);
			DES_Dfun(output, KEY, MIN);
			printf("明文如下:\n");
			for (int i = 0; i < 8; i++)
				printf("%c", MIN[i]);
			printf("\n\n");
		}
	}
	return 0;
}
