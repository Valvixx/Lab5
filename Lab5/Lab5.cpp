// Lab5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Russian");
	int n = 10, ** G = NULL, size = 0, *degree = NULL, *loop = NULL;
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
				degree[i] += 2*G[i][j];
				loop[i] += 2*G[i][j];
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


