//4.Write a C program to dynamically allocate memory for a 2D matrix and perform matrix addition and subtraction.

#include <stdio.h>
#include <stdlib.h>
int main() {
    int r, c, i, j;
    int **mat1, **mat2, **sum, **sub;
    printf("Enter rows and columns: ");
    if (scanf("%d %d", &r, &c) != 2) return 1;
    mat1 = (int**)malloc(r * sizeof(int*));
    mat2 = (int**)malloc(r * sizeof(int*));
    sum = (int**)malloc(r * sizeof(int*));
    sub = (int**)malloc(r * sizeof(int*));
    for (i = 0; i < r; i++) {
        mat1[i] = (int*)malloc(c * sizeof(int));
        mat2[i] = (int*)malloc(c * sizeof(int));
        sum[i] = (int*)malloc(c * sizeof(int));
        sub[i] = (int*)malloc(c * sizeof(int));
    }
    printf("Enter elements of Matrix 1:\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) scanf("%d", &mat1[i][j]);
    }
    printf("Enter elements of Matrix 2:\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &mat2[i][j]);
            sum[i][j] = mat1[i][j] + mat2[i][j];
            sub[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
    printf("\nAddition Result:\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) printf("%d ", sum[i][j]);
        printf("\n");
    }
    printf("\nSubtraction Result:\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) printf("%d ", sub[i][j]);
        printf("\n");
    }
    for (i = 0; i < r; i++) {
        free(mat1[i]); free(mat2[i]); free(sum[i]); free(sub[i]);
    }
    free(mat1); free(mat2); free(sum); free(sub);
    return 0;
}