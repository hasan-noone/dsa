#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_STACK 100
#define MAX_EXPR_LENGTH 256

// Stack to hold intermediate expressions
char stack[MAX_STACK][MAX_EXPR_LENGTH];
int top = -1;

// Push a string onto the stack
void push(const char *str) {
    top++;
    strcpy(stack[top], str);
}

// Pop a string from the stack
char* pop() {
    return stack[top--];
}

// Convert a postfix expression to an infix expression using a static stack
char* post2inFix(const char* s) {
    // Reset the stack for each new conversion
    top = -1;
    
    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];
        
        // If the character is an operand, push it as a string
        if (isalpha(c) || isdigit(c)) {
            char operand[2] = { c, '\0' };
            push(operand);
        }
        // If the character is an operator, pop two operands and form a new expression
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            char *right = pop();
            char *left  = pop();
            char temp[MAX_EXPR_LENGTH];
            // Format: (left operator right)
            snprintf(temp, MAX_EXPR_LENGTH, "(%s%c%s)", left, c, right);
            push(temp);
        }
    }
    
    return pop();
}

int main() {
    printf("%s\n", post2inFix("21+3*"));      // Should print: ((2+1)*3)
    printf("%s\n", post2inFix("abc*+"));       // Should print: (a+(b*c))
    printf("%s\n", post2inFix("ab*cd/+"));      // Should print: ((a*b)+(c/d))
    
    return 0;
}
