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
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d ", ar[i][j]);
        }
        printf("\n");
    }
}

// Function to transpose matrix
void transpose(int **ar, int r, int c) {
    printf("-------After Transpose!--------\n");
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            printf("%d ", ar[j][i]);
        }
        printf("\n");
    }
}

// Row-wise sum
void rowAdd(int **ar, int r, int c) {
    for (int i = 0; i < r; i++) {
        int sum = 0;
        for (int j = 0; j < c; j++) {
            sum += ar[i][j];
        }
        printf("Sum of %d row = %d\n", i + 1, sum);
    }
}

// Column-wise sum
void colAdd(int **ar, int r, int c) {
    for (int i = 0; i < c; i++) {
        int sum = 0;
        for (int j = 0; j < r; j++) {
            sum += ar[j][i];
        }
        printf("Sum of %d column = %d\n", i + 1, sum);
    }
}

// Off-diagonal sum
void sumOffDia(int **ar, int r, int c) {
    if (r != c) {
        printf("Not a square matrix!\n");
        return;
    }
    int sum = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (i != j) {
                sum += ar[i][j];
            }
        }
    }
    printf("Sum of off-diagonal elements = %d\n", sum);
}

// Display upper triangular matrix
void disUT(int **ar, int r, int c) {
    if (r != c) {
        printf("Not a square matrix!\n");
        return;
    }
    printf("--------Upper Triangular Matrix!--------\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (i <= j) {
                printf("%d ", ar[i][j]);
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

// Display lower triangular matrix
void disLT(int **ar, int r, int c) {
    if (r != c) {
        printf("Not a square matrix!\n");
        return;
    }
    printf("--------Lower Triangular Matrix!--------\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (i >= j) {
                printf("%d ", ar[i][j]);
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

// Display diagonal matrix
void disDia(int **ar, int r, int c) {
    if (r != c) {
        printf("Not a square matrix!\n");
        return;
    }
    printf("--------Diagonal Matrix!--------\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (i == j) {
                printf("%d ", ar[i][j]);
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main() {
    int r, c;

    printf("Enter the number of rows = ");
    scanf("%d", &r);
    printf("Enter the number of columns = ");
    scanf("%d", &c);

    // Dynamic allocation of 2D array
    int **ar = (int **)malloc(r * sizeof(int *));
    for (int i = 0; i < r; i++)
        ar[i] = (int *)malloc(c * sizeof(int));

    read(ar, r, c);

    printf("-------Matrix!-------\n");
    display(ar, r, c);

    disUT(ar, r, c);
    disLT(ar, r, c);
    disDia(ar, r, c);
    transpose(ar, r, c);
    rowAdd(ar, r, c);
    colAdd(ar, r, c);
    sumOffDia(ar, r, c);

    // Free memory
    for (int i = 0; i < r; i++) {
        free(ar[i]);
    }
    free(ar);

    return 0;
}
