#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 100
int main() {
    char expression[MAX];
    int stack[MAX];
    int top = -1;
    printf("Enter a postfix expression: ");
    fgets(expression, sizeof(expression), stdin);

    for (int i = 0; expression[i] != '\0'; i++) {
        if (isspace(expression[i])) {
            continue;
        }
        if (isdigit(expression[i])) {
            stack[++top] = expression[i] - '0'; 
        } 
        else {
            int operand2 = stack[top--]; 
            int operand1 = stack[top--];
            switch (expression[i]) {
                case '+':
                    stack[++top] = operand1 + operand2; 
                    break;
                case '-':
                    stack[++top] = operand1 - operand2;
                    break;
                case '*':
                    stack[++top] = operand1 * operand2;
                    break;
                case '/':
                    stack[++top] = operand1 / operand2;
                    break;
                default:
                    printf("Invalid operator: %c\n", expression[i]);
                    return 1; 
            }
        }
    }
    printf("Result: %d\n", stack[top]);
    return 0;
}
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


#include <stdio.h>
#include <string.h>

#define MAX 100
char stack[MAX];
int top = -1;
void push(char c) {
    if (top < MAX - 1) {
        stack[++top] = c;
    }
}

char pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return '\0';
}

int isMatchingPair(char opening, char closing) {
    if (opening == '(' && closing == ')') return 1;
    if (opening == '{' && closing == '}') return 1;
    if (opening == '[' && closing == ']') return 1;
    return 0;
}
void checkSyntax(char *code) {
    int length = strlen(code);
    
    for (int i = 0; i < length; i++) {
        char current = code[i];
        if (current == '(' || current == '{' || current == '[') {
            push(current);
        }
        else if (current == ')' || current == '}' || current == ']') {
            if (top == -1) {
                printf("Syntax error at index %d: unmatched closing '%c'\n", i, current);
                return;
            }
            char popped = pop();
            if (!isMatchingPair(popped, current)) {
                printf("Syntax error at index %d: unmatched closing '%c', expected matching for '%c'\n", i, current, popped);
                return;
            }
        }
    }
    if (top != -1) {
        printf("Syntax error: unmatched opening delimiter '%c'\n", stack[top]);
    } else {
        printf("No syntax errors: All delimiters are balanced.\n");
    }
}

int main() {
    char code[MAX];
    
    printf("Enter the code: \n");
    fgets(code, MAX, stdin);
    
    checkSyntax(code);
    
    return 0;
}

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------










