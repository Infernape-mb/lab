// 12 ascending priority queue
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
struct queue
{
    int *data;
    int front, rear, size, count;
};
typedef struct queue QUEUE;
void enqueue(QUEUE *q, int data)
{
    int i;
    if (q->size >= SIZE)
    {
        printf("Queue is full\n");
        return;
    }
    printf("%d is inserted\n");
    if (q->front == -1)
        (q->front)++;
    if (q->size < SIZE)
    {
        (q->size)++;
        q->data = (int *)realloc(q->data, q->size * sizeof(int));
    }
    (q->count)++;
    i = q->rear;
    while (i >= 0 && *(q->data + i) > data)
    {
        *(q->data + i + 1) = *(q->data + i);
        i--;
    }
    *(q->data + i + 1) = data;
    (q->rear)++;
}
void dequeue(QUEUE *q)
{
    if (q->front == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("%d deleted\n", *(q->data + q->front));
    (q->count)--;
    (q->front)++;
    if (q->count == 0)
    {
        free(q->data);
        q->size = 0;
        q->data = NULL;
        q->front = q->rear = -1;
    }
}
void display(QUEUE *q)
{
    int i;
    if (q->data == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    for (i = q->front; i <= q->rear; i++)
        printf("%d ", *(q->data + i));
    printf("\n");
}
void main()
{
    QUEUE q;
    int choice, ele;
    q.data = NULL;
    q.front = -1;
    q.rear = -1;
    q.size = 0;
    q.count = 0;

    while (1)
    {
        printf("\nEnter your choice\n");
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element: ");
            scanf("%d", &ele);
            enqueue(&q, ele);
            break;
        case 2:
            dequeue(&q);
            break;
        case 3:
            display(&q);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
            break;
        }
    }
}