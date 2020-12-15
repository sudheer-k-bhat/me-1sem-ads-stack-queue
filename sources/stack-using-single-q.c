#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

#include "stack-using-single-q.h"

Queue stack1q_new(){
    Queue queue = {Q_LEN, 0, 0, 0, {0}};
    return queue;
}

STACK_STATUS stack1q_empty(const Queue* stack){
    assert(stack != NULL);
    return stack->count == 0 ? STACK_EMPTY : STACK_OK;
}

STACK_STATUS stack1q_full(const Queue* stack){
    assert(stack != NULL);
    return stack->count == stack->size ? STACK_FULL : STACK_OK;
}

Queue* stack1q_push(Queue* stack, STACK_CONTENT_TYPE data, StackResult* result){
    QueueResult q_res;
    uint32_t size = stack->count;
    stack = queue_add(stack, data, &q_res);
    for (uint32_t i = 0; i < size; i++)
    {
        stack = queue_delete(stack, &q_res);   
        stack = queue_add(stack, result->data, &q_res);
    }
    return stack;
}

Queue* stack1q_pop(Queue* stack, StackResult* result){
    QueueResult q_res;
    queue_delete(stack, &q_res);
    result->data = q_res.data;
    result->status = q_res.status == QUEUE_EMPTY ? STACK_EMPTY : q_res.status == QUEUE_FULL ? STACK_FULL : STACK_OK;
    return stack;
}