#include <stdio.h>
#include <conio.h>
#include<stdlib.h>

#define MAX 5
void EnQueue(int data);
void DeQueue();
void QueueRear();
void QueueFront();
void display();

int front = 0, rear = -1, queue[MAX];

int main() {
    int data, choice;

    do {
        printf("\n***Queue Operations***");
        printf("\n 1.EnQueue\n 2.DeQueue\n 3.QueueFront\n 4.QueueRear\n 5.EXIT");
        printf("\n Enter the choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data you want to add into the queue: ");
                scanf("%d", &data);
                EnQueue(data);
                break;

            case 2:
                DeQueue();
                break;

            case 3:
                QueueFront();
                break;

            case 4:
                QueueRear();
                break;

            case 5:
                exit(0);
                break;

            default:
                printf("Enter a valid choice\n");
        }
    } while (choice != 5);

    return 0;
}

void EnQueue(int data) {
    if (rear == MAX - 1) {
        printf("\nQueue is Full");
    } else {
        rear++;
        queue[rear] = data;
        printf("\nAfter Enqueue operation Queue is: ");
        display();
    }
    printf("\nFRONT = %d\tREAR = %d", front, rear);
}

void DeQueue() {
    if (front > rear) {
        printf("Queue is empty");
    } else {
        printf("\nElement %d has been DeQueued", queue[front]);

        if (front == rear) {
            front = 0;
            rear = -1;
        } else {
            front++;
            display();
            printf("\nFRONT = %d\tREAR = %d", front, rear);
        }
    }
}

void QueueFront() {
    if (front > rear) {
        printf("\nQueue is Empty");
    } else {
        printf("\nData at the front of the queue: %d", queue[front]);
    }
}

void QueueRear() {
    if (front > rear) {
        printf("\nQueue is empty");
    } else {
        printf("\nData at the rear end of the queue is: %d", queue[rear]);
    }
}

void display() {
    int i;
    if (front > rear) {
        printf("\nQueue is empty");
    } else {
        printf("FRONT: ");
        for (i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf(": REAR");
    }
}
