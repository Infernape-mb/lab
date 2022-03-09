// 09 Postfix and Prefix evaluation
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
struct stack
{
    int data[100];
    int top;
};
typedef struct stack STACK;
void push(STACK *s, int ele)
{
    s->data[++(s->top)] = ele;
}
int pop(STACK *s)
{
    return s->data[(s->top)--];
}
int eval(char c, int n1, int n2)
{
    switch (c)
    {
    case '+':
        return n1 + n2;
    case '-':
        return n1 - n2;
    case '*':
        return n1 * n2;
    case '/':
        return n1 / n2;
    case '$':
    case '^':
        return pow(n1, n2);
    }
}
void main()
{
    STACK P;
    char s[100];
    P.top = -1;
    int i = 0, n1, n2, choice;
    printf("Enter your choice\n1.Postfix Evaluation\n2.Prefix Evaluation\n");
    scanf("%d", &choice);
    printf("Enter expression : \n");
    scanf("%s", s);
    switch (choice)
    {
    case 1:
        for (i = 0; s[i] != '\0'; i++)
            if (isdigit(s[i]))
                push(&P, s[i] - '0');
            else
            {

                n2 = pop(&P);
                n1 = pop(&P);
                push(&P, eval(s[i], n1, n2));
            }
        break;
    case 2:
        for (i = strlen(s) - 1; i >= 0; i--)
            if (isdigit(s[i]))
                push(&P, s[i] - '0');
            else
            {
                n1 = pop(&P);
                n2 = pop(&P);
                push(&P, eval(s[i], n1, n2));
            }
        break;
    default:
        printf("Invalid choice \n");
        exit(0);
        break;
    }

    printf("Result = %d\n", pop(&P));
}