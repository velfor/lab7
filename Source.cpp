#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>

void printmenu() {
	printf("\n1 - Solve task 1\n");
	printf("2 - Solve task 2\n");
	printf("3 - Solve task 3\n");
	printf("4 - Solve task 4\n");
	printf("5 - Exit\n");
}

int minf(float** mas, int n, int col) {
	int pos_min = 0;
	for (int i = 0; i < n; i++) {
		if (mas[i][col] < mas[pos_min][col]) {
			pos_min = i;
		}
	}
	return pos_min;
}

bool ismin(float** mas, int n, int col) {
	return minf(mas, n, col) == col;
}

bool matmin(float** mas, int n) {
	bool flag = true;
	for (int j = 0; j < n; j++) {
		if (!ismin(mas, n, j)) {
			flag = false;
			break;
		}
	}
	return flag;
}

float ari(float** mas, int n) {
	float col = 0, mid = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i > j) {
				col++;
				mid = mid + mas[i][j];
			}
		}
	}
	mid = mid / col;
	return mid;
}

void dobalari(float** mas, int n) {
	float p = ari(mas, n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i < j) {
				mas[i][j] += p;
			}
		}
	}
}

void first() {
	float** mas, col, min, mid;
	int n;
	printf("N: ");
	scanf("%i", &n);
	mas = (float**)malloc(n * sizeof(float*));
	for (int i = 0; i < n; i++) {
		mas[i] = (float*)malloc(n * sizeof(float));
	}
	col = 0;
	mid = 0;
	for (int i = 0; i < n; i++) {
		printf("Vvedite stroku %i\n", i);
		for (int j = 0; j < n; j++) {
			scanf("%f", &mas[i][j]);
		}
	}
	if (matmin(mas, n)) {
		dobalari(mas, n);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%10.5f ", mas[i][j]);
		}
		printf("\n");
	}
}

void second() {
	float** mas, col;
	int n, k;
	k = 0;
	printf("N: ");
	scanf("%i", &n);
	mas = (float**)malloc(n * sizeof(float*));
	for (int i = 0; i < n; i++) {
		mas[i] = (float*)malloc(n * sizeof(float));
	}
	for (int i = 0; i < n; i++) {
		printf("Vvedite stroku %i\n", i);
		for (int j = 0; j < n; j++) {
			scanf("%f", &mas[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		bool flag = true;
		for (int j = 0; j < n; j++) {
			if (mas[i][j] == 0) {
				flag = false;
				break;
			}
		}
		if (flag) {
			k++;
		}
	}
	printf("Colichestvo stolbcov: %i", k);

}

int minstr(float** mas, int n, int st) {
	int num = 0;
	for (int j = 0; j < n; j++) {
		if (mas[st][j] < mas[st][num]) {
			num = j;
		}
	}
	return num;
}

int maxcol(float** mas, int n, int co) {
	int num = 0;
	for (int i = 0; i < n; i++) {
		if (mas[i][co] < mas[i][num]) {
			num = i;
		}
	}
	return num;
}

void third() {
	float** mas, maxco;
	int n, k, minst;
	k = 0;
	printf("N: ");
	scanf("%i", &n);
	mas = (float**)malloc(n * sizeof(float*));
	for (int i = 0; i < n; i++) {
		mas[i] = (float*)malloc(n * sizeof(float));
	}
	for (int i = 0; i < n; i++) {
		printf("Vvedite stroku %i\n", i);
		for (int j = 0; j < n; j++) {
			scanf("%f", &mas[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		minst = minstr(mas, n, i);
		maxco = maxcol(mas, n, minst);
		if (i == maxco) {
			printf("%i  %i\n", i, minst);
		}
	}

}

bool ub(float** mas, int n, int st) {
	bool flag = true;
	for (int i = 0; i < n - 1; i++) {
		if (mas[i][st] < mas[i + 1][st]) {
			flag = false;
			break;
		}
	}
	return flag;
}

bool vozr(float** mas, int n, int st) {
	bool flag = true;
	for (int i = 0; i < n - 1; i++) {
		if (mas[i][st] > mas[i + 1][st]) {
			flag = false;
			break;
		}
	}
	return flag;
}

void sort(float** mas, int n, int coll) {
	int num_max = 0;
	float c = 0;
	//сортируем столбец coll
	//повторяем столько раз, сколько элементов в столбце
	for(int k = 0; k < n; k++){
		//ищем в столбце максимальный элемент
		for (int i = k; i < n; i++) {
			if (mas[i][coll] > mas[num_max][coll]) {
				num_max = i;
			}
		}
		//переставляем местами макс и 1-й неотсортированный
		c = mas[num_max][coll];
		mas[num_max][coll] = mas[k][coll];
		mas[k][coll] = c;
	}
	
}

void printMatrix(float** mas, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%8.5f",mas[i][j]);
		}
		printf("\n");
	}
}

void fourth() {
	float** mas, maxco;
	int n, k, minst;
	k = 0;
	printf("N: ");
	scanf("%i", &n);
	mas = (float**)malloc(n * sizeof(float*));
	for (int i = 0; i < n; i++) {
		mas[i] = (float*)malloc(n * sizeof(float));
	}
	for (int i = 0; i < n; i++) {
		printf("Vvedite stroku %i\n", i);
		for (int j = 0; j < n; j++) {
			scanf("%f", &mas[i][j]);
		}
	}
	//вывод матрицы
	printf("\nOriginal matrix\n");
	printMatrix(mas, n);
	bool flag = true;
	for (int j = 0; j < n; j++) {
		if (!(ub(mas, n, j) || vozr(mas, n, j))) {
			flag = false;
			break;
		}
	}
	if (flag) {
		printf("Vse stolbci matritsi uporadochena");
	}
	else {

		for (int j = 0; j < n; j++) {
			sort(mas, n, j);
		}
		//вывод матрицы
		printf("\nSorted matrix\n");
		printMatrix(mas, n);
	}
}

int main()
{
	int k = 0;
	while (true) {
		printmenu();
		scanf("%i", &k);
		switch (k) {
		case 1: first(); break;
		case 2: second(); break;
		case 3: third(); break;
		case 4: fourth(); break;
		case 5: return 0;
		default: printf("Wrong number");
		}
	}

}
