#include <stdlib.h>
#include <stdio.h>

#include "postfix.h"
#include "stack.h"

static void extract_operand(Stack* stack, int32_t* operand){
    StackResult stack_result;
    stack = stack_peek(stack, &stack_result);
    if(stack_result.data != '+'){
        stack = stack_pop(stack, &stack_result);
        char res[2] = {stack_result.data, '\0'};
        *operand = atoi(res);
    }
}

void eval_postfix(char* expression, PostFixResult* result){
    char* t;
    Stack stk = stack_new();
    Stack* stack = &stk;
    StackResult stack_result;
    for(t = expression; *t != '\0'; t++){
        char symbol = t[0];
        // TODO assuming only numbers & arithmetic operators (+ for now)
        if(symbol == '+'){
            int32_t operand1;
            extract_operand(stack, &operand1);

            t++;
            char op2 = t[0];
            char res[2] = {op2, '\0'};
            int32_t operand2 = atoi(res);

            int32_t op_result = operand1 + operand2;
            printf("%d = %d + %d", op_result, operand1, operand2);
            char op_result_char[2];
            sprintf(op_result_char, "%d", op_result);
            stack_push(stack, op_result_char[0], &stack_result);
        }else{
            stack_push(stack, symbol, &stack_result);
        }
    }
    stack_pop(stack, &stack_result);
    result->result = stack_result.data;
}