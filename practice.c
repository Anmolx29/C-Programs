#include <stdio.h>
#include <stdlib.h>

// Define the size of the queue
#define MAX 50

// Create a queue using an array
int queue[MAX];
int rear = -1;
int front = -1;

// Function to insert an element into the queue
void insert(int item) {
  // Check if the queue is full
  if (rear == MAX - 1) {
    printf("Queue is full\n");
    return;
  }

  // Increment the rear pointer
  rear++;

  // Insert the item at the rear of the queue
  queue[rear] = item;
}

// Function to delete an element from the queue
int delete() {
  // Check if the queue is empty
  if (front == rear) {
    printf("Queue is empty\n");
    return 0;
  }

  // Increment the front pointer
  front++;

  // Delete the item at the front of the queue
  int item = queue[front];

  // Return the deleted item
  return item;
}

// Function to display the queue
void display() {
  // Check if the queue is empty
  if (front == rear) {
    printf("Queue is empty\n");
    return;
  }

  // Iterate over the queue and print each item
  for (int i = front + 1; i <= rear; i++) {
    printf("%d ", queue[i]);
  }

  printf("\n");
}

int main() {
 

  // Insert some elements into the queue
  insert(1);
  insert(2);
  insert(3);
  insert(4);
  insert(5);

  // Display the queue
  display();

  // Delete an element from the queue
  int item = delete();

  // Display the queue again
  display();

  return 0;
}