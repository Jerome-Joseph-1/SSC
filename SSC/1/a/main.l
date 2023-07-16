%{
    #include<stdio.h>
    int op = 0, digits = 0, brackets = 0; 
%}

digit [0-9]
letter_ [a-zA-Z_]

%%
{letter_}({letter_}|{digit})* {printf("Identifier: %s\n", yytext); digits++;}
{digit}+ {digits++;}
[(] {brackets++;}
[)] {if(!brackets) return 0;brackets--;}
[+*/\-] {op++;}
[\n] return 0;
%%

int main(){
    printf(":Started Program:\n\nEnter an Expression : ");
    yylex();
    if(op == digits - 1 && !brackets) {
        printf("Valid Expression.\n");
    } else {
        printf("Invalid Expression.\n");
    }
    return 0;
}

int yywrap(){
    return 1;
}