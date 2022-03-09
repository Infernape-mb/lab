//program to implement doubly linked list with header node
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

struct node
{
	int data;
	struct node *next,*prev;
};
int count=0;

typedef struct node n;

n * create(n* head)
{
	int x,m,i=0;
	n *newnode,*temp; 
	newnode=(n*)malloc(sizeof(n));
	
	newnode->data=count;
	newnode->next=head;
	newnode->prev=head;
	head=newnode;
	temp=head;
	printf("Enter the number of nodes \n");
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
      newnode=(n*)malloc(sizeof(n));
	  printf("enter the data %d \n",(i+1));
	  scanf("%d",&x);
	  newnode->data=x;
	  newnode->next=head;
	  newnode->prev=temp;
	  temp->next=newnode;
	  head->prev=newnode;
	  temp=temp->next;
     head->data++;
	}
	
	return head;
}

void insertpos(n* head,int item)
{
	int pos,i=1;
	n *temp=head;
	if(head==NULL)
	 {
		 n * newnode=(n*)malloc(sizeof(n));
		 newnode->data=item;
		 head=newnode;
		 newnode->next=head;
		 newnode->prev=head;
		 return;
	 }
	printf("enter the position \n");
	scanf("%d",&pos);
	if(pos<=head->data){
		n *newnode=(n*)malloc(sizeof(n));
		newnode->data=item;
		head->data++;
    for(i;i<pos;i++)
	{
      temp=temp->next;
	}
	newnode->prev=temp;
	newnode->next=temp->next;
	temp->next->prev=newnode;
	temp->next=newnode;
    }
	else{
		printf("invalid position\n");
	}

}

 void deletepos(n *head)
 {
	 int pos,i;
	 n *temp=head,*ptr;
     printf("enter the position \n");
	 scanf("%d",&pos);
	 if(pos>head->data)
	 {
		 printf("invalid postion\n");
	 }
	 else
	 {
		 for(i=1;i<pos;i++)
		 {
          temp=temp->next;
		 }
        ptr=temp->next;
		temp->next=ptr->next;
		ptr->next->prev=temp;
		free(ptr);
		head->data--;
	 }
 }

  void searchk(n *head,int key)
  {
	  int i=0,flag=0;
	  n *temp=head->next;
	  if(head==NULL)
	   printf("list is empty\n");
	  else
	  {
		  for(i;i<head->data;i++)
		  {
            if(temp->data==key)
			{
				printf("element found at position %d",(i+1));
				flag=1;
			}
			temp=temp->next;
		  }
		  if(flag==0)
		   printf("Element not found\n");

	  }
  }

  n * reverse(n *head)
  {
	  if(head==NULL)
	   printf("list is empty\n");
	  else
	  {
		  n *pre,*nxt,*cur;
		  pre=head->prev;
		  nxt=NULL;
		  cur=head;
		  while(cur->next!=head)
		  {
			  nxt=cur->next;
			  cur->next=pre;
			  cur->prev=nxt;
			  pre=cur;
			  cur=nxt;
		  }
			cur->prev=nxt;
			cur->next=pre;
	  }
	  
	  return head;
  }
  void display( n* head)
  {
	  n *temp=head->next;
	if(head==NULL){
	 printf("list is empty\n");
	 return;
	}
	else
	{
		printf("elements of list are\n");
		while (temp!=head)
		{
			printf(" %d ",temp->data);
			temp=temp->next;
		}
		//printf(" %d ",temp->data);
		printf("\n");
		
	}
  }

  void main()
  {
	  int choice;
	  n *head;
	  int x,k;
	  head=NULL;
	  head=create(head);
      while(1)
	  {
		  printf("Enter your choice\n");
		  printf("1.insert at position\n2.delete at pos\n3.search\n4.revers\n");
		  scanf("%d",&choice);
		  switch (choice)
		  {
			  case 1: 
			          printf("enter the element to be inserted\n");
					  scanf("%d",&x);
					  insertpos(head,x);
					  display(head);
					  break;
			  case 2: deletepos(head);
			          display(head);
			          break;
			  case 3:  
			           printf("enter the search element\n");
					   scanf("%d",&k);
			           searchk(head,k);
			           break;
			  case 4:head=reverse(head);
			         display(head);
			         break;
		  }
		  
	  }
  }