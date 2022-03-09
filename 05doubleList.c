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
	int x;
	n *newnode,*temp; 
	newnode=(n*)malloc(sizeof(n));
	printf("enter the element to be inserted\n");
	scanf("%d",&x);
	newnode->data=x;
	newnode->next=NULL;
	newnode->prev=NULL;
	head=newnode;
	return head;
}

n * insertfront(n* head,int item)
{
	int pos,i=1;
	n *temp=head;
	if(head==NULL)
	 {
		 create(head);
	 }
	else{
		n *newnode=(n*)malloc(sizeof(n));
		newnode->next=head;
		newnode->prev=NULL;
		newnode->data=item;
		head=newnode;
	}
	return head;

}

  n * deletefront(n *head)
 {
	if(head==NULL)
	{
		return NULL;
	}
	else if(head->next=NULL){
        head=NULL;
		free (head);
	}
	else{
	 n *temp=head;
	 head=head->next;
	 head->prev=NULL;
	 free(temp);
	 return head;
     
 }}

 n * insertrear(n *head,int item)
 {
	 n * newnode;
	 n *temp=head;
	 newnode=(n*)malloc(sizeof(n));
	 newnode->data=item;
	 while(temp->next!=NULL)
	 {
		 temp=temp->next;
	 }
	 temp->next=newnode;
	 newnode->prev=temp;
	 newnode->next=NULL;
	 return head;
}

   void deleterear(n *head)
   {
	 n *temp=head,*ptr;
	 while(temp->next!=NULL)
	 {
		 ptr=temp;
		 temp=temp->next;
	 }
	 ptr->next=NULL;
	 free(temp);
     return ;
   }

  void deletek(n *head,int key)
  {
	  int flag=0;
	  n *temp=head,*ptr=NULL,*temp1;
	  if(head==NULL)
	   printf("list is empty\n");
	  else{
		  while(temp->next!=NULL)
		  {
			 
			  if(key==temp->data)
			   {
				   temp->next->prev=ptr;
				   ptr->next=temp->next;
				   temp1=temp;
				   free(temp1);
			   }
		  }
		  if(temp->data==key)
		  {
			  ptr->next=NULL;
			  free(temp);
		  }
	  }
	  
  }

  n * reverse(n *head)
  {
	  if(head==NULL)
	   printf("list is empty\n");
	  else
	  {
		  n *pre,*nxt,*cur;
		  pre=NULL;
		  nxt=NULL;
		  cur=head;
		  while(cur!=NULL)
		  {
			  nxt=cur->next;
			  cur->next=pre;
			  cur->prev=nxt;
			  pre=cur;
			  cur=nxt;
		  }
			head=cur;
	  }
	  
	  return head;
  }
  void display( n* head)
  {
	  n *temp=head;
	if(head==NULL){
	 printf("list is empty\n");
	 return;
	}
	else
	{
		printf("elements of list are\n");
		while (temp!=NULL)
		{
			printf(" %d ",temp->data);
			temp=temp->next;
		}
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
		  printf("1.insert front\n2.delete front\n3.insert rear\n4.delete rear\n5.key delete\n6.reverse\n");
		  scanf("%d",&choice);
		  switch (choice)
		  {
			  case 1: 
			          printf("enter the element to be inserted\n");
					  scanf("%d",&x);
					  head=insertfront(head,x);
					  display(head);
					  break;
			  case 2 :head=deletefront(head);
					  display(head);
					  break;
			  case 3: printf("enter the element to be inserted\n");
					  scanf("%d",&x);
					 insertrear(head,x);
					  display(head);
					  break;
			  case 4: deleterear(head);
					  display(head);
					  break;
			  case 5:printf("enter the data to be deleted\n");
			         scanf("%d",&x);
					 deletek(head,x);
					 break;
			  case 6:head=reverse(head);
			         display(head);
			         break;
		  }
		  
	  }
  }