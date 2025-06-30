#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the doubly linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Define the deque structure
struct Deque {
    struct Node* front;
    struct Node* rear;
};

// Function to initialize an empty deque
void initializeDeque(struct Deque* deque) {
    deque->front = NULL;
    deque->rear = NULL;
}

// Function to check if the deque is empty
int isEmpty(const struct Deque* deque) {
    return deque->front == NULL;
}

// Function to insert an element at the front of the deque
void insertFront(struct Deque* deque, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (isEmpty(deque)) {
        deque->front = newNode;
        deque->rear = newNode;
    } else {
        newNode->next = deque->front;
        deque->front->prev = newNode;
        deque->front = newNode;
    }

    printf("%d inserted at the front\n", value);
}

// Function to insert an element at the rear of the deque
void insertRear(struct Deque* deque, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (isEmpty(deque)) {
        deque->front = newNode;
        deque->rear = newNode;
    } else {
        newNode->prev = deque->rear;
        deque->rear->next = newNode;
        deque->rear = newNode;
    }

    printf("%d inserted at the rear\n", value);
}

// Function to delete an element from the front of the deque
void deleteFront(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty. Cannot delete from the front\n");
        return;
    }

    struct Node* temp = deque->front;

    if (deque->front == deque->rear) {
        // Only one element in the deque
        deque->front = NULL;
        deque->rear = NULL;
    } else {
        deque->front = deque->front->next;
        deque->front->prev = NULL;
    }

    int deletedValue = temp->data;
    free(temp);

    printf("%d deleted from the front\n", deletedValue);
}

// Function to delete an element from the rear of the deque
void deleteRear(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty. Cannot delete from the rear\n");
        return;
    }

    struct Node* temp = deque->rear;

    if (deque->front == deque->rear) {
        // Only one element in the deque
        deque->front = NULL;
        deque->rear = NULL;
    } else {
        deque->rear = deque->rear->prev;
        deque->rear->next = NULL;
    }

    int deletedValue = temp->data;
    free(temp);

    printf("%d deleted from the rear\n", deletedValue);
}

// Function to display the elements of the deque
void displayDeque(const struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty\n");
        return;
    }

    printf("Deque elements: ");
    struct Node* current = deque->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to free the memory allocated for the deque
void freeDeque(struct Deque* deque) {
    struct Node* current = deque->front;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }

    initializeDeque(deque);
}

int main() {
    struct Deque myDeque;
    initializeDeque(&myDeque);

    insertFront(&myDeque, 10);
    insertRear(&myDeque, 20);
    insertFront(&myDeque, 5);

    displayDeque(&myDeque);

    deleteFront(&myDeque);
    deleteRear(&myDeque);

    displayDeque(&myDeque);

    freeDeque(&myDeque);

    return 0;
}
