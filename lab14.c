#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Функция для считывания строк из файла и определения минимальной длины строк
void findShortestLines(const char* filename)
{
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Unable to open file");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    char** shortestLines = NULL;
    int minLength = MAX_LINE_LENGTH;
    int count = 0;

    // Первый проход: находим минимальную длину строк
    while (fgets(line, sizeof(line), file)) {
        int length = strlen(line);
        if (line[length - 1] == '\n') {
            line[length - 1] = '\0'; // Удаляем символ новой строки
            length--;
        }
        if (length < minLength) {
            minLength = length;
        }
    }

    // Возвращаемся в начало файла
    rewind(file);

    // Второй проход: собираем строки с минимальной длиной
    while (fgets(line, sizeof(line), file)) {
        int length = strlen(line);
        if (line[length - 1] == '\n') {
            line[length - 1] = '\0'; // Удаляем символ новой строки
            length--;
        }
        if (length == minLength) {
            shortestLines = realloc(shortestLines, sizeof(char*) * (count + 1));
            shortestLines[count] = strdup(line);
            count++;
        }
    }

    fclose(file);

    // Выводим строки с минимальной длиной
    printf("Shortest lines (length %d):\n", minLength);
    for (int i = 0; i < count; i++) {
        printf("%s\n", shortestLines[i]);
        free(shortestLines[i]);
    }
    free(shortestLines);
}

int main()
{
    const char* filename = "input.txt";
    findShortestLines(filename);
    return 0;
}
