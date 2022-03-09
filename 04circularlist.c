#include<stdio.h>
 #include<stdlib.h>

 struct node
  {
     int data;
     struct node *next;
  };

  typedef struct node n;

  n *getnode()
  {
     struct node *newnode;
     newnode = (struct node *)malloc(sizeof(struct node));
     printf("Enter data :");
     scanf("%d",&newnode->data);
     newnode->next=NULL;
     return newnode;
  }
 
   void insert_pos(n * head) {
     int pos,count=1,i=1;
	 n *temp,*n1;
     temp=head;
 
     if(head==NULL) {
        n1=getnode();
        head=n1;
        n1->next=head;
        return;    } 
	 printf("Enter position :");  
	 scanf("%d",&pos);  
	 while(temp->next!=head){
	 count++;
	 temp=temp->next;
	 } 
		if(pos>count+1)
		{ printf("Invalidposition\n");
       return;    }   
	    if(pos==1||pos==count+1)
		{
			 n1=getnode();
 
        if(head==NULL) {
           head=n1;
           n1->next=head;
        }
     else {
          temp=head;
          while(temp->next!=head)
             temp=temp->next;
          temp->next=n1;
          n1->next=head;
          }
		}
		    
			 else {
				 temp=head;
				 n1=getnode();
  for(i=1;i<pos-1;i++){
                temp=temp->next;
            n1->next=temp->next;
            temp->next=n1;
         }
 }
  }

  void deletepos(n *head)
  {
	  struct node *nextnode,*temp;
    int pos,i=1,count=1;
    if(head==NULL)
         return;
 temp=head;
    while(temp->next!=head) {
       count++;
       temp=temp->next;
    }
    printf("Enter position :");
    scanf("%d",&pos);
    if(pos==1||pos==count)
      {
		  struct node *prevnode;
    if(head==NULL)
         return;
    else if(head->next==head) {
       head=NULL;
       free(head);
    }
    else {
       temp=head;
       while(temp->next!=head)
       {
          prevnode=temp;
          temp=temp->next;
       }
       prevnode->next=temp->next;
       free(temp);
    }
	  }
  
    else if(pos>count||count<0)
       printf("Invalid position \n");
    else {
       temp=head;
       while(i<pos-1) {
          temp=temp->next;
          i++;
       }
       nextnode=temp->next;
       temp->next=nextnode->next;
       free(nextnode);
    }
  }

  void deleteK(n *head)
  {
	  int key;
    struct node *prev,*temp;
    temp=head;
	prev=temp;
    if(head==NULL)       
       return;

    printf("Enter key to be deleted :");
    scanf("%d",&key);
    while(temp->data!=key)
	{
         if(temp->next==head)
		  {
			  printf("element not found\n");
			  return;
			  
		  }
		  prev=temp;
		  temp=temp->next;
	}
	if(temp->next==head)
	{
		temp=NULL;
		free(temp);
	}
	else
	if(temp==head)
	{
		prev=head;
		while(temp->next!=head)
		{
			temp=temp->next;
        }
		head=head->next;
		temp->next=head;
		free(prev);
	}
	else if(temp->next==head)
	{
		prev->next=head;
		free(temp);
	}
	else{
		prev->next=temp->next;
		free(temp);
	}
  }

  n* reverse(n *head) {
    struct node *prev,*curr,*nextnode;
    if(head==NULL)
       return head;
    prev=NULL;
    curr=head;

    do {
       nextnode=curr->next;
       curr->next=prev;
       prev=curr;
       curr=nextnode;
    }while(curr!=head);
    head->next=prev;
    head=prev;
	return head;
 }
void display(n *head)  {
	n *temp;
    temp=head;
    if(head==NULL)
       printf("List is empty\n");
    else{
       printf("Linked list elements are :");
       do {
          printf("%d   ",temp->data);
          temp=temp->next;
       }while(temp!=head);
    }
 }

 void main()
 {
	 int choice;
	 n *head;
	 head=getnode();
	 head->next=head;
	 while(1){
	 printf("\n1.insert pos\n2.delete pos\n3delete key\n4.reverse\n");
	 scanf("%d",&choice);
	 switch(choice)
	 {
		 case 1: insert_pos(head);
		         display(head);
		  break;
		  case 2:deletepos(head);
		   display(head);
		  break;
		  case 3:deleteK(head);
		  display(head);
		  break;
		  case 4:head=reverse(head);
		  display(head);
		  break;
		  default:exit(0);
	 }
 }
 }