#include <stdio.h>
#include <stdlib.h>

void read(int **ar, int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("Enter element at row %d column %d = ", i, j);
            scanf("%d", &ar[i][j]);
        }
    }
}

void display(int **ar, int r, int c) {
    printf("Array =\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d ", ar[i][j]);
        }
        printf("\n");
    }
}

void displaySparse(int **sparse, int rows) {
    printf("Sparse Matrix Representation (row, col, val):\n");
    for (int i = 0; i < rows; i++) {
        printf("%d %d %d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
    }
}

int **represent(int **ar, int r, int c, int nonZeroCount) {
    int **sparse = (int **)malloc(nonZeroCount * sizeof(int *));
    for (int i = 0; i < nonZeroCount; i++) {
        sparse[i] = (int *)malloc(3 * sizeof(int));
    }

    int row = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (ar[i][j] != 0) {
                sparse[row][0] = i;
                sparse[row][1] = j;
                sparse[row][2] = ar[i][j];
                row++;
            }
        }
    }

    displaySparse(sparse, nonZeroCount);
    return sparse;
}

int checkSparse(int **ar, int r, int c) {
    int zeroCount = 0;
    int total = r * c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (ar[i][j] == 0)
                zeroCount++;
        }
    }

    if (zeroCount > total / 2) {
        int nonZeroCount = total - zeroCount;
        represent(ar, r, c, nonZeroCount);
        return 1;
    }
    return 0;
}

int main() {
    int r, c;
    printf("Enter the number of rows = ");
    scanf("%d", &r);
    printf("Enter the number of columns = ");
    scanf("%d", &c);

    int **ar = (int **)malloc(r * sizeof(int *));
    for (int i = 0; i < r; i++) {
        ar[i] = (int *)malloc(c * sizeof(int));
    }

    read(ar, r, c);
    display(ar, r, c);

    if (!checkSparse(ar, r, c)) {
        printf("The matrix is not sparse.\n");
    }

    // Free allocated memory
    for (int i = 0; i < r; i++) {
        free(ar[i]);
    }
    free(ar);

    return 0;
}
