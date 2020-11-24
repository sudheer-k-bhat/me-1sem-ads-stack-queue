#include <stdint.h>
#include <stdio.h>

#include "symbol-balancing.h"
#include "stack.h"

void is_well_formed(char* expression, BalanceResult* result){
    Stack stk = stack_new();
    Stack *stack = &stk;
    char* t;
    StackResult stack_result;
    // printf("%s\n\n\n", expression);
    for (t = expression; *t != '\0'; t++)
    {
        char symbol = t[0];
        // printf("%c\n", symbol);
        if(symbol == '('){
            stack = stack_push(stack, symbol, &stack_result);
        }else if(symbol == ')'){
            stack = stack_peek(stack, &stack_result);
            if(stack_result.data != '('){
                result->status = NOT_BALANCED;
                break;
            }else{
                stack = stack_pop(stack, &stack_result);
            }
        }
    }
    if(stack_empty(stack) != STACK_EMPTY){
        result->status = NOT_BALANCED;
    }else{
        result->status = BALANCED;
    }
}