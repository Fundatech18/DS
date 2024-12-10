#include <stdio.h>
#include <stdlib.h>

// Node structure for linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node into a sorted linked list
void sortedInsert(Node** head, int data) {
    Node* newNode = createNode(data);
    Node* current;

    if (*head == NULL || (*head)->data >= data) {
        newNode->next = *head;
        *head = newNode;
    } else {
        current = *head;
        while (current->next != NULL && current->next->data < data) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Function to free the linked list
void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Address Calculation Sort Function
void addressCalculationSort(int arr[], int n) {
    // Create an array of buckets (linked lists)
    Node* buckets[10] = {NULL};

    // Place elements into buckets based on hash function
    for (int i = 0; i < n; i++) {
        int bucketIndex = arr[i] % 10; // Hash function
        sortedInsert(&buckets[bucketIndex], arr[i]);
    }

    // Collect sorted elements from buckets
    int index = 0;
    for (int i = 0; i < 10; i++) {
        Node* current = buckets[i];
        while (current != NULL) {
            arr[index++] = current->data;
            current = current->next;
        }
        // Free memory of bucket
        freeList(buckets[i]);
    }
}

// Main function to test the program
int main() {
    int arr[] = {29, 25, 3, 49, 9, 37, 21, 43};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    addressCalculationSort(arr, n);

    printf("\nSorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
