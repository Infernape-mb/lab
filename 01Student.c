// 1 - Students marks
#include <stdio.h>
#include <stdlib.h>

struct student
{
    char name[20];
    int reg_no;
    int m1, m2, m3;
    float avg;
};
typedef struct student STD;

void calc_avg(STD *s)
{
    int min = s->m1;
    if (s->m2 < min)
        min = s->m2;
    if (s->m3 < min)
        min = s->m3;
    s->avg = (s->m1 + s->m2 + s->m3 - min) / 2;
}

void read(STD *s)
{
    printf("Enter name:");
    scanf("%s", &s->name);
    printf("Enter reg_no:");
    scanf("%d", &s->reg_no);
    printf("Enter marks of 3 test:\n");
    scanf("%d %d %d", &s->m1, &s->m2, &s->m3);
    calc_avg(s);
}

void display(STD *s)
{
    printf("%-10s%-7d%-7d%-7d%-7d%-.1f\n", s->name, s->reg_no, s->m1, s->m2, s->m3, s->avg);
}
void main()
{
    int choice, n, i;
    STD *arr;
    while (1)
    {
        printf("Enter Your Choice:\n1.Read\n2.Display\n3.Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the number of students: ");
            scanf("%d", &n);
           // free(arr);
            arr = (STD *)calloc(n, sizeof(STD));
            for (i = 0; i < n; i++)
            {
                printf("\nStudent - %d \n", i + 1);
                read(arr + i);
            }
            break;
        case 2:
            printf("Name     reg_no   m1    m2    m3    avg\n");
            for (i = 0; i < n; i++)
                display(arr + i);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid Input");
            break;
        }
    }
}