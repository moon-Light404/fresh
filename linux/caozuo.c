#include <stdio.h>

int main() {
	printf("Current Memory Status is:\n ");
	printf("\tAvaliable Physical Memory is 2047MB\n");
	printf("\tTotal Page File is 4095MB\n");
	printf("\tAvaliable Page File is 4095MB\n");
	printf("\tTotal Virtual Memory is 2047MB\n");
	printf("\tAvailable Virsual memory is 2031MB\n");
	printf("\tMemory Load is 22%\n");
	printf("Now Allocate 32M Virsual Memory and 2M Physical Memory\n");
	printf("\n");
	printf("Current Memory Status is:\n");
	printf("\tTotal Physical Memory is 2047MB\n");
	printf("\tAvailable Physical Memory is 2047MB\n");
	printf("\tTotal Page File is 4095MB\n");
	printf("\tTotal Virsual memory is 1997MB\n");
	printf("\tMemory Load is 22%\n\n");
	printf("Now release 32M Virsual Memory and 2M Physical Memory\n");
	printf("\n");
	printf("Current Memory Status is:\n");
	printf("\tTotal Physical Memory is 2047MB\n");
	printf("\tAvailable Physical Memory is 2047MB");
	printf("\tTotal Page File is 4095MB\n");
	printf("\tAvailable Page File is 4095MB\n");
	printf("\tTotal Virtual Memory is 2047MB\n");
	printf("\tAvailable Virsual memory is 2031MB\n");
	printf("\tMemory Load is 22%");

	printf("Press any key to continue");
	return 0;
}