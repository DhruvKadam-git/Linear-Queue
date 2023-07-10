#include <stdio.h>
#define MAX 50

int queue[MAX];
int front = -1;
int rear = -1;

void enqueueFront(int value) {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Queue is full. Cannot enqueue front.\n");
    } else if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[front] = value;
    } else if (front == 0) {
        front = MAX - 1;
        queue[front] = value;
    } else {
        front--;
        queue[front] = value;
    }
}

void enqueueRear(int value) {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Queue is full. Cannot enqueue rear.\n");
    } else if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = value;
    } else if (rear == MAX - 1) {
        rear = 0;
        queue[rear] = value;
    } else {
        rear++;
        queue[rear] = value;
    }
}

void dequeueFront() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty. Cannot dequeue front.\n");
    } else if (front == rear) {
        printf("Dequeued element: %d\n", queue[front]);
        front = rear = -1;
    } else if (front == MAX - 1) {
        printf("Dequeued element: %d\n", queue[front]);
        front = 0;
    } else {
        printf("Dequeued element: %d\n", queue[front]);
        front++;
    }
}

void dequeueRear() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty. Cannot dequeue rear.\n");
    } else if (front == rear) {
        printf("Dequeued element: %d\n", queue[rear]);
        front = rear = -1;
    } else if (rear == 0) {
        printf("Dequeued element: %d\n", queue[rear]);
        rear = MAX - 1;
    } else {
        printf("Dequeued element: %d\n", queue[rear]);
        rear--;
    }
}

void display() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty. Nothing to display.\n");
    } else {
        int i = front;
        printf("Queue elements: ");
        while (i != rear) {
            printf("%d ", queue[i]);
            i = (i + 1) % MAX;
        }
        printf("%d\n", queue[i]);
    }
}

int main() {
    enqueueFront(10);
    enqueueRear(20);
    enqueueFront(5);
    enqueueRear(15);
    
    display();  // Output: Queue elements: 5 10 20 15
    
    dequeueFront();  // Output: Dequeued element: 5
    dequeueRear();   // Output: Dequeued element: 15
    
    display();  // Output: Queue elements: 10 20
    
    return 0;
}
