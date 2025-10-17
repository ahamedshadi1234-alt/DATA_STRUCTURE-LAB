#include <stdio.h>
#include <stdlib.h>
#define SIZE 5  // Size of the circular queue

int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int value) {
    if ((front == 0 && rear == SIZE - 1) || (rear == (front - 1 + SIZE) % SIZE)) {
        printf("Queue is Full (Overflow)\n");
        return;
    }
    if (front == -1) {  // First element
        front = rear = 0;
    } else if (rear == SIZE - 1 && front != 0) {
        rear = 0;  // Wrap around
    } else {
        rear++;
    }
    queue[rear] = value;
    printf("Inserted %d\n", value);
}

void dequeue() {
    if (front == -1) {
        printf("Queue is Empty (Underflow)\n");
        return;
    }

    int data = queue[front];
    printf("Deleted %d\n", data);

    if (front == rear) { 
        front = rear = -1;
    } else if (front == SIZE - 1) {
        front = 0;  // Wrap around
    } else {
        front++;
    }
}

void display() {
    if (front == -1) {
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue elements: ");
    if (rear >= front) {
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
    } else {
        for (int i = front; i < SIZE; i++)
            printf("%d ", queue[i]);
        for (int i = 0; i <= rear; i++)
            printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50); 
    display();

    dequeue();
    dequeue();
    display();

    enqueue(60);
    enqueue(70);  
    display();

    enqueue(80);  
    return (0);
    }
