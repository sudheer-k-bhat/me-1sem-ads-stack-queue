#include <assert.h>

#include "stack-using-single-q-test-suite.h"

void test_stack_using_single_q(){
    Queue stk = stack1q_new();
    Queue* stack = &stk;

    StackResult result;
    stack1q_push(stack, 1, &result);
    stack1q_push(stack, 2, &result);
    stack1q_push(stack, 3, &result);
    stack1q_push(stack, 4, &result);

    stack1q_pop(stack, &result);
    assert(result.status == STACK_OK && result.data == 4);
}