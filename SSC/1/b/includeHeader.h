#ifndef INCLUDE_H_H
#define INCLUDE_H_H

#include<stdlib.h>

typedef union {
    float v;
} expType;

#define YYSTYPE expType

extern int yyerror();

#endif