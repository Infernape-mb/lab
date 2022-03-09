#include<stdio.h>
#include<stdlib.h>
#define n 20

struct queue
{
  int *dq;
  int front,rear;
};

typedef struct queue Q;
int isfull1(Q *q)
{
	if(q->front==0)
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
int isfull2(Q *q)
{
	if(q->rear==n-1)
	 return 1;
    else
	return 0;
}
 

void insertfront(Q *q)
{
	int x;
	printf("enter the data to inserted\n");
	scanf("%d",&x);
	if(isfull1(q)){
	 printf("queue is full\n");
	 return;
	 }
	 else if(isempty(q))
	{
	 q->front=q->rear=0;
	 q->front=x;
	}
	else
	{
		q->front--;
        q->dq[q->front]=x;
	}

}

 void insertrear(Q *q)
 {
	 int x;
	 printf("Enter the element to be inserted\n");
	 scanf("%d",&x);
	 if(isfull2(q))
	 {
		 printf("Queue is full\n");
		 return;
	 }
	 else if(isempty(q))
	 {
		 q->front=q->rear=0;
		 q->dq[q->rear]=x;
		 printf("element is successfully inserted\n");
	 }
	 else{
		 q->rear++;
		 q->dq[q->rear]=x;
	 }
 }

  void deletefront(Q *q)
  {
	  if(isempty(q))
	  {
		  printf("queue is empty\n");
		  return;
	  }
	  else if(q->front==q->rear)
	  {
		  q->front=q->rear=-1;
	  }
	  else{
		  q->front++;
	  }
  }

  void deleterear(Q *q)
  {
	  if(isempty(q))
	  {
         printf("queue is empty\n");
		 return;
	  }
	  else if(q->front==q->rear)
	  {
		  q->front=q->rear=-1;
	  }
	  else{
		  q->rear--;
	  }
  }

   void display(Q *q)
   {
	   if(isempty(q)){
	    printf("queue is empty\n");
	   return;
	   }
	else
	{
      int i=q->front;
	  printf("elemets of queue are\n");
	  for(i;i<=q->rear;i++)
	  {
		  printf("%d  ",q->dq[i]);
	  }
	}
   }

   void main()
   {
	   Q *queue;
	   int ch=0;
	   queue=(Q*)malloc(sizeof(Q));
	   queue->front=queue->rear=-1;
	   queue->dq=(int *)malloc(sizeof(int)*n);
	   while(1)
	{
		printf("enter your choice\n");
		printf("Implementation of  queue\n");
		printf("1.insertrear\n");
		printf("2.insertfront\n3.delete front\n4.delete rear\n");
		printf("5.Display\n");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
				insertrear(queue);
				display(queue);
				break;
			case 2:
				insertfront(queue);
				display(queue);
				break;
			case 3:
				deletefront(queue);
				display(queue);
				break;
			case 4:
			    deleterear(queue);
				display(queue);
				break;
			case 5:
			    display(queue);
				break;
			default:
				exit(0);
		}
	}
   }