#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateIncreasingArray(int arr[], int n)
{
    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }
}

void generateDecreasingArray(int arr[], int n)
{
    for (int i = 0; i < n; i++) {
        arr[i] = n - i;
    }
}

void generateRandomArray(int arr[], int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
}

void binaryInsertionSort(int arr[], int n, int* comparisons, int* swaps)
{
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int left = 0;
        int right = i - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            (*comparisons)++;
            if (arr[mid] > key) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        for (int j = i - 1; j >= left; j--) {
            arr[j + 1] = arr[j];
            (*swaps)++;
        }

        arr[left] = key;
    }
}

void shellSort(int arr[], int n, int* comparisons, int* swaps)
{
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            (*comparisons)++;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
                (*swaps)++;
            }
            arr[j] = temp;
        }
    }
}

void selectionSort(int arr[], int n, int* comparisons, int* swaps)
{
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            (*comparisons)++;
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            int temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
            (*swaps)++;
        }
    }
}

void printTableHeader()
{
    printf("| %10s | %15s | %15s |\n",
           "Тип массива",
           "Кол-во сравнений",
           "Кол-во пересылок");
    printf("|------------|-----------------|-----------------|\n");
}

void printTableRow(char* arrayType, int comparisons, int swaps)
{
    printf("| %10s | %15d | %15d |\n", arrayType, comparisons, swaps);
}

int main()
{
    int n = 100;
    int* arr = (int*)malloc(n * sizeof(int));
    int comparisons = 0;
    int swaps = 0;

    printf("Сортировка методом бинарного включения:\n");
    printTableHeader();

    generateIncreasingArray(arr, n);
    comparisons = 0;
    swaps = 0;
    binaryInsertionSort(arr, n, &comparisons, &swaps);
    printTableRow("Возрастающий", comparisons, swaps);

    generateDecreasingArray(arr, n);
    comparisons = 0;
    swaps = 0;
    binaryInsertionSort(arr, n, &comparisons, &swaps);
    printTableRow("Убывающий", comparisons, swaps);

    generateRandomArray(arr, n);
    comparisons = 0;
    swaps = 0;
    binaryInsertionSort(arr, n, &comparisons, &swaps);
    printTableRow("Случайный", comparisons, swaps);

    printf("\n");

    printf("Сортировка методом Шелла:\n");
    printTableHeader();

    generateIncreasingArray(arr, n);
    comparisons = 0;
    swaps = 0;
    shellSort(arr, n, &comparisons, &swaps);
    printTableRow("Возрастающий", comparisons, swaps);

    generateDecreasingArray(arr, n);
    comparisons = 0;
    swaps = 0;
    shellSort(arr, n, &comparisons, &swaps);
    printTableRow("Убывающий", comparisons, swaps);

    generateRandomArray(arr, n);
    comparisons = 0;
    swaps = 0;
    shellSort(arr, n, &comparisons, &swaps);
    printTableRow("Случайный", comparisons, swaps);

    printf("\n");

    printf("Сортировка методом простого выбора:\n");
    printTableHeader();

    generateIncreasingArray(arr, n);
    comparisons = 0;
    swaps = 0;
    selectionSort(arr, n, &comparisons, &swaps);
    printTableRow("Возрастающий", comparisons, swaps);

    generateDecreasingArray(arr, n);
    comparisons = 0;
    swaps = 0;
    selectionSort(arr, n, &comparisons, &swaps);
    printTableRow("Убывающий", comparisons, swaps);
    generateRandomArray(arr, n);
    comparisons = 0;
    swaps = 0;
    selectionSort(arr, n, &comparisons, &swaps);
    printTableRow("Случайный", comparisons, swaps);

    free(arr);

    return 0;
}
