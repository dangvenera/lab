#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

typedef struct {
    char destination[MAX_NAME_LENGTH];
    int train_number;
    int departure_time[2]; // 0 - часы, 1 - минуты
} Train;

void addRecord(const char* filename)
{
    FILE* file = fopen(filename, "ab");
    if (!file) {
        perror("Unable to open file for writing");
        return;
    }

    Train train;
    printf("Enter destination: ");
    scanf("%s", train.destination);
    printf("Enter train number: ");
    scanf("%d", &train.train_number);
    printf("Enter departure time (hours minutes): ");
    scanf("%d %d", &train.departure_time[0], &train.departure_time[1]);

    fwrite(&train, sizeof(Train), 1, file);
    fclose(file);
    printf("Record added successfully.\n");
}

void searchTrains(const char* filename)
{
    FILE* file = fopen(filename, "rb");
    if (!file) {
        perror("Unable to open file for reading");
        return;
    }

    char destination[MAX_NAME_LENGTH];
    printf("Enter destination to search: ");
    scanf("%s", destination);

    Train train;
    int found = 0;
    while (fread(&train, sizeof(Train), 1, file)) {
        if (strcmp(train.destination, destination) == 0) {
            printf("Train number: %d, Departure time: %02d:%02d\n",
                   train.train_number,
                   train.departure_time[0],
                   train.departure_time[1]);
            found = 1;
        }
    }

    if (!found) {
        printf("No trains found for destination: %s\n", destination);
    }

    fclose(file);
}

int main()
{
    const char* filename = "Train.dat";
    int choice;

    while (1) {
        printf("Select an operation:\n");
        printf("1. Add a record to the file or start a new file\n");
        printf("2. Process the created file\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addRecord(filename);
            break;
        case 2:
            searchTrains(filename);
            break;
        case 3:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
