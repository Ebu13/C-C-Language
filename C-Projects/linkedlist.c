#include <stdio.h>
#include <stdlib.h>

// Structure representing a node in a linked list
struct Node {
    int data;           // Data
    struct Node* next;  // Pointer to the next node
};

// Linked list structure
struct LinkedList {
    struct Node* head;  // Pointer to the head of the list
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize a linked list
void initList(struct LinkedList* list) {
    list->head = NULL;
}

// Function to add a new node to the end of the list
void addNode(struct LinkedList* list, int value) {
    struct Node* newNode = createNode(value);
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        struct Node* temp = list->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to remove a node with a specific value from the list
void removeNode(struct LinkedList* list, int value) {
    if (list->head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (list->head->data == value) {
        struct Node* temp = list->head;
        list->head = list->head->next;
        free(temp);
        printf("%d has been removed from the list.\n", value);
        return;
    }

    struct Node* prev = NULL;
    struct Node* current = list->head;
    while (current != NULL && current->data != value) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("%d is not found in the list.\n", value);
        return;
    }

    prev->next = current->next;
    free(current);
    printf("%d has been removed from the list.\n", value);
}

// Function to display the linked list
void displayList(struct LinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = list->head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to find the minimum and maximum numbers and display them
void findMinMax(struct LinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty.\n");
        return;
    }

    int min = list->head->data;
    int max = list->head->data;
    struct Node* temp = list->head->next;
    while (temp != NULL) {
        if (temp->data < min)
            min = temp->data;
        if (temp->data > max)
            max = temp->data;
        temp = temp->next;
    }

    printf("Minimum number: %d\n", min);
    printf("Maximum number: %d\n", max);
}

// Function to calculate the average of the numbers in the linked list and display it
void calculateAverage(struct LinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty.\n");
        return;
    }

    int sum = 0;
    int count = 0;
    struct Node* temp = list->head;
    while (temp != NULL) {
        sum += temp->data;
        count++;
        temp = temp->next;
    }

    float average = (float)sum / count;
    printf("Average: %.2f\n", average);
}

// Function to sort the linked list in ascending order
void sortList(struct LinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* current = list->head;
    struct Node* index = NULL;
    int temp;

    while (current != NULL) {
        index = current->next;

        while (index != NULL) {
            if (current->data > index->data) {
                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
            index = index->next;
        }

        current = current->next;
    }

    printf("List has been sorted.\n");
}

int main() {
    struct LinkedList list;
    initList(&list);

    int choice, value;

    while (1) {
        printf("Select an operation:\n");
        printf("1. Add Number\n");
        printf("2. Remove Number\n");
        printf("3. Display List\n");
        printf("4. Find Minimum and Maximum Numbers\n");
        printf("5. Calculate Average\n");
        printf("6. Sort List\n");
        printf("0. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                printf("Exiting the program...\n");
                return 0;
            case 1:
                printf("Enter a number to add: ");
                scanf("%d", &value);
                addNode(&list, value);
                break;
            case 2:
                printf("Enter a number to remove: ");
                scanf("%d", &value);
                removeNode(&list, value);
                break;
            case 3:
                displayList(&list);
                break;
            case 4:
                findMinMax(&list);
                break;
            case 5:
                calculateAverage(&list);
                break;
            case 6:
                sortList(&list);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

        printf("\n");
    }

    return 0;
}

