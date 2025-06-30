#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int x) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->data = x;
  temp->next = NULL;
  if (rear == NULL) {
    front = rear = temp;
  } else {
    rear->next = temp;
    rear = temp;
  }
}

void dequeue() {
  if (front == NULL) {
    printf("Queue is empty\n");
    return;
  } else {
    struct node *temp = front;
    front = front->next;
    if (front == NULL) {
      rear = NULL;
    }
    free(temp);
  }
}

void display() {
  struct node *temp = front;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

int main() {
  enqueue(1);
  enqueue(2);
  enqueue(3);
  enqueue(4);
  display();
  dequeue();
  display();
  return 0;
}