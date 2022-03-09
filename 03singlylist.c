// 03 Single linked list
#include <stdio.h>
#include <stdlib.h>

typedef struct node *NODE;
struct node
{
    int data;
    NODE link;
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
    new->link = NULL;
    return new;
}

void display(NODE temp)
{
    if (temp == NULL)
    {
        printf("List is Empty\n");
        return;
    }
    printf("LIST : \n");
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}

NODE insertpos(NODE head, int data, int pos)
{
    int i = 0;
    if (pos < 0 || (head == NULL && pos > 0))
    {
        printf("Invalid pos\n");
        return head;
    }
    NODE new = create(data);
    NODE cur = head, prev;
    if (pos == 0)
    {
        printf("%d is inserted\n", data);
        new->link = head;
        display(new);
        return new;
    }
    if (head == NULL)
    {
        printf("%d is inserted\n", data);
        display(new);
        return new;
    }
    while (cur != NULL && i < pos - 1)
    {
        prev = cur;
        cur = cur->link;
        i++;
    }
    if (cur == NULL)
    {
        printf("Invalid pos\n");
        return head;
    }
    printf("%d is inserted\n", data);
    new->link = cur->link;
    cur->link = new;
    display(head);
    return head;
}

NODE delpos(NODE head, int pos)
{
    int i = 0;
    if (pos < 0)
    {
        printf("Invalid pos\n");
        return head;
    }
    NODE cur = head, prev;

    if (head == NULL)
    {
        printf("List is Empty\n");
        return NULL;
    }
    if (pos == 0)
    {
        printf("%d is deleted\n", head->data);
        cur = head->link;
        free(head);
        display(cur);
        return cur;
    }

    while (cur != NULL && i < pos)
    {
        prev = cur;
        cur = cur->link;
        i++;
    }
    if (cur == NULL)
    {
        printf("Invalid pos\n");
        return head;
    }
    prev->link = cur->link;
    printf("%d is deleted\n", cur->data);
    free(cur);
    display(head);
    return head;
}

NODE reverse(NODE head)
{
    NODE prev = NULL, cur = head, next;
    if (head == NULL)
    {
        printf("List is empty\n");
        return NULL;
    }
    while (cur != NULL)
    {
        next = cur->link;
        cur->link = prev;
        prev = cur;
        cur = next;
    }
    display(prev);
    return prev;
}

int search(NODE head, int key)
{
    NODE temp = head;
    int i = 0;
    while (temp != NULL)
    {
        if (temp->data == key)
            return i;
        temp = temp->link;
        i++;
    }
    return -1;
}

void main()
{
    NODE head = NULL, copy = NULL;
    int ele, choice, pos;

    while (1)
    {
        printf("\nEnter Your Choice \n1.Display\n2.Insert Pos\n3.Delete Pos\n4.Search\n5.Reverse\n6.Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            display(head);
            break;

        case 2:
            printf("Enter the element:");
            scanf("%d", &ele);
            printf("Enter the pos:");
            scanf("%d", &pos);
            head = insertpos(head, ele, pos);
            break;

        case 3:
            printf("Enter the pos:");
            scanf("%d", &pos);
            head = delpos(head, pos);
            break;

        case 4:
            printf("Enter the element:");
            scanf("%d", &ele);
            pos = search(head, ele);
            if (pos == -1)
                printf("%d not found", ele);
            else
                printf("%d found at index %d", ele, pos);
            break;

        case 5:
            head = reverse(head);
            break;

        case 6:
            exit(0);

        default:
            printf("Invalid choice\n");
            break;
        }
    }
}