#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
#define n 50
char stack[n];
int top=-1;

void push(int num)
{
	if(top>=n-1)
	 printf("Stack overflow\n");
	else
	 {
		 top++;
		 stack[top]=num;
	 }
}

 int pop()
 { 
	 int item;
	 if(top<0)
	  printf("Stack underflow\n");
	else
	{
     item=stack[top];
	 top--;
	 return item;
	}
 }
 int is_operator(char symbol)
{
	if(symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol =='-')
	{
		return 1;
	}
	else
	{
	return 0;
	}
}

  void evaluation(char postfix[])
   {
    int i=0,num1,num2;
	for(i=0;i<strlen(postfix);i++){
     if(isdigit(postfix[i])==1)
	{
		//printf("1\n");
		push(postfix[i]-'0');
    }
	else if(is_operator(postfix[i])==1)
	{
      num1=pop();
	  num2=pop();
	 // printf("%d %d\n",num1,num2);
	 // printf("%d \n",num1+num2);
	  if(postfix[i]=='+'){
	   push(num2+num1);
	  }
	  else if(postfix[i]=='-'){
	   push(num2-num1);}
	  else if(postfix[i]=='*'){
	   push(num2*num1);}
	  else if(postfix[i]='/'){
	   push(num2/num1);}
	  else if(postfix[i]='^'){
	   push(pow(num2,num1));}
	  
	}
   }

   }

   int main()
   {
	   char postfix[n];
	   printf("enter postfix expression\n");
	   gets(postfix);
	   evaluation(postfix);
	   printf("Final answer is \n %d",stack[top]);

   }