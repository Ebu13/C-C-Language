#include <iostream>

// Structure representing a node in a linked list
struct Node {
    int data;     // Data
    Node* next;   // Pointer to the next node
};

// Linked list class
class LinkedList {
private:
    Node* head;   // Pointer to the head of the list

public:
    // Constructor, initializes the head to NULL
    LinkedList() {
        head = NULL;
    }

    // Add a new node to the end of the list
    void addNode(int value) {
        Node* newNode = new Node;   // Create a new node
        newNode->data = value;      // Assign the value to the new node
        newNode->next = NULL;    // Set the next pointer of the new node to NULL

        if (head == NULL) {
            // If the list is empty, the new node becomes the head
            head = newNode;
        } else {
            // If the list is not empty, traverse to the end and add the new node
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Remove a node with a specific value from the list
    void removeNode(int value) {
        if (head == NULL) {
            std::cout << "List is empty." << std::endl;
            return;
        }

        if (head->data == value) {
            // If the head node has the specified value,
            // update the head and delete the old head
            Node* temp = head;
            head = head->next;
            delete temp;
            std::cout << value << " has been removed from the list." << std::endl;
            return;
        }

        // If it's not the head node, find and remove the node
        Node* prev = NULL;
        Node* current = head;
        while (current != NULL && current->data != value) {
            prev = current;
            current = current->next;
        }

        if (current == NULL) {
            // No node with the specified value found
            std::cout << value << " is not found in the list." << std::endl;
            return;
        }

        prev->next = current->next;
        delete current;
        std::cout << value << " has been removed from the list." << std::endl;
    }

    // Display the linked list
    void displayList() {
        if (head == NULL) {
            std::cout << "List is empty." << std::endl;
            return;
        }

        Node* temp = head;
        std::cout << "List: ";
        while (temp != NULL) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    // Find the minimum and maximum numbers and display them
    void findMinMax() {
        if (head == NULL) {
            std::cout << "List is empty." << std::endl;
            return;
        }

        int min = head->data;
        int max = head->data;
        Node* temp = head->next;
        while (temp != NULL) {
            if (temp->data < min)
                min = temp->data;
            if (temp->data > max)
                max = temp->data;
            temp = temp->next;
        }

        std::cout << "Minimum number: " << min << std::endl;
        std::cout << "Maximum number: " << max << std::endl;
    }

    // Calculate the average of the numbers in the linked list and display it
    void calculateAverage() {
        if (head == NULL) {
            std::cout << "List is empty." << std::endl;
            return;
        }

        int sum = 0;
        int count = 0;
        Node* temp = head;
        while (temp != NULL) {
            sum += temp->data;
            count++;
            temp = temp->next;
        }

        float average = static_cast<float>(sum) / count;
        std::cout << "Average: " << average << std::endl;
    }

    // Sort the linked list in ascending order
    void sortList() {
        if (head == NULL) {
            std::cout << "List is empty." << std::endl;
            return;
        }

        Node* current = head;
        Node* index = NULL;
        int temp;

        while (current != NULL) {
            index = current->next;

            while (index != NULL) {
                if (current->data > index->data) {
                    // Swap the nodes
                    temp = current->data;
                    current->data = index->data;
                    index->data = temp;
                }
                index = index->next;
            }

            current = current->next;
        }

        std::cout << "List has been sorted." << std::endl;
    }
};

int main() {
    LinkedList list;

    int choice, value;

    while (true) {
        // Get user choice and perform the operation
        std::cout << "Select an operation:" << std::endl;
        std::cout << "1. Add Number" << std::endl;
        std::cout << "2. Remove Number" << std::endl;
        std::cout << "3. Display List" << std::endl;
        std::cout << "4. Find Minimum and Maximum Numbers" << std::endl;
        std::cout << "5. Calculate Average" << std::endl;
        std::cout << "6. Sort List" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "Your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 0:
                std::cout << "Exiting the program..." << std::endl;
                return 0;
            case 1:
                std::cout << "Enter a number to add: ";
                std::cin >> value;
                list.addNode(value);
                break;
            case 2:
                std::cout << "Enter a number to remove: ";
                std::cin >> value;
                list.removeNode(value);
                break;
            case 3:
                list.displayList();
                break;
            case 4:
                list.findMinMax();
                break;
            case 5:
                list.calculateAverage();
                break;
            case 6:
                list.sortList();
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }

        std::cout << std::endl;
    }

    return 0;
}

