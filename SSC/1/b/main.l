%{
    #include "main.tab.h"
%}

%%

[0-9]+ {yylval.value = atof(yytext);return num;}
[+*/\-()] {return yytext[0];}
[\n] return yytext[0];

%%

int yywrap() { return 1; }