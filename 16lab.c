#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int info;
    struct Node* next1;
    struct Node* next2;
    struct Node* next3;
} Node;

Node* head1 = NULL;
Node* head2 = NULL;
Node* ringHead = NULL;

Node* createNode(int info)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->info = info;
    newNode->next1 = NULL;
    newNode->next2 = NULL;
    newNode->next3 = NULL;
    return newNode;
}

void addToList(Node** head, int info)
{
    Node* newNode = createNode(info);
    newNode->next1 = *head;
    *head = newNode;
}

void createRing(Node* list1, Node* list2)
{
    Node* temp1 = list1;
    Node* temp2 = list2;
    Node* ringTail = NULL;

    while (temp1 != NULL) {
        Node* newNode = createNode(temp1->info);
        if (ringHead == NULL) {
            ringHead = newNode;
        } else {
            ringTail->next3 = newNode;
        }
        ringTail = newNode;
        temp1 = temp1->next1;
    }

    while (temp2 != NULL) {
        Node* newNode = createNode(temp2->info);
        ringTail->next3 = newNode;
        ringTail = newNode;
        temp2 = temp2->next1;
    }

    if (ringTail != NULL) {
        ringTail->next3 = ringHead;
    }
}

void searchInRing(int value)
{
    if (ringHead == NULL) {
        printf("Ring list is empty.\n");
        return;
    }

    Node* temp = ringHead;
    do {
        if (temp->info == value) {
            printf("Found value: %d\n", value);
            return;
        }
        temp = temp->next3;
    } while (temp != ringHead);

    printf("Value %d not found in ring list.\n", value);
}

int main()
{
    int choice, info;
    while (1) {
        printf("Select an operation:\n");
        printf("1. Add record to list 1\n");
        printf("2. Add record to list 2\n");
        printf("3. Create ring list\n");
        printf("4. Search in ring list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter info: ");
            scanf("%d", &info);
            addToList(&head1, info);
            break;
        case 2:
            printf("Enter info: ");
            scanf("%d", &info);
            addToList(&head2, info);
            break;
        case 3:
            createRing(head1, head2);
            printf("Ring list created.\n");
            break;
        case 4:
            printf("Enter value to search: ");
            scanf("%d", &info);
            searchInRing(info);
            break;
        case 5:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
