#include <assert.h>
#include <stdint.h>
#include <stdlib.h>

#include "stack.h"

static Node *_get_new_node(STACK_CONTENT_TYPE val)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = val;
    node->next = NULL;
    return node;
}

Stack stack_new(){
    Stack stack = {NULL, 0};
    return stack;
}

STACK_STATUS stack_empty(const Stack* stack){
    assert(stack != NULL);
    return stack->length == 0;
}

Stack* stack_push(Stack* stack, STACK_CONTENT_TYPE el, StackResult* result){
    assert(stack != NULL);
    Node* node = _get_new_node(el);
    node->next = stack->top;
    stack->top = node;
    ++stack->length;
    result->data = el;
    result->status = STACK_OK;
    return stack;
}

Stack* stack_pop(Stack* stack, StackResult* result){
    assert(stack != NULL);
    if(!stack_empty(stack)){
        result->data = stack->top->data;
        result->status = STACK_OK;
        
        Node* temp = stack->top;
        stack->top = stack->top->next;
        free(temp);
        --stack->length;
    }else{
        result->status = STACK_EMPTY;
    }
    return stack;
}

Stack* stack_peek(Stack* stack, StackResult* result){
    assert(stack != NULL);
    if(!stack_empty(stack)){
        result->data = stack->top->data;
        result->status = STACK_OK;
    }else{
        result->status = STACK_EMPTY;
    }
    return stack;
}