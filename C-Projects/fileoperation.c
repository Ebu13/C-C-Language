#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100

// Function to get file name from user
void getFileName(char *fileName) {
    printf("Enter the name of the file: ");
    scanf("%s", fileName);
}

// Function to create a file
void createFile() {
    char fileName[MAX_FILENAME_LENGTH];
    getFileName(fileName);

    // Creating and opening the file
    FILE *file = fopen(fileName, "w");
    if (file == NULL) {
        printf("Failed to create the file.\n");
        return;
    }

    printf("File created: %s\n", fileName);
    fclose(file);
}

// Function to delete a file
void deleteFile() {
    char fileName[MAX_FILENAME_LENGTH];
    getFileName(fileName);

    // Deleting the file
    if (remove(fileName) == 0) {
        printf("File deleted: %s\n", fileName);
    } else {
        printf("Failed to delete the file.\n");
    }
}

// Function to read a file
void readFile() {
    char fileName[MAX_FILENAME_LENGTH];
    getFileName(fileName);

    // Opening the file and reading it line by line
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        printf("File not found.\n");
        return;
    }

    char line[100];
    printf("File content:\n");
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }

    fclose(file);
}

// Function to write to a file
void writeToFile() {
    char fileName[MAX_FILENAME_LENGTH];
    getFileName(fileName);

    // Opening the file and writing data to it
    FILE *file = fopen(fileName, "a+");
    if (file == NULL) {
        printf("File not found.\n");
        return;
    }

    char data[100];
    printf("Enter the data to write to the file: ");
    scanf(" %[^\n]s", data);

    fprintf(file, "%s\n", data);
    printf("Data written to the file.\n");

    fclose(file);
}

// Function to completely erase the content of a file
void eraseFileContent() {
    char fileName[MAX_FILENAME_LENGTH];
    getFileName(fileName);

    // Opening the file and clearing its content
    FILE *file = fopen(fileName, "w");
    if (file == NULL) {
        printf("File not found.\n");
        return;
    }

    printf("The content of the file has been completely erased.\n");

    fclose(file);
}

int main() {
    int choice;
    printf("Enter the file name in the format file.txt.\n");
    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Create File\n");
        printf("2. Delete File\n");
        printf("3. Read File\n");
        printf("4. Write to File\n");
        printf("5. Erase File Content\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createFile();
                break;
            case 2:
                deleteFile();
                break;
            case 3:
                readFile();
                break;
            case 4:
                writeToFile();
                break;
            case 5:
                eraseFileContent();
                break;
            case 6:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
