#include <stdio.h>
#include <malloc.h>
#include <windows.h>
#pragma warning(disable : 4996)

typedef struct graph { 
    int point1; 
    int point2; 
} graph;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    FILE *file = fopen("table.dot", "w"); 
    int punkt, n, m, mn[10][10], stat = 0;
    graph *table = (graph*)malloc(sizeof(graph));
    fprintf(file, "graph G {");
    fprintf(file, "\n");
    printf("Введите число вершин графа > ");
    scanf("%d%*c", &n);
    for (int wide = 1; wide < (n + 1); ++wide) {
        for (int len = 1; len < (n + 1); ++len) {
            mn[wide][len] = 0;
        }
    }
    for (int i = 1; i < (n + 1); i++) {
        fprintf(file, "%d;", i);
        fprintf(file, "\n");
    }
    printf("Введите количество ребер > ");
    scanf("%d%*c", &m);
    table = (graph*)realloc(table, m * sizeof(graph));
    printf("Введите ребра в формате (Вершина 1 - Вершина 2) > ");
    for (int i = 0; i < m; i++) {
        scanf("%d - %d", &table[i].point1, &table[i].point2);
        mn[table[i].point1][table[i].point2]++;
        mn[table[i].point2][table[i].point1]++;
        fprintf(file, "%d -- %d;", table[i].point1, table[i].point2);
        fprintf(file, "\n");
    }
    for (int wide = 1; wide < (n + 1); ++wide) {
        for (int len = 1; len < (n + 1); ++len) {
            printf("%d ", mn[wide][len]);
            if (mn[wide][len] > 1) {
                stat = 1;
            }
        }
        printf("\n");
    }
    if ((m > (((n - 1) * (n - 2)) / 2)) && (stat == 0)) {
        printf("Граф является связным");
    }
    else if (stat == 1) {
        printf("Граф не является простым (теорема для него не работает)");
    }
    else {
        printf("Граф не является связным");
    }
    fprintf(file, "}");
    fclose(file); 
    free(table);
    return 0;
}