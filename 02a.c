// Array with static memory allocation
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
void display(int arr[], int n)
{
    int i;
    if (n == 0)
    {
        printf("Array is empty\n");
        return;
    }
    printf("Array:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

void insertbeg(int arr[], int *n, int ele)
{
    int i;
    if (*n >= SIZE)
    {
        printf("Array is full");
        return;
    }
    (*n)++;
    for (i = *n - 1; i > 0; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = ele;
}
void insertend(int arr[], int *n, int ele)
{
    if (*n >= SIZE)
    {
        printf("Array is full");
        return;
    }
    (*n)++;
    arr[*n - 1] = ele;
}
void insertpos(int arr[], int *n, int ele, int pos)
{
    int i;
    if (pos < 0 || pos > *n)
    {
        printf("Invalid position\n");
        return;
    }
    (*n)++;

    for (i = *n - 1; i > pos; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[pos] = ele;
}
void delbeg(int arr[], int *n)
{
    int i;
    if (*n == 0)
    {
        printf("Array is empty\n");
        return;
    }
    printf("%d is deleted\n", arr[0]);
    for (i = 0; i < *n - 1; i++)
        arr[i] = arr[i + 1];
    (*n)--;
}
void delend(int arr[], int *n)
{
    if (*n == 0)
    {
        printf("Array is empty\n");
        return;
    }
    printf("%d is deleted\n", arr[*n - 1]);
    (*n)--;
}

void delpos(int arr[], int *n, int pos)
{
    int i;
    if (*n == 0)
    {
        printf("Array is empty\n");
        return;
    }
    if (pos < 0 || pos >= *n)
    {
        printf("Invalid Position\n");
        return;
    }
    printf("%d is deleted\n", arr[pos]);
    for (i = pos; i < *n - 1; i++)
        arr[i] = arr[i + 1];
    (*n)--;
}

int search(int arr[], int n, int key)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == key)
            return i;
    }
    return -1;
}
void reverse(int arr[], int n)
{
    int i;
    int temp;
    for (i = 0; i < n / 2; i++)
    {
        temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
}
void main()
{
    int arr[SIZE], n = 0, choice, ele, pos;
    while (1)
    {
        printf("\n\nEnter Yor Choice:\n1.Display\n2.Insert Beg\n3.Insert End\n4.Insert Pos\n5.Delete beg\n6.Delete End\n7.Delete pos\n8.Delete key\n9.Search\n10.Reverse\n11.Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            display(arr, n);
            break;
        case 2:
            printf("Enter the element:");
            scanf("%d", &ele);
            insertbeg(arr, &n, ele);
            break;
        case 3:
            printf("Enter the element:");
            scanf("%d", &ele);
            insertend(arr, &n, ele);
            break;
        case 4:
            printf("Enter the element:");
            scanf("%d", &ele);
            printf("Enter the Position:");
            scanf("%d", &pos);
            insertpos(arr, &n, ele, pos);
            break;
        case 5:
            delbeg(arr, &n);
            break;
        case 6:
            delend(arr, &n);
            break;
        case 7:
            printf("Enter the Position:");
            scanf("%d", &pos);
            delpos(arr, &n, pos);
            break;
        case 8:
            printf("Enter the element:");
            scanf("%d", &ele);
            pos = search(arr, n, ele);
            if (pos == -1)
                printf("%d not found", ele);
            else
                delpos(arr, &n, pos);
            break;
        case 9:
            printf("Enter the element:");
            scanf("%d", &ele);
            pos = search(arr, n, ele);
            if (pos == -1)
                printf("%d not found", ele);
            else
                printf("%d found at index %d", ele, pos);
            break;
        case 10:
            reverse(arr, n);
            display(arr, n);
            break;
        case 11:
            exit(0);
        default:
            printf("Invalid Input");
            break;
        }
    }
}