#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateArray(int arr[], int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
}

void fillArrayFromKeyboard(int arr[], int n)
{
    printf("Введите элементы массива:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

void fillArrayFromFile(int arr[], int n, char* filename)
{
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Ошибка открытия файла.\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        if (fscanf(file, "%d", &arr[i]) != 1) {
            printf("Ошибка чтения файла.\n");
            return;
        }
    }

    fclose(file);
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

void printArray(int arr[], int n)
{
    printf("Массив:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int n = 0;
    int* arr = NULL;
    int comparisons = 0;
    int swaps = 0;

    int choice;
    do {
        printf("\nМеню:\n");
        printf("1. Заполнить массив с клавиатуры\n");
        printf("2. Заполнить массив из файла\n");
        printf("3. Заполнить массив случайными числами\n");
        printf("4. Сортировка методом бинарного включения\n");
        printf("5. Сортировка методом Шелла\n");
        printf("6. Сортировка методом простого выбора\n");
        printf("7. Вывести массив на экран\n");
        printf("8. Вывести количество сравнений и пересылок\n");
        printf("9. Выход\n");

        printf("Выберите опцию: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Введите размер массива: ");
            scanf("%d", &n);
            arr = (int*)malloc(n * sizeof(int));
            fillArrayFromKeyboard(arr, n);
            printArray(arr, n);
            break;
        case 2:
            printf("Введите размер массива: ");
            scanf("%d", &n);
            arr = (int*)malloc(n * sizeof(int));
            fillArrayFromFile(arr, n, "input.txt");
            printArray(arr, n);
            break;
        case 3:
            printf("Введите размер массива: ");
            scanf("%d", &n);
            arr = (int*)malloc(n * sizeof(int));
            generateArray(arr, n);
            printArray(arr, n);
            break;
        case 4:
            n = 100;
            arr = (int*)malloc(n * sizeof(int));
            generateArray(arr, n);
            comparisons = 0;
            swaps = 0;
            binaryInsertionSort(arr, n, &comparisons, &swaps);
            printf("Массив отсортирован.\n");
            printf("Количество сравнений: %d\n", comparisons);
            printf("Количество пересылок: %d\n", swaps);
            break;
        case 5:
            n = 100;
            arr = (int*)malloc(n * sizeof(int));
            generateArray(arr, n);
            comparisons = 0;
            swaps = 0;
            shellSort(arr, n, &comparisons, &swaps);
            printf("Массив отсортирован.\n");
            printf("Количество сравнений: %d\n", comparisons);
            printf("Количество пересылок: %d\n", swaps);
            break;
        case 6:
            n = 100;
            arr = (int*)malloc(n * sizeof(int));
            generateArray(arr, n);
            comparisons = 0;
            swaps = 0;
            selectionSort(arr, n, &comparisons, &swaps);
            printf("Массив отсортирован.\n");
            printf("Количество сравнений: %d\n", comparisons);
            printf("Количество пересылок: %d\n", swaps);
            break;
        case 7:
            printArray(arr, n);
            break;
        case 8:
            printf("Эта опция доступна только после сортировки.\n");
            break;
        case 9:
            printf("Выход...\n");
            break;
        default:
            printf("Некорректный выбор. Пожалуйста, выберите опцию из меню.\n");
            break;
        }
    } while (choice != 9);

    free(arr);

    return 0;
}
