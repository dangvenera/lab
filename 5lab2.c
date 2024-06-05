// доработанная программа 1
#include <stdbool.h>

bool allNonNegative(int A[], int n)
{
    for (int i = 0; i < n; i++) {
        if (A[i] < 0) {
            return false;
        }
    }
    return true;
}
// доработанная программа 2
void removeMax(int A[], int* n)
{
    int maxIndex = 0;
    for (int i = 1; i < *n; i++) {
        if (A[i] > A[maxIndex]) {
            maxIndex = i;
        }
    }
    for (int j = maxIndex; j < *n - 1; j++) {
        A[j] = A[j + 1];
    }
    (*n)--;
}
// доработанная программа 3
#include <stdbool.h>

void fillWithPrimes(int A[], int v, int m)
{
    int i = 0;
    int a = 2;
    while (a < v && i < m - 1) {
        bool isPrime = true;
        for (int j = 0; j < i; j++) {
            if (a % A[j] == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            A[i++] = a;
        }
        a++;
    }
    A[i] = 0;
}
// доработанная программа 4
int sumUntilNegative(int A[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] < 0) {
            break;
        }
        sum += A[i];
    }
    return sum;
}
// доработанная программа 5
int findMax(int A[], int n)
{
    int max = A[0];
    for (int i = 1; i < n; i++) {
        if (A[i] > max) {
            max = A[i];
        }
    }
    return max;
}
// доработанная программа 6
int sumArray(int A[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += A[i];
    }
    return sum;
}
