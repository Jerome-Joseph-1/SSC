#include <stdio.h>
#include <string.h>

char stack[100], input[100];

void disp(int stk, int inp){
    for (int i = 0; i < stk + 1; i++)
    {
        printf("%c", stack[i]);
    }

    printf("\t\t");

    for (int i = inp; input[i] != '\0'; i++)
    {
        printf("%c", input[i]);
    }
    printf("\n");
    
}

int main(){
    int stackPointer = 0, inputPointer = 0;

    char m[2][3][4] = {
        {"aBa", "E", "E"},
        {"n", "bB", "E"},
    };

    int size[2][3] = {
        {3, 1, 1},
        {1, 2, 1}
    };

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%s\t", m[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    printf("Enter the string : ");
    scanf("%s", input);
    strcpy(stack, "$A");
    strcat(input, "$");
    stackPointer = 1;
    
    disp(stackPointer, inputPointer);
    while (stack[stackPointer] != '$' && input[inputPointer] != '$') {
        if (stack[stackPointer] == input[inputPointer])
        {
            stackPointer--;
            inputPointer++;
            disp(stackPointer, inputPointer);
        }

        int row, col;
        switch (stack[stackPointer])
        {
        case 'A':
            row = 0;
            break;

        case 'B':
            row = 1;
            break;
        
        default:
            if (stack[stackPointer] == '$' && input[inputPointer] == '$')
            {
                printf("Successful Parsing!!\n");
            } else {
                printf("Un-successful Parsing!!\n");
            }
            return 0;
        }

        switch (input[inputPointer])
        {
        case 'a':
            col = 0;
            break;
        
        case 'b':
            col = 1;
            break;
        
        case '$':
            col = 2;
            break;
        
        default:
            printf("Invalid Terminal!!\n");
            return 0;
        }


        if(m[row][col][0] == input[inputPointer]) {
            for (int k = size[row][col] - 1;k > -1; k--)
            {
                stack[stackPointer++] = m[row][col][k];
            }
            stackPointer--;
        }

        if(m[row][col][0] == 'E') {
            printf("Un-successful Parsing!!\n");
            return 0;
        }

        if (m[row][col][0] == 'n') stackPointer--;
        
        disp(stackPointer, inputPointer);
    }
    
}