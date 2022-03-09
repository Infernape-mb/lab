// 11 Double ended queue
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
struct queue
{
    int *data;
    int front, rear, size, count;
};
typedef struct queue QUEUE;
void insertrear(QUEUE *q, int data)
{
    if (q->size >= SIZE)
    {
        printf("Cannot insert from rear\n");
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
    (q->rear)++;
    *(q->data + q->rear) = data;
}
void insertfront(QUEUE *q, int data)
{
    if (q->front == 0)
    {
        printf("Cannot insert from front\n");
        return;
    }
    printf("%d is inserted\n");
    if (q->front == -1)
        (q->front)++;
    else
        (q->front)--;
    (q->count)++;
    *(q->data + q->front) = data;
}
void deletefront(QUEUE *q)
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
void deleterear(QUEUE *q)
{
    if (q->rear == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("%d deleted\n", *(q->data + q->rear));
    (q->count)--;
    (q->rear)--;
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
    {
        printf("%d ", *(q->data + i));
    }
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
        printf("1.Insert Front\n2.Insert Rear\n3.Delete Front\n4.Delete Rear\n5.Display\n6.Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element: ");
            scanf("%d", &ele);
            insertfront(&q, ele);
            break;
        case 2:
            printf("Enter the element: ");
            scanf("%d", &ele);
            insertrear(&q, ele);
            break;
        case 3:
            deletefront(&q);
            break;
        case 4:
            deleterear(&q);
            break;
        case 5:
            display(&q);
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice\n");
            break;
        }
    }
}