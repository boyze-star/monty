#include <stdio.h>
#include <stdlib.h>

/**
 * push - adds to stack and queue
 * @value: integer value passed as arguement
 *
 * Return: 0 (success), 1 (error)
 */
void push(int value)
{
    if (top == STACK_SIZE - 1) {
        fprintf(stderr, "Error: Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    stack[++top] = value;
}

/**
 * pall - does nothing
 *
 * Return: stack is empty, does nothing
 */
void pall()
{
    if (top == -1)
    {
        return;
    }

    for (int i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}
/**
 * main - entry point
 *
 * Return: nothing
 */
int main()
{
    char opcode[4];
    int value;

    while (scanf("%3s", opcode) != EOF) {
        if (strcmp(opcode, "push") == 0) {
            if (scanf("%d", &value) != 1) {
                fprintf(stderr, "Error: usage: push integer\n");
                exit(EXIT_FAILURE);
            }
            push(value);
        } else if (strcmp(opcode, "pall") == 0) {
            pall();
        } else {
            fprintf(stderr, "Error: Unknown opcode %s\n", opcode);
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}
