#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int mono_fun(int *arr) {
	int i, k = 0;
	for (i = 0; i < 16; ++i)
		printf("%d ", arr[i]);
	for (i = 0; i < 8; ++i)
		if (arr[i] <= arr[8 + i])
			k++;
		else
			return 0;
	if (k == 8)
		for (i = 0; i < 4; ++i)
			if (arr[i] <= arr[4 + i])
				k++;
			else
				return 0;
	if (k == 12)
		for (i = 0; i < 4; ++i)
			if (arr[4 + i] <= arr[12 + i])
				k++;
			else
				return 0;
	if (k == 16)
		for (i = 0; i < 2; ++i)
			if (arr[i] <= arr[2 + i])
				k++;
			else
				return 0;
	if (k == 18)
		for (i = 0; i < 2; ++i)
			if (arr[4 + i] <= arr[6 + i])
				k++;
			else
				return 0;
	if (k == 20)
		for (i = 0; i < 2; ++i)
			if (arr[8 + i] <= arr[10 + i])
				k++;
			else
				return 0;
	if (k == 22)
		for (i = 0; i < 2; ++i)
			if (arr[12 + i] <= arr[14 + i])
				k++;
			else
				return 0;
	if (k == 24)
		return 1;
	return 0;	
}

int lin_fun(int *arr) {
	int i, j;
	int arr_rev[16][16];
	for (i = 1; i < 17; ++i) {
		for (j = 0; j < (16 - i); ++j) {
			if ((j >= 0 || j <= 15) && i == 1)
				arr_rev[i][j] = arr[j] + arr[j + 1];
			else
				arr_rev[i][j] = arr_rev[i - 1][j] + arr_rev[i - 1][j + 1];
			if (arr_rev[i][j] == 2)
				arr_rev[i][j] = 0;
			printf("%d ", arr_rev[i][j]);
		}
		printf("   \n");
	}
	if (arr_rev[3][0] == 1 || arr_rev[5][0] == 1 || arr_rev[6][0] == 1)
		return 0;
	if (arr_rev[7][0] == 1 || arr_rev[9][0] == 1 || arr_rev[10][0] == 1)
		return 0;
	if (arr_rev[11][0] == 1 || arr_rev[12][0] == 1 || arr_rev[13][0] == 1)
		return 0;
	if (arr_rev[14][0] == 1 || arr_rev[15][0] == 1)
		return 0;
	return 1;
}

int main() {
	int i, flag = 0;
	int arr[16];
	for (i = 0; i < 16; ++i) {
		scanf("%d", &arr[i]);
	}
	printf("\n------\nWhat we got: ");
	for (i = 0; i < 16; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n------\n");
	if (arr[0] == 0)
		printf("------\nT0 - YES! %d\n", arr[0]);
	else
		printf("------\nT0 - NO! %d\n", arr[0]);
	if (arr[15] == 1)
		printf("------\nT1 - YES! %d\n", arr[15]);
	else 
		printf("------\nT1 - NO! %d\n", arr[15]);

	for (i = 0; i < 8; i++) {
		if (arr[i] == arr[15 - i]) {
			printf("------\nS - NO!\n");
			break;
		}
		if (arr[i] != arr[15 - i])
			flag++;
	}
	if (flag == 8)
		printf("------\nS - YES!\n------\n");

	printf("------\nHanded array to the function result: ");

	if (mono_fun(arr) == 1)
		printf("\n------\nM - YES!\n");
	else
		printf("\n------\nM - NO!\n");
	printf("------\n");
	if (lin_fun(arr) == 1)
		printf("------\nL - YES!\n");
	else
		printf("------\nL - NO!\n");
	
	printf("------\n");


	return 0;
}