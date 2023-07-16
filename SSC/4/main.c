#include <stdio.h>
#include <string.h>

char input[100], stack[100], message[100];
int inputPointer = 0, stackPointer = 0;
int count = 0, level = 0;
int len;

void disp(char* a, char* b, char* c) {
    printf("$%s\t%s$\t%s\n", a, b, c);
}

void check();

int main(){
    // print grammer 

    printf("Entter String : ");
    scanf("%s", input);
    disp(stack, input, " ");
    len = strlen(input);

    for (; inputPointer < len; inputPointer++, stackPointer++) {
        if (input[inputPointer] == 'i' && input[inputPointer + 1] == 'd') {
            input[inputPointer] = input[inputPointer + 1] = ' ';
            stack[stackPointer] = 'i';
            stack[stackPointer + 1] = 'd';
            stack[stackPointer + 2] = '\0';
            count += 1;
            disp(stack, input, "SHIFT id");
            check();
        }

        else if(input[inputPointer] == '+' || input[inputPointer] == '*') {
            stack[stackPointer] = input[inputPointer];
            stack[stackPointer + 1] = '\0';
            input[inputPointer] = ' ';

            count += 1;
            sprintf(message, "SHIFT %c", stack[stackPointer]);
            disp(stack, input, message);
            check();
        }

        else if(input[inputPointer] == '(' || input[inputPointer] == ')') {
            stack[stackPointer] = input[inputPointer];
            stack[stackPointer + 1] = '\0';
            input[inputPointer] = ' ';

            count += 1;
            sprintf(message, "SHIFT %c", stack[stackPointer]);
            if(stack[stackPointer] == '(') level += 1; else level -= 1;
            disp(stack, input, message);
            check();
        }

        else {
            printf("Invalid Character !!\n");
            return 0;
        }
    }

    if(count == 1 && stack[0] == 'E' && level == 0) {
        printf("Successful Parsing!!\n");
    } else {
        printf("Unn-Successful Parsing!!\n");
    }
    
}

/*
F -> id
T -> T * F
T -> F
E -> E + T
E -> T
F -> (E)
*/


void check(){
    int change = 0;
    for (int i = 0; i < len; i++)
    {
        if (stack[i] == 'i' && stack[i+1] == 'd')
        {
            change = 1;
            stack[i] = 'F';
            stack[i+1] = '\0';
            inputPointer++;
            disp(stack, input, "Reduce F -> id");
        }
    }

    for (int i = 0; i < len; i++)
    {
        if (stack[i] == 'T' && stack[i+1] == '*' && stack[i+2] == 'F')
        {
            change = 1;
            stack[i] = 'T';
            stack[i+1] = '\0';
            stack[i+2] = '\0';
            count -= 2;
            stackPointer -= 2;
            disp(stack, input, "Reduce T -> T * F");
        }
    }

    for (int i = 0; i < len; i++)
    {
        if (stack[i] == 'F')
        {
            change = 1;
            stack[i] = 'T';
            stack[i+1] = '\0';
            disp(stack, input, "Reduce T -> F");
        }
    }
    
    for (int i = 0; i < len; i++)
    {
        if (stack[i] == 'E' && stack[i+1] == '+' && stack[i+2] == 'T')
        {
            if (stack[i+3] == ')')
            {
                change = 1;
                stack[i] = 'E';
                stack[i+1] = ')';
                stack[i+2] = '\0';
                count -= 2;
                stackPointer -= 2;
                disp(stack, input, "Reduce E -> E + T");
            }

            else if (stack[i+3] != '*' && input[inputPointer + 1] != '*') {
                change = 1;
                stack[i] = 'E';
                stack[i+1] = '\0';
                stack[i+2] = '\0';
                count -= 2;
                stackPointer -= 2;
                disp(stack, input, "Reduce E -> E + T");
            }
        }
    }

    for (int i = 0; i < len; i++)
    {
        if (stack[i] == 'T' && (input[inputPointer + 1] == '+' || input[inputPointer + 1] == '\0'))
        {
            change = 1;
            stack[i] = 'E';
            stack[i+1] = '\0';
            disp(stack, input, "Reduce E -> T");
        }
    }

    for (int i = 0; i < len; i++)
    {
        if (stack[i] == '(' && stack[i+1] == 'E' && stack[i+2] == ')')
        {
            change = 1;
            stack[i] = 'F';
            stack[i+1] = '\0';
            stack[i+2] = '\0';
            count -= 2;
            stackPointer -= 2;
            disp(stack, input, "Reduce F -> ( E )");
        }
    }

    if(change) check();
}