// Lab5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Russian");
	int n = 10, ** G = NULL, size = 0, * degree = NULL, * loop = NULL;
	printf("Введите количество вершин:");
	scanf("%d", &n);
	printf("\n");

	degree = (int*)malloc(n * sizeof(int*));
	loop = (int*)malloc(n * sizeof(int*));
	G = (int**)malloc(n * sizeof(int*));

	for (int i = 0; i < n; i++)
	{
		G[i] = (int*)malloc(n * sizeof(int));
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			G[i][j] = 0;



	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++)
		{
			G[i][j] = rand() % 2;
			G[j][i] = G[i][j];
			size += G[i][j];

			if (i == j)
			{
				degree[i] += 2 * G[i][j];
				loop[i] += 2 * G[i][j];
			}
			else
			{
				degree[i] += G[i][j];
			}
		}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", G[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	printf("Размер: %d \n\n", size);

	for (int i = 0; i < n; i++)
	{
		if (degree[i] - loop[i] == 0)
			printf("Вершина %d - Изолированная\n", i);
		if (degree[i] - loop[i] == 1)
			printf("Вершина %d - Концевая\n", i);
		if (degree[i] - loop[i] == n)
			printf("Вершина %d - Доминирующая\n", i);
	}


	// ---Task 2---

	int m, ** IncMatrix = NULL;

	printf("Введите количество вершин: ");
	scanf("%d", &n);

	printf("Введите количество рёбер: ");
	scanf("%d", &m);

	// Выделение памяти для массива степеней и петель
	degree = (int*)calloc(n, sizeof(int));
	loop = (int*)calloc(n, sizeof(int));

	// Выделение памяти для матрицы инцидентности
	IncMatrix = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++)
		IncMatrix[i] = (int*)calloc(m, sizeof(int));

	// Заполнение матрицы инцидентности
	for (int j = 0; j < m; j++) {
		int v1, v2;
		printf("Введите вершины для ребра %d (через пробел): ", j + 1);
		scanf("%d %d", &v1, &v2);

		if (v1 == v2) {
			IncMatrix[v1][j] = 2; // Петля
			degree[v1] += 2;
			loop[v1] += 2;
		}
		else {
			IncMatrix[v1][j] = 1;
			IncMatrix[v2][j] = 1;
			degree[v1]++;
			degree[v2]++;
		}
	}

	// Вывод матрицы инцидентности
	printf("\nМатрица инцидентности:\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", IncMatrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	for (int i = 0; i < n; i++) {
		if (degree[i] - loop[i] == 0)
			printf("Вершина %d - Изолированная\n", i);
		if (degree[i] - loop[i] == 1)
			printf("Вершина %d - Концевая\n", i);
		if (degree[i] == n - 1)
			printf("Вершина %d - Доминирующая\n", i);
	}

	for (int i = 0; i < n; i++)
		free(IncMatrix[i]);
	free(IncMatrix);
	free(degree);
	free(loop);

	return 0;
}