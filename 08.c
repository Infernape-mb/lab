// 08 infix to prefix
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
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
void display(STACK *s)
{
    int i;
    for (i = s->top; i >= 0; i--)
        printf("%c", s->data[i]);
}
int pre(char c)
{
    if (c == ')' || c == '#')
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
    STACK prefix, temp;
    prefix.top = temp.top = -1;
    int i;
    char s[100];
    push(&temp, '#');
    printf("Enter infix expression : \n");
    scanf("%s", s);
    printf("Prefix expression : \n");
    for (i = strlen(s) - 1; i >= 0; i--)
    {
        if (s[i] == ' ')
        {
            continue;
        }
        if (s[i] == ')')
        {
            push(&temp, s[i]);
        }
        else if (s[i] == '(')
        {
            while (temp.data[temp.top] != ')')
            {
                push(&prefix, pop(&temp));
            }
            pop(&temp);
        }
        else if (isalnum(s[i]))
        {
            push(&prefix, s[i]);
        }
        else if (isalnum(s[i]) != 1)
        {
            if (pre(s[i]) > pre(temp.data[temp.top]))
            {
                push(&temp, s[i]);
            }
            else
            {
                while (pre(s[i]) <= pre(temp.data[temp.top]))
                {
                    push(&prefix, pop(&temp));
                }
                push(&temp, s[i]);
            }
        }
    }
    while (temp.data[temp.top] != '#')
    {
        push(&prefix, pop(&temp));
    }
    display(&prefix);
}