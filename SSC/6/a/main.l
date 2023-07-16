%{
    #include <stdio.h>
    #include <stdlib.h>
    int sl = 0, ml = 0;
%}

%%

"//".* {sl++;}
"/*"([^*]|"*"[^/])*"*/" {ml++;}
. {fprintf(yyout, "%s", yytext);}
[\n] {fprintf(yyout, "\n");}

%%

int main(){
    yyin = fopen("main.c", "r");
    yyout = fopen("output.c", "w");

    if(!yyin || !yyout) exit(-1);
    yylex();
}

int yywrap() { return 1;}