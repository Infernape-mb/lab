// 06 Circular Double linked list with header
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
    new->next = new;
    new->prev = new;
    return new;
}

void display(NODE header)
{
    NODE temp = header->next;
    if (header == NULL || header->next == header)
    {
        printf("List is Empty\n");
        return;
    }
    printf("List :\n");
    while (temp != header)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insertpos(NODE header, int data, int pos)
{
    int i = 0;
    if (pos < 0 || (header->next == header && pos > 0))
    {
        printf("Invalid pos\n");
        return;
    }
    NODE new = create(data);
    NODE cur = header;
    while (i < pos)
    {
        cur = cur->next;
        i++;
        if (cur == header)
        {
            printf("Invalid pos\n");
            return;
        }
    }

    printf("%d is inserted\n", data);
    new->next = cur->next;
    cur->next = new;
    new->prev = cur;
    new->next->prev = new;
    display(header);
}

void delpos(NODE header, int pos)
{
    int i = 0;
    if (pos < 0)
    {
        printf("Invalid pos\n");
        return;
    }
    NODE cur = header->next, prev;

    if (header == header->next)
    {
        printf("List is Empty\n");
        return;
    }
    while (i < pos)
    {
        cur = cur->next;
        i++;
        if (cur == header)
        {
            printf("Invalid pos\n");
            return;
        }
    }
    prev = cur->prev;
    prev->next = cur->next;
    prev->next->prev = prev;
    printf("%d is deleted\n", cur->data);
    free(cur);
    display(header);
    return;
}

void delkey(NODE header, int key)
{
    NODE cur = header->next, prev;

    if (header == header->next)
    {
        printf("List is Empty\n");
        return;
    }
    while (cur != header && cur->data != key)
    {
        cur = cur->next;
    }
    prev = cur->prev;
    if (cur == header)
    {
        printf("Element Not Found\n");
        return;
    }
    prev->next = cur->next;
    prev->next->prev = prev;
    printf("%d is deleted\n", cur->data);
    free(cur);
    display(header);
}

void reverse(NODE header)
{
    NODE prev = NULL, cur = header, next, temp;
    if (header == header->next)
    {
        printf("List is empty\n");
        return;
    }
    do
    {
        prev = cur;
        temp = cur->next;
        cur->next = cur->prev;
        cur->prev = temp;
        cur = temp;
    } while (cur != header);
    display(header);
}

void main()
{
    NODE header = create(0), copy = NULL;
    int ele, choice, pos;

    while (1)
    {
        printf("\nEnter Your Choice \n1.Display\n2.Insert Pos\n3.Delete Pos\n4.Delete key\n5.Reverse\n6.Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            display(header);
            break;

        case 2:
            printf("Enter the element:");
            scanf("%d", &ele);
            printf("Enter the pos:");
            scanf("%d", &pos);
            insertpos(header, ele, pos);
            break;

        case 3:
            printf("Enter the pos:");
            scanf("%d", &pos);
            delpos(header, pos);
            break;

        case 4:
            printf("Enter the element:");
            scanf("%d", &ele);
            delkey(header, ele);
            break;

        case 5:
            reverse(header);
            break;

        case 6:
            exit(0);

        default:
            printf("Invalid choice\n");
            break;
        }
    }
}