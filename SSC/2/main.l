%{
    #include "main.tab.h"
%}

%%

[a] return a;
[b] return b;
[\n] return yytext[0];
. return yytext[0];

%%

int yywrap(){
    return 1;
}