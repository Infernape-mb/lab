#include<stdio.h>
#include<stdlib.h>
#define n 5

struct queue
{
  int *cq;
  int front,rear;
};

typedef struct queue Q;

int isfull(Q * q)
{
	if(q->rear+1%n==q->front)
	 return 1;
	else 
	return 0;
	
}


int isempty(Q *q)
{
	if(q->front==-1&&q->rear==-1)
	 return 1;
	else 
	 return 0;
}

 void enqueue(Q *q)
 {
	 int x;
	 printf("enter the element to be inserted\n");
	 scanf("%d",&x);
	 if(isfull(q))
	 {
	  printf("queue is full\n");
	  return;
	 }
	  else if(q->front==-1&&q->rear==-1)
	  {
        q->front=q->rear=0;
		q->cq[q->rear]=x;
	  }
	  else
	  {
		  q->rear=(q->rear+1)%n;
		  q->cq[q->rear]=x;
	  }
 }

 void dequeue(Q *q)
 {
	 if(isempty(q))
	 {
		 printf("Queue is empty\n");
		 return;
	 }
	 else if(q->front==q->rear)
	 {
		 q->front=q->rear=-1;

	 }
	 else{
		q->front= (q->front+1)%n;

	 }

 }
    void display(Q *q){
		int i;
		//printf("%d",q->front);
		if(isempty(q)){
			printf("queue is empty");
			return;
		}
		else{ 
			printf("elements of queue are\n");
			for(i=q->front;i!=q->rear;i=(i+1)%(n)){
				printf("%d  ",q->cq[i]);
			}
         printf("%d",q->cq[i]);
		}
	}
  /*void peek(Q * q)
  {
	  if(isempty(q))
	   printf("queue is empty\n");
	else {
		printf("top element is %d",q->cq[q->rear]);
	}
  }*/

  int main()
  {
	  Q *queue;
	  int ch;
	  queue=(Q*)malloc(sizeof(Q));
	  queue->front=queue->rear=-1;
	  queue->cq=(int *)malloc(sizeof(int)*n);
	  while(1)
	{
		printf("\nImplementation of  queue\n");
		printf("1.Enqueue\n");
		printf("2.dequeue\n");
		printf("3.Display\n");
			scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
				enqueue(queue);
				break;
			case 2:
				dequeue(queue);
				break;
			case 3:
				display(queue);
				break;
			default:
				exit(0);
		}
	}

  }