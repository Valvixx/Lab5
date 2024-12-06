#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <locale.h>

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "Russian");
	int n = 10, ** G = NULL, count = 0, * deg = NULL, * loop = NULL, ** I, count_i = 0, * deg_i = NULL, * loop_i = NULL, sum = 0;

	srand(time(NULL));

	printf("N = ");
	scanf("%d", &n);
	printf("\n");

	G = (int**)malloc(n * sizeof(int*));
	deg = (int*)malloc(n * sizeof(int));
	loop = (int*)malloc(n * sizeof(int));
	deg_i = (int*)malloc(n * sizeof(int));
	loop_i = (int*)malloc(n * sizeof(int));


	for (int i = 0; i < n; i++) {
		deg[i] = 0;
		loop[i] = 0;
		deg_i[i] = 0;
		loop_i[i] = 0;
		G[i] = (int*)malloc(n * sizeof(int));
	}

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			G[i][j] = rand() % 2;
			G[j][i] = G[i][j];
			count += G[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) {
				loop[i] += 2 * G[j][i];
				deg[i] += 2 * G[j][i];
			}
			else {
				deg[i] += G[j][i];
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", G[i][j]);
		}
		printf("\n");
	}

	printf("\nРазмер = %d\n\n", count);


	for (int i = 0; i < n; i++) {
		if (deg[i] - loop[i] == 0) printf("Вершина %d - Изолированная\n", i);
		if (deg[i] - loop[i] == 1) printf("Вершина %d - Концевая\n", i);
		if (deg[i] - loop[i] == n - 1) printf("Вершина %d - Доминирующая\n", i);
	}
	printf("\n");

	I = (int**)malloc(n * sizeof(int*));

	for (int i = 0; i < n; i++) {
		I[i] = (int*)malloc(count * sizeof(int));
		for (int j = 0; j < count; j++) {
			I[i][j] = 0;
		}
	}


	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (G[i][j] == 1) {
				if (i != j) {
					I[i][count_i] = 1;
					I[j][count_i] = 1;
				}
				else {
					I[i][count_i] = 2;
				}
				count_i++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < count; j++) {
			printf("%d ", I[i][j]);
		}
		printf("\n");
	}

	printf("\nРазмер = %d\n\n", count_i);


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < count; j++) {
			if (I[i][j] == 1) {
				deg_i[i] += I[i][j];
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (deg_i[i] == 0) printf("Вершина %d - Изолированная\n", i);
		if (deg_i[i] == 1) printf("Вершина %d - Концевая\n", i);
		if (deg_i[i] == n - 1) printf("Вершина %d - Доминирующая\n", i);
	}

    for (int i = 0; i < n; i++) {
        free(G[i]);
    }
    free(G);
    free(loop);

    return 0;
}
