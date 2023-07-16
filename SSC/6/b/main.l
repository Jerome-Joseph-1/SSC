%{
    #include "main.tab.h"
%}

letter_ [a-zA-Z_]
digit [0-9]
string \"([^"])*\"

%%

int|float|bool|unsigned|return|typedef|double {printf("Keyword\t:%s\n", yytext); return KEY;}
{string} {printf("String\t\t:%s\n", yytext);}
{letter_}({letter_}|{digit})* {printf("Identifier\t:%s\n", yytext); return ID;}
{digit}+ {printf("Number\t\t:%s\n", yytext); return NUM;}
[+*/\-%<>=] {printf("Operator\t:%s\n", yytext); return OP;}
. ;
%%

int yywrap(){ return 1; }