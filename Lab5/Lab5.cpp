#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <locale.h>

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "Russian");
    int n = 10, ** G = NULL, size = 0, * degree = NULL, * loop = NULL;
    printf("Введите количество вершин:");
    scanf("%d", &n);
    printf("\n");

    degree = (int*)calloc(n, sizeof(int));
    loop = (int*)calloc(n, sizeof(int));
    G = (int**)malloc(n * sizeof(int*));

    for (int i = 0; i < n; i++)
    {
        G[i] = (int*)calloc(n, sizeof(int));
    }

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
                degree[j] += G[i][j];
            }
            
        }

    printf("Матрица смежности:\n");
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

    int m = size, ** IncMatrix = NULL;

    // Выделение памяти для матрицы инцидентности
    IncMatrix = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
        IncMatrix[i] = (int*)calloc(m, sizeof(int));

    // Генерация матрицы инцидентности из матрицы смежности
    int edgeIndex = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (G[i][j] > 0) {
                if (i == j) {
                    IncMatrix[i][edgeIndex] = 2; // Петля
                }
                else {
                    IncMatrix[i][edgeIndex] = 1;
                    IncMatrix[j][edgeIndex] = 1;
                }
                edgeIndex++;
            }
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

    // Проверка и вывод свойств вершин
    for (int i = 0; i < n; i++) {
        // Изолированная вершина: не имеет соединений
        if (degree[i] - loop[i] == 0) {
            printf("Вершина %d - Изолированная\n", i);
        }
        // Концевая вершина: имеет ровно одно соединение
        else if (degree[i] - loop[i] == 1) {
            printf("Вершина %d - Концевая\n", i);
        }
        // Проверка на доминирующую вершину
        else {
            int connections = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && G[i][j] == 1) { // Считаем связи только с другими вершинами
                    connections++;
                }
            }
            if (connections == n - 1) { // Соединена со всеми вершинами, кроме себя
                printf("Вершина %d - Доминирующая\n", i);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        free(G[i]);
        free(IncMatrix[i]);
    }
    free(G);
    free(IncMatrix);
    free(degree);
    free(loop);

    return 0;
}
