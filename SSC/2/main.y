%{
    #include <stdio.h>
    #include <stdlib.h>

    extern int yylex();
    int yyerror();
%}

%token a b

%%

S : A B '\n' {
    printf("Successful Parsing!!\n");
    exit(0);
};
A : a A | ;
B : b;

%%

int main(){
    printf("Enter the string [ (a)*b ] [ eg: aaa..b] : ");
    yyparse();
}

int yyerror(){
    printf("String Rejected\n");
    exit(0);
}