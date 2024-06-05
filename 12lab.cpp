#include <iostream>

// Структура для комплексного числа
struct ComplexNumber {
    double x; // Действительная часть
    double y; // Мнимая часть
};

// Функция для сложения двух комплексных чисел
ComplexNumber add(ComplexNumber a, ComplexNumber b)
{
    ComplexNumber result;
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    return result;
}

// Функция для умножения двух комплексных чисел
ComplexNumber multiply(ComplexNumber a, ComplexNumber b)
{
    ComplexNumber result;
    result.x = a.x * b.x - a.y * b.y;
    result.y = a.x * b.y + a.y * b.x;
    return result;
}

int main()
{
    // Инициализация комплексных чисел a, b, c
    ComplexNumber a = {1.0, 2.0}; // a = 1 + 2i
    ComplexNumber b = {3.0, 4.0}; // b = 3 + 4i
    ComplexNumber c = {5.0, 6.0}; // c = 5 + 6i

    // Вычисление выражения Q = a + b^2 + (b + c)
    ComplexNumber bSquared
            = multiply(b, b); // Вычисляем квадрат комплексного числа b
    ComplexNumber sum1 = add(a, bSquared); // Вычисляем сумму a и b^2
    ComplexNumber sum2 = add(b, c); // Вычисляем сумму b и c
    ComplexNumber result = add(sum1, sum2); // Вычисляем итоговое выражение

    // Вывод результата
    std::cout << "Результат: " << result.x << " + " << result.y << "i"
              << std::endl;

    return 0;
}
