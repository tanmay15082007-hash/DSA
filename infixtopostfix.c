#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ── STACK FOR OPERATORS ───────────────────────────
char stack[50];
int top = -1;

// ── PUSH ──────────────────────────────────────────
void push(char c){
    top++;
    stack[top] = c;
}

// ── POP ───────────────────────────────────────────
char pop(){
    if(top == -1){
        return -1;
    }
    char c = stack[top];
    top--;
    return c;
}

// ── PEEK ──────────────────────────────────────────
char peek(){
    if(top == -1){
        return -1;
    }
    return stack[top];
}

// ── IS EMPTY ──────────────────────────────────────
int isEmpty(){
    if(top == -1){
        return 1;
    }
    return 0;
}

// ── PRECEDENCE ────────────────────────────────────
int precedence(char c){
    if(c == '^')
        return 3;            // highest
    else if(c == '*' || c == '/')
        return 2;            // medium
    else if(c == '+' || c == '-')
        return 1;            // lowest
    else
        return 0;
}

// ── IS OPERAND ────────────────────────────────────
int isOperand(char c){
    if(c >= 'a' && c <= 'z')
        return 1;
    if(c >= 'A' && c <= 'Z')
        return 1;
    if(c >= '0' && c <= '9')
        return 1;
    return 0;
}

// ── INFIX TO POSTFIX ──────────────────────────────
void infixToPostfix(char *infix, char *postfix){
    int i = 0;    // infix index
    int j = 0;    // postfix index
    char c;

    while(infix[i] != '\0'){
        c = infix[i];

        // CASE 1: operand → directly add to postfix
        if(isOperand(c)){
            postfix[j] = c;
            j++;
        }

        // CASE 2: '(' → push to stack
        else if(c == '('){
            push(c);
        }

        // CASE 3: ')' → pop until '('
        else if(c == ')'){
            while(!isEmpty() && peek() != '('){
                postfix[j] = pop();
                j++;
            }
            pop();           // remove '(' from stack
        }

        // CASE 4: operator → pop higher/equal precedence then push
        else{
            while(!isEmpty() && precedence(peek()) >= precedence(c)){
                postfix[j] = pop();
                j++;
            }
            push(c);
        }
        i++;
    }

    // CASE 5: pop remaining operators from stack
    while(!isEmpty()){
        postfix[j] = pop();
        j++;
    }
    postfix[j] = '\0';       // null terminate
}

int main(){
    char infix[50];
    char postfix[50];

    // ── TEST 1 ────────────────────────────────────
    strcpy(infix, "a+b*c");
    infixToPostfix(infix, postfix);
    printf("Infix:   %s\n", infix);
    printf("Postfix: %s\n", postfix);

    // ── TEST 2 ────────────────────────────────────
    strcpy(infix, "a+b*c-d");
    infixToPostfix(infix, postfix);
    printf("\nInfix:   %s\n", infix);
    printf("Postfix: %s\n", postfix);

    // ── TEST 3 ────────────────────────────────────
    strcpy(infix, "(a+b)*(c-d)");
    infixToPostfix(infix, postfix);
    printf("\nInfix:   %s\n", infix);
    printf("Postfix: %s\n", postfix);

    // ── TEST 4 ────────────────────────────────────
    strcpy(infix, "a^b+c*d");
    infixToPostfix(infix, postfix);
    printf("\nInfix:   %s\n", infix);
    printf("Postfix: %s\n", postfix);

    // ── TEST 5 ────────────────────────────────────
    strcpy(infix, "((a+b)*c)-d^e");
    infixToPostfix(infix, postfix);
    printf("\nInfix:   %s\n", infix);
    printf("Postfix: %s\n", postfix);

    return 0;
}