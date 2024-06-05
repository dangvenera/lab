// 10.	Определить количество чисел, значения которых кратно 3.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Функция для подсчета чисел, значения которых кратно 3
int countMultiplesOfThree(int n)
{
    if (n == 0) {
        return 0;
    } else {
        int num;
        printf("Введите число: ");
        scanf("%d", &num);
        if (num % 3 == 0) {
            return 1
                    + countMultiplesOfThree(
                            n - 1); // Рекурсивный вызов функции, если число
                                    // кратно 3
        } else {
            return countMultiplesOfThree(
                    n - 1); // Рекурсивный вызов функции, если число не кратно 3
        }
    }
}

int main()
{
    int n, choice;
    srand(time(0)); // Инициализация генератора случайных чисел

    printf("Введите количество чисел: ");
    scanf("%d", &n);

    printf("Выберите способ ввода (1 - через клавиатуру, 2 - рандомно): ");
    scanf("%d", &choice);

    int count = 0;
    if (choice == 1) {
        count = countMultiplesOfThree(
                n); // Вызов функции для ввода чисел через клавиатуру
    } else if (choice == 2) {
        for (int i = 0; i < n; i++) {
            int num = rand() % 100
                    + 1; // Генерация случайного числа от 1 до 100
            printf("%d ", num);
            if (num % 3 == 0) {
                count++; // Увеличение счетчика, если число кратно 3
            }
        }
    } else {
        printf("Неверный выбор способа ввода.\n");
        return 1;
    }

    printf("\nКоличество чисел, значения которых кратно 3: %d\n", count);

    return 0;
}
