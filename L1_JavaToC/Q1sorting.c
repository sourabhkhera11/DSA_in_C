#include <stdio.h>
#include <stdlib.h>

void read(int ar[], int num) {
    for (int i = 0; i < num; i++) {
        printf("Enter the element at %d index = ", i);
        scanf("%d", &ar[i]);
    }
}

void swap(int ar[], int i1, int i2) {
    int temp = ar[i1];
    ar[i1] = ar[i2];
    ar[i2] = temp;
}

void display(int ar[], int len) {
    printf("\nArray = ");
    for (int i = 0; i < len; i++) {
        printf("%d ", ar[i]);
    }
    printf("\n");
}

void selectionSort(int ar[], int len) {
    for (int i = 0; i < len - 1; i++) {
        int min = i;
        for (int j = i + 1; j < len; j++) {
            if (ar[j] < ar[min]) {
                min = j;
            }
        }
        swap(ar, i, min);
    }
}

void bubbleSort(int ar[], int len) {
    for (int i = 0; i < len; i++) {
        int flag = 0;
        for (int j = 0; j < len - 1 - i; j++) {
            if (ar[j] > ar[j + 1]) {
                swap(ar, j, j + 1);
                flag = 1;
            }
        }
        if (flag == 0) return;
    }
}

void insertionSort(int ar[], int len) {
    for (int i = 1; i < len; i++) {
        int j = i - 1;
        int cur = ar[i];
        while (j >= 0 && cur < ar[j]) {
            ar[j + 1] = ar[j];
            j--;
        }
        ar[j + 1] = cur;
    }
}

void merge(int ar[], int l, int mid, int mid1, int h) {
    int n1 = mid - l + 1;
    int n2 = h - mid1 + 1;
    int *ar1 = (int *)malloc(n1 * sizeof(int));
    int *ar2 = (int *)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++) ar1[i] = ar[l + i];
    for (int i = 0; i < n2; i++) ar2[i] = ar[mid1 + i];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (ar1[i] < ar2[j]) ar[k++] = ar1[i++];
        else ar[k++] = ar2[j++];
    }

    while (i < n1) ar[k++] = ar1[i++];
    while (j < n2) ar[k++] = ar2[j++];

    free(ar1);
    free(ar2);
}

void mergeSort(int ar[], int l, int h) {
    if (l < h) {
        int mid = l + (h - l) / 2;
        mergeSort(ar, l, mid);
        mergeSort(ar, mid + 1, h);
        merge(ar, l, mid, mid + 1, h);
    }
}

int partition(int ar[], int l, int h) {
    int pivot = ar[l];
    int i = l, j = h;

    while (i < j) {
        while (ar[i] <= pivot && i < h) i++;
        while (ar[j] > pivot && j > 0) j--;
        if (i < j) swap(ar, i, j);
    }

    swap(ar, j, l);
    return j;
}

void quickSort(int ar[], int l, int h) {
    if (l < h) {
        int p = partition(ar, l, h);
        quickSort(ar, l, p - 1);
        quickSort(ar, p + 1, h);
    }
}

void shellSort(int ar[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = ar[i], j;
            for (j = i; j >= gap && ar[j - gap] > temp; j -= gap) {
                ar[j] = ar[j - gap];
            }
            ar[j] = temp;
        }
    }
}

int getMax(int ar[], int len) {
    int max = ar[0];
    for (int i = 1; i < len; i++) {
        if (ar[i] > max) max = ar[i];
    }
    return max;
}

void countingSort(int ar[], int len, int exp) {
    int output[len];
    int count[10] = {0};

    for (int i = 0; i < len; i++) {
        count[(ar[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = len - 1; i >= 0; i--) {
        int digit = (ar[i] / exp) % 10;
        output[count[digit] - 1] = ar[i];
        count[digit]--;
    }

    for (int i = 0; i < len; i++) {
        ar[i] = output[i];
    }
}

void radixSort(int ar[], int len) {
    int m = getMax(ar, len);
    for (int exp = 1; m / exp > 0; exp *= 10) {
        countingSort(ar, len, exp);
    }
}

void frequency(int ar[], int len) {
    int visited[len];
    for (int i = 0; i < len; i++) visited[i] = 0;

    for (int i = 0; i < len; i++) {
        if (visited[i]) continue;
        int count = 1;
        for (int j = i + 1; j < len; j++) {
            if (ar[i] == ar[j]) {
                visited[j] = 1;
                count++;
            }
        }
        printf("Freq of %d = %d\n", ar[i], count);
    }
}

int main() {
    int ar[] = {91, 2, 43, 27, 18, 18, 27, 91, 91, 91};
    int len = sizeof(ar) / sizeof(ar[0]);

    // Example usage:
    display(ar, len);
    radixSort(ar, len);
    display(ar, len);
    frequency(ar, len);

    return 0;
}
