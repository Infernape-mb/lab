// 04 Circular singly linked list
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
    new->link = new;
    return new;
}

void display(NODE last)
{
    if (last == NULL)
    {
        printf("List is Empty\n");
        return;
    }
    NODE temp = last->link;
    printf("List : \n");
    do
    {
        printf("%d ", temp->data);
        temp = temp->link;
    } while (temp != last->link);
    printf("\n");
}

NODE insertpos(NODE last, int data, int pos)
{
    int i = 0;
    if (pos < 0)
    {
        printf("Invalid pos\n");
        return last;
    }

    NODE new = create(data);
    if (last == NULL)
    {
        printf("%d is inserted\n", data);
        display(new);
        return new;
    }
    NODE cur = last->link, prev = last;
    if (pos == 0)
    {
        printf("%d is inserted\n", data);
        new->link = last->link;
        last->link = new;
        display(last);
        return last;
    }
    while (i < pos - 1)
    {
        printf("%d and i = %d\n", cur->data, i);
        prev = cur;
        cur = cur->link;
        i++;
        if (cur == last->link)
        {
            printf("Invalid pos\n");
            return last;
        }
    }
    printf("%d is inserted\n", data);
    new->link = cur->link;
    cur->link = new;
    if (cur == last)
    {
        display(new);
        return new;
    }
    display(last);
    return last;
}

NODE delpos(NODE last, int pos)
{
    int i = 0;
    if (pos < 0)
    {
        printf("Invalid pos\n");
        return last;
    }
    if (last == NULL)
    {
        printf("List is Empty\n");
        return NULL;
    }
    NODE cur = last->link, prev;

    if (pos == 0)
    {
        printf("%d is deleted", cur->data);
        last->link = cur->link;
        free(cur);
        display(last);
        return last;
    }

    while (i < pos)
    {
        prev = cur;
        cur = cur->link;
        i++;
        if (cur == last->link)
        {
            printf("Invalid pos\n");
            return last;
        }
    }
    printf("%d is deleted", cur->data);
    if (cur == last)
    {
        prev->link = cur->link;
        free(cur);
        display(prev);
        return prev;
    }
    prev->link = cur->link;
    free(cur);
    display(last);
    return last;
}

NODE delkey(NODE last, int key)
{
    if (last == NULL)
    {
        printf("List is Empty\n");
        return NULL;
    }
    NODE cur = last->link, prev = last;
    do
    {
        if (cur->data == key)
        {
            break;
        }
        prev = cur;
        cur = cur->link;
    } while (cur != last->link);
    if (cur->data != key)
    {
        printf("Element Not Found\n");
        return last;
    }
    printf("%d is deleted\n", cur->data);
    prev->link = cur->link;
    if (cur == last)
    {
        if (cur->link == cur)
        {
            free(cur);
            display(NULL);
            return NULL;
        }
        free(cur);
        display(prev);
        return prev;
    }
    free(cur);
    display(last);
    return last;
}

NODE reverse(NODE last)
{
    if (last == NULL)
    {
        printf("List is empty\n");
        return NULL;
    }
    NODE prev = last, cur = last->link, first = last->link, next;
    do
    {
        next = cur->link;
        cur->link = prev;
        prev = cur;
        cur = next;
    } while (cur != first);
    display(cur);
    return cur;
}

void main()
{
    NODE last = NULL, copy = NULL;
    int ele, choice, pos;

    while (1)
    {
        printf("\nEnter Your Choice \n1.Display\n2.Insert Pos\n3.Delete Pos\n4.Delete key\n5.Reverse\n6.Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            display(last);
            break;

        case 2:
            printf("Enter the element:");
            scanf("%d", &ele);
            printf("Enter the pos:");
            scanf("%d", &pos);
            last = insertpos(last, ele, pos);
            break;

        case 3:
            printf("Enter the pos:");
            scanf("%d", &pos);
            last = delpos(last, pos);
            break;

        case 4:
            printf("Enter the element:");
            scanf("%d", &ele);
            last = delkey(last, ele);
            break;

        case 5:
            last = reverse(last);
            break;

        case 6:
            exit(0);

        default:
            printf("Invalid choice\n");
            break;
        }
    }
}