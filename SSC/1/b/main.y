%{
    #include <stdio.h>
    #include <stdlib.h>

    extern int yylex();
    int yyerror();
%}

%union {
    float value;
}

%token <value> num
%type <value> S
%type <value> EXP

%left '+' '-'
%left '*' '/'
%nonassoc UMINUS 

%%
S : EXP '\n' {
    printf("Value : %f\n", $$);
    exit(0);
};
EXP : EXP '+' EXP { $$ = $1 + $3;}
    | EXP '-' EXP { $$ = $1 - $3;}
    | EXP '*' EXP { $$ = $1 * $3;}
    | EXP '/' EXP { $$ = $1 / (($3)?$3:( yyerror(), 1 ));}
    | '(' EXP ')' %prec UMINUS { $$ = $2; }
    | '-' EXP %prec UMINUS { $$ = -$2;}
    | num {$$ = $1;}
    ;
%%

int main(){
    printf("Enter Expression : ");
    yyparse();
}

int yyerror(){
    printf("Error in parsing\n");
    exit(0);
}