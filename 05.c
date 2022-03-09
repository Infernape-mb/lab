// 05 Double linked list
#include <stdio.h>
#include <stdlib.h>

typedef struct node *NODE;
struct node
{
    int data;
    NODE next;
    NODE prev;
};

NODE create(int data)
{
    NODE new = (NODE)malloc(sizeof(struct node));
    if (new == NULL)
    {
        printf("Memory could not be allocated\n");
        exit(0);
    }
    new->data = data;
    new->next = NULL;
    new->prev = NULL;
    return new;
}

void display(NODE temp)
{
    if (temp == NULL)
    {
        printf("List is Empty\n");
        return;
    }
    printf("List :\n");
    while (temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

NODE insertbeg(NODE head, int data)
{
    printf("%d is inserted\n", data);
    NODE new = create(data);
    if (head == NULL)
    {
        display(new);
        return new;
    }
    new->next = head;
    head->prev = new;
    display(new);
    return new;
}
NODE insertend(NODE head, int data)
{
    printf("%d is inserted\n", data);
    NODE new = create(data);
    NODE temp = head;
    if (head == NULL)
    {
        display(new);
        return new;
    }
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = new;
    new->prev = temp;
    display(head);
    return head;
}

NODE delbeg(NODE head)
{
    if (head == NULL)
    {
        printf("List is Empty\n");
        return NULL;
    }
    printf("%d is deleted\n", head->data);
    NODE temp = head->next;
    free(head);
    if (temp != NULL)
        temp->prev = NULL;
    else
    {
        display(NULL);
        return NULL;
    }
    display(temp);
    return temp;
}
NODE delend(NODE head)
{
    if (head == NULL)
    {
        printf("List is Empty\n");
        return NULL;
    }
    NODE cur = head, prev;
    if (head->next == NULL)
    {
        printf("%d is deleted\n", head->data);
        free(head);
        display(NULL);
        return NULL;
    }
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    prev = cur->prev;
    printf("%d is deleted\n", cur->data);
    prev->next = NULL;
    free(cur);
    display(head);
    return head;
}

NODE delkey(NODE head, int key)
{
    NODE cur = head, prev;

    if (head == NULL)
    {
        printf("List is Empty\n");
        return NULL;
    }
    if (head->data == key)
    {
        printf("%d is deleted\n", head->data);
        cur = head->next;
        free(head);
        if (cur != NULL)
            cur->prev = NULL;
        else
        {
            display(NULL);
            return NULL;
        }
        display(cur);
        return cur;
    }

    while (cur != NULL && cur->data != key)
    {
        cur = cur->next;
    }
    prev = cur->prev;
    if (cur == NULL)
    {
        printf("Element Not Found\n");
        return head;
    }
    prev->next = cur->next;
    if (prev->next != NULL)
        prev->next->prev = prev;
    printf("%d is deleted", cur->data);
    free(cur);
    display(head);
    return head;
}

NODE reverse(NODE head)
{
    NODE prev = NULL, cur = head, next, temp;
    if (head == NULL)
    {
        printf("List is empty\n");
        return NULL;
    }
    while (cur != NULL)
    {
        prev = cur;
        temp = cur->next;
        cur->next = cur->prev;
        cur->prev = temp;
        cur = temp;
    }
    display(prev);
    return prev;
}

void main()
{
    NODE head = NULL, copy = NULL;
    int ele, choice, pos;

    while (1)
    {
        printf("\nEnter Your Choice \n1.Display\n2.Insert Beg\n3.Insert End\n4.Delete Beg\n5.Delete End\n6.Delete key\n7.Reverse\n8.Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            display(head);
            break;
        case 2:
            printf("Enter the element:");
            scanf("%d", &ele);
            head = insertbeg(head, ele);
            break;
        case 3:
            printf("Enter the element:");
            scanf("%d", &ele);
            head = insertend(head, ele);
            break;
        case 4:
            head = delbeg(head);
            break;
        case 5:
            head = delend(head);
            break;
        case 6:
            printf("Enter the element:");
            scanf("%d", &ele);
            head = delkey(head, ele);
            break;
        case 7:
            head = reverse(head);
            break;
        case 8:
            exit(0);
        default:
            printf("Invalid choice\n");
            break;
        }
    }
}