#ifndef POSTFIX_H
#define POSTFIX_H

#include <stdint.h>

typedef struct{
    char result;
}PostFixResult;

void eval_postfix(char* expression, PostFixResult* result);

#endif