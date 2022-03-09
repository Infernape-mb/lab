// 07 infix to postfix
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
struct stack
{
    char data[100];
    int top;
};
typedef struct stack STACK;
void push(STACK *s, char ele)
{
    s->data[++(s->top)] = ele;
}
char pop(STACK *s)
{
    return s->data[(s->top)--];
}
int pre(char c)
{
    if (c == '(' || c == '#')
        return 1;
    if (c == '+' || c == '-')
        return 2;
    if (c == '*' || c == '/')
        return 3;
    if (c == '^' || c == '$')
        return 4;
}
void main()
{
    STACK P;
    char s[100];
    P.top = -1;
    push(&P, '#');
    int i = 0;
    printf("Enter infix expression : \n");
    scanf("%s", s);
    printf("Postfix expression : \n");
    while (s[i] != '\0')
    {
        if (s[i] == ' ')
        {
            continue;
        }
        if (s[i] == '(')
        {
            push(&P, s[i]);
        }
        else if (s[i] == ')')
        {
            while (P.data[P.top] != '(')
            {
                printf("%c", pop(&P));
            }
            pop(&P);
        }
        else if (isalnum(s[i]))
        {
            printf("%c", s[i]);
        }
        else if (isalnum(s[i]) != 1)
        {
            if (pre(s[i]) > pre(P.data[P.top]))
            {
                push(&P, s[i]);
            }
            else
            {
                while (pre(s[i]) <= pre(P.data[P.top]))
                {
                    printf("%c", pop(&P));
                }
                push(&P, s[i]);
            }
        }
        i++;
    }
    while (P.data[P.top] != '#')
    {
        printf("%c", pop(&P));
    }
}