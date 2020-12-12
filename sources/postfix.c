#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <ctype.h>

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
        if(t[0] == ' ') continue;
        assert(t[0] == '+' || isdigit(t[0]));
        // TODO assuming only numbers & arithmetic operators (+ for now)
        if(t[0] == '+'){
            stack = stack_pop(stack, &stack_result);
            int32_t operand1 = stack_result.data;

            t++;
            int32_t num = 0;
            while(isdigit(t[0]) || t[0] == ' '){
                char token = t[0];
                t++;
                if(token == ' '){
                    continue;
                }else{
                    num = num * 10 + (int32_t) (token - '0');
                }
            }
            int32_t operand2 = num;
            t--;

            int32_t op_result = operand1 + operand2;
            printf("%d = %d + %d\n", op_result, operand1, operand2);
            stack_push(stack, op_result, &stack_result);
        }else{
            int32_t num = 0;
            while(isdigit(t[0]) || t[0] == ' '){
                char token = t[0];
                t++;
                if(token == ' '){
                    continue;
                }else{
                    num = num * 10 + (int32_t) (token - '0');
                }
            }
            t--;
            stack_push(stack, num, &stack_result);
        }
    }
    stack_pop(stack, &stack_result);
    result->result = stack_result.data;
}