#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 100
int priority(char operator)                     //to check the priority of operator in the stack function created
{
    switch (operator) {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return -1;
    }
}
int is_operator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/'
            || ch == '^');
}

char *conversion(char *infix,char *postfix)          //function for conversion of infix==>postfix
{
    char stack[max]; int top=-1;int i;int j=0;
    int len=strlen(infix);                           //length of infix calculated
   // a+b*(c^d-e)^(f+g*h)-i
    for(i=0;i<len;i++)
    {
        if(isalnum(infix[i]))                        //built in function to check whether it is alphabet or digit
        {
            postfix[j++]=infix[i];
        }
        else if(infix[i]=='(')                        //direct push if it is(
        {
            stack[++top]=infix[i];
        }
        else if(infix[i]==')')                        //if it is ) then pop all element in stack till we get (
        {
            while (top > -1 && stack[top] != '(')
            {postfix[j++] = stack[top--];
            }top--;
        }
        else if(is_operator(infix[i]))                 //for checking priority
        {
            while(top>-1 && priority(stack[top])>= priority(infix[i]))
            {
                postfix[j++]=stack[top--];

            }
             stack[++top] = infix[i];
        }
    }
    while(top>-1 ){                               //after completion of all element from infix then pop all element present in stack
        postfix[j++] = stack[top--];

    }
    postfix[j]='\0';
    return postfix;

}
//LKA/-(CB/A--(

int main()
{
char infix[100];char postfix[100];                           //infix taken from user ///postfix in which resukt will be stored

    printf ("enter the infix:");
    scanf("%s",infix);
  char *result=conversion(infix,postfix);                     //as postfix address will be return so stored in a pointer
    printf("conversion of infix to postfix==>%s",result);     //result printed
    return 0;
}
