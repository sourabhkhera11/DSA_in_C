#include <stdio.h>
#include <stdlib.h>

// Function to read matrix
void read(int **ar, int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("Enter element at row %d column %d = ", i, j);
            scanf("%d", &ar[i][j]);
        }
    }
}

// Function to display matrix
void display(int **ar, int r, int c) {
    printf("\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d ", ar[i][j]);
        }
        printf("\n");
    }
}

// Function to add matrices
void add(int **ar1, int **ar2, int r1, int c1, int r2, int c2) {
    if (r1 == r2 && c1 == c2) {
        int **sum = (int **)malloc(r1 * sizeof(int *));
        for (int i = 0; i < r1; i++)
            sum[i] = (int *)malloc(c1 * sizeof(int));

        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c1; j++) {
                sum[i][j] = ar1[i][j] + ar2[i][j];
            }
        }
        printf("Sum =\n");
        display(sum, r1, c1);

        for (int i = 0; i < r1; i++) free(sum[i]);
        free(sum);
    } else {
        printf("Sum is not possible!\n");
    }
}

// Function to subtract matrices
void sub(int **ar1, int **ar2, int r1, int c1, int r2, int c2) {
    if (r1 == r2 && c1 == c2) {
        int **diff = (int **)malloc(r1 * sizeof(int *));
        for (int i = 0; i < r1; i++)
            diff[i] = (int *)malloc(c1 * sizeof(int));

        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c1; j++) {
                diff[i][j] = abs(ar1[i][j] - ar2[i][j]);
            }
        }
        printf("Subtraction =\n");
        display(diff, r1, c1);

        for (int i = 0; i < r1; i++) free(diff[i]);
        free(diff);
    } else {
        printf("Subtraction is not possible!\n");
    }
}

// Function to multiply matrices
void multi(int **ar1, int **ar2, int r1, int c1, int r2, int c2) {
    if (c1 == r2) {
        int **mul = (int **)malloc(r1 * sizeof(int *));
        for (int i = 0; i < r1; i++)
            mul[i] = (int *)calloc(c2, sizeof(int));

        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c2; j++) {
                for (int k = 0; k < c1; k++) {
                    mul[i][j] += ar1[i][k] * ar2[k][j];
                }
            }
        }
        printf("After multiplication =\n");
        display(mul, r1, c2);

        for (int i = 0; i < r1; i++) free(mul[i]);
        free(mul);
    } else {
        printf("Matrix cannot be multiplied!\n");
    }
}

int main() {
    int r1, c1, r2, c2;

    printf("For matrix 1:\n");
    printf("Enter number of rows: ");
    scanf("%d", &r1);
    printf("Enter number of columns: ");
    scanf("%d", &c1);

    int **matrix1 = (int **)malloc(r1 * sizeof(int *));
    for (int i = 0; i < r1; i++)
        matrix1[i] = (int *)malloc(c1 * sizeof(int));

    read(matrix1, r1, c1);

    printf("For matrix 2:\n");
    printf("Enter number of rows: ");
    scanf("%d", &r2);
    printf("Enter number of columns: ");
    scanf("%d", &c2);

    int **matrix2 = (int **)malloc(r2 * sizeof(int *));
    for (int i = 0; i < r2; i++)
        matrix2[i] = (int *)malloc(c2 * sizeof(int));

    read(matrix2, r2, c2);

    printf("Matrix 1 =\n");
    display(matrix1, r1, c1);

    printf("Matrix 2 =\n");
    display(matrix2, r2, c2);

    // Perform operations
    add(matrix1, matrix2, r1, c1, r2, c2);
    sub(matrix1, matrix2, r1, c1, r2, c2);
    multi(matrix1, matrix2, r1, c1, r2, c2);

    // Free memory
    for (int i = 0; i < r1; i++) free(matrix1[i]);
    free(matrix1);
    for (int i = 0; i < r2; i++) free(matrix2[i]);
    free(matrix2);

    return 0;
}
