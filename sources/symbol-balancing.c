#include <stdint.h>
#include <stdio.h>

#include "symbol-balancing.h"
#include "stack.h"

static uint8_t _is_open_symbol(char token){
    return token == '(' || token == '[' || token == '{';
}

static uint8_t _is_close_symbol(char token){
    return token == ')' || token == ']' || token == '}';
}

static uint8_t _is_matching_symbol(char open_symbol, char close_symbol){
    return (open_symbol == '(' && close_symbol == ')')
        || (open_symbol == '[' && close_symbol == ']')
        || (open_symbol == '{' && close_symbol == '}');
}

void is_well_formed(char* expression, BalanceResult* result){
    Stack stk = stack_new();
    Stack *stack = &stk;
    char* t;
    StackResult stack_result;
    for (t = expression; *t != '\0'; t++)
    {
        char symbol = t[0];
        if(_is_open_symbol(symbol)){
            stack = stack_push(stack, symbol, &stack_result);
        }else if(_is_close_symbol(symbol)){
            stack = stack_peek(stack, &stack_result);
            if(_is_matching_symbol(stack_result.data, symbol)){
                stack = stack_pop(stack, &stack_result);
            }else{
                result->status = NOT_BALANCED;
                break;
            }
        }
    }
    if(stack_empty(stack) != STACK_EMPTY){
        result->status = NOT_BALANCED;
    }else{
        result->status = BALANCED;
    }
}