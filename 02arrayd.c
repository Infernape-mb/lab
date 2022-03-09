// Array with dynamic memory allocation
#include <stdio.h>
#include <stdlib.h>

void display(int *arr, int n)
{
    int i;
    if (arr == NULL)
    {
        printf("Array is empty\n");
        return;
    }
    printf("Array:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", *(arr + i));
    }
    printf("\n");
}

int *insertbeg(int *arr, int *n, int ele)
{
    int i;
    (*n)++;
    arr = (int *)realloc(arr, *n * sizeof(int));
    for (i = *n - 1; i > 0; i--)
    {
        *(arr + i) = *(arr + i - 1);
    }
    *arr = ele;
    return arr;
}
int *insertend(int *arr, int *n, int ele)
{
    (*n)++;
    arr = (int *)realloc(arr, *n * sizeof(int));
    *(arr + *n - 1) = ele;
    return arr;
}
int *insertpos(int *arr, int *n, int ele, int pos)
{
    int i;
    if (pos < 0 || pos > *n)
    {
        printf("Invalid position\n");
        return arr;
    }
    (*n)++;
    arr = (int *)realloc(arr, *n * sizeof(int));
    for (i = *n - 1; i > pos; i--)
    {
        *(arr + i) = *(arr + i - 1);
    }
    *(arr + pos) = ele;
    return arr;
}
int *delbeg(int *arr, int *n)
{
    int i;
    if (*n == 0)
    {
        printf("Array is empty\n");
        return arr;
    }
    printf("%d is deleted\n", *arr);
    for (i = 0; i < *n - 1; i++)
        *(arr + i) = *(arr + i + 1);
    (*n)--;
    arr = (int *)realloc(arr, *n * sizeof(int));
    return arr;
}
int *delend(int *arr, int *n)
{
    if (*n == 0)
    {
        printf("Array is empty\n");
        return arr;
    }
    printf("%d is deleted\n", *(arr + *n - 1));
    (*n)--;
    arr = (int *)realloc(arr, *n * sizeof(int));
    return arr;
}

int *delpos(int *arr, int *n, int pos)
{
    int i;
    if (*n == 0)
    {
        printf("Array is empty\n");
        return arr;
    }
    if (pos < 0 || pos >= *n)
    {
        printf("Invalid Position\n");
        return arr;
    }
    printf("%d is deleted\n", *(arr + pos));
    for (i = pos; i < *n - 1; i++)
        *(arr + i) = *(arr + i + 1);
    (*n)--;
    arr = (int *)realloc(arr, *n * sizeof(int));
    return arr;
}

int search(int *arr, int n, int key)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (*(arr + i) == key)
            return i;
    }
    return -1;
}
void reverse(int *arr, int n)
{
    int i;
    int temp;
    for (i = 0; i < n / 2; i++)
    {
        temp = *(arr + i);
        *(arr + i) = *(arr + n - i - 1);
        *(arr + n - i - 1) = temp;
    }
}
void main()
{
    int *arr = NULL, n = 0, choice, ele, pos;
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
            arr = insertbeg(arr, &n, ele);
            break;
        case 3:
            printf("Enter the element:");
            scanf("%d", &ele);
            arr = insertend(arr, &n, ele);
            break;
        case 4:
            printf("Enter the element:");
            scanf("%d", &ele);
            printf("Enter the Position:");
            scanf("%d", &pos);
            arr = insertpos(arr, &n, ele, pos);
            break;
        case 5:
            arr = delbeg(arr, &n);
            break;
        case 6:
            arr = delend(arr, &n);
            break;
        case 7:
            printf("Enter the Position:");
            scanf("%d", &pos);
            arr = delpos(arr, &n, pos);
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