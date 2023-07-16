%{
    #include <stdio.h>
    #include <stdlib.h>

    int yyerror();
    extern int yylex();

    int id = 0, num = 0, op = 0, key = 0; 
    extern FILE* yyin;
%}

%token ID NUM OP KEY

%%
S : ID S {id++;}
    | NUM S {num++;}
    | OP S {op++;}
    | KEY S {key++;}
    | KEY {key++;}
    | OP {op++;}
    | NUM {num++;}
    | ID {id++;};
%%

int main(){
    yyin = fopen("main.c", "r");
    if(!yyin) yyerror();
    yyparse();
    printf("\n\
Identifiers : %d\nNumbers : %d\nOperators : %d\nKeywords : %d\n\n", id, num, op, key);
}

int yyerror(){
    printf("Parse Faild\n");
    exit(0);
}