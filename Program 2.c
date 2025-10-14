#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define MAX 100
char stack[MAX];
int top=-1;

void push(char ch){
    stack[++top]=ch;
}
char pop(){
    if(top == -1)
        return -1;
    else
        return stack[top--];
    }
int precedence(char op){
    if(op == '^')
        return 3;
    else if (op == '*'|| op == '/')
        return 2;
    else if (op == '+'|| op == '-')
        return 1;
    else
        return 0;
}
int isRightAssociative (char op){
    return op =='^';
}
int main(){
    char infix[MAX],postfix[MAX];
    int i,k = 0;
    char ch;

    printf("Enter a infix expression:");
    scanf("%s", infix);

    for ( i = 0;infix[i] != '\0';i++){
        ch = infix[i];

        if(isalnum(ch))
            postfix[k++] = ch;
        else if (ch == '(')
            push(ch);
        else if (ch == ')'){
            while (top != -1 && stack[top] != ')')
                postfix[k++]=pop();
                pop();
        }
        else {
            while( top != -1 && precedence(stack[top])>precedence(ch)|| (precedence(stack[top])==precedence(ch)&& !isRightAssociative(ch)) && stack[top] != '(')
                    postfix[k++]= pop();
                    push(ch);
        }
    }
    while (top != -1)
            postfix [k++]= pop();

    postfix[k] = '\0';
    printf("Postfix expression: %s\n", postfix);
    return 0;
}
