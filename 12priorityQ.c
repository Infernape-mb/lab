#include <stdio.h>
#include <stdlib.h>
 
#define MAX 5

 struct node {
int *pri_que;
int front, rear;
 };
 typedef struct node nd;
 

 void check(int data,nd *queue)
{
    int i,j;
 
    for (i = 0; i <= queue->rear; i++)
    {
        if (data >= queue->pri_que[i])
        {
            for (j = queue->rear + 1; j > i; j--)
            {
               queue->pri_que[j] = queue->pri_que[j - 1];
            }
            queue->pri_que[i] = data;
            return;
        }
    }
    queue->pri_que[i] = data;
}
 
/* Function to create an empty priority queue */
void create(nd *queue)
{
    queue->front = queue->rear = -1;
}
 
/* Function to insert value into priority queue */
void insert_by_priority(int data,nd *queue)
{
    if (queue->rear >= MAX - 1)
    {
        printf("\nQueue overflow no more elements can be inserted");
        return;
    }
    if ((queue->front == -1) && (queue->rear == -1))
    {
        queue->front++;
        queue->rear++;
        queue->pri_que[queue->rear] = data;
        return;
    }    
    else
        check(data,queue);
    queue->rear++;
}
 

/* Function to delete an element from queue */
void delete_by_priority(int data,nd *q)
{
    int i;
 
    if ((q->front==-1) && (q->rear==-1))
    {
        printf("\nQueue is empty no elements to delete");
        return;
    }
 
    for (i = 0; i <= q->rear; i++)
    {
        if (data == q->pri_que[i])
        {
            for (; i < q->rear; i++)
            {
                q->pri_que[i] = q->pri_que[i + 1];
            }
 
        q->pri_que[i] = -99;
        q->rear--;
 
        if (q->rear == -1) 
            q->front = -1;
        return;
        }
    }
    printf("\n%d not found in queue to delete", data);
}
 
/* Function to display queue elements */
void display_pqueue(nd *q)
{
    if ((q->front == -1) && (q->rear == -1))
    {
        printf("\nQueue is empty");
        return;
    }
 
    for (; q->front <= q->rear; q->front++)
    {
        printf(" %d ", q->pri_que[q->front]);
    }
 
    q->front = 0;
}
void main()
{
    int n, ch;
     nd *queue;
     queue=(nd*)malloc(sizeof(nd));
     queue->pri_que=(int *)malloc(sizeof(int)*MAX);
      printf("\n1 - Insert an element into queue");
    printf("\n2 - Delete an element from queue");
    printf("\n3 - Display queue elements");
    printf("\n4 - Exit");
 
    create(queue);
 
    while (1)
    {
        printf("\nEnter your choice : ");    
        scanf("%d", &ch);
 
        switch (ch)
        {
        case 1: 
            printf("\nEnter value to be inserted : ");
            scanf("%d",&n);
            insert_by_priority(n,queue);
            break;
        case 2:
            printf("\nEnter value to delete : ");
            scanf("%d",&n);
            delete_by_priority(n,queue);
            break;
        case 3: 
            display_pqueue(queue);
            break;
        case 4: 
            exit(0);
        default: 
            printf("\nChoice is incorrect, Enter a correct choice");
        }
    }
}