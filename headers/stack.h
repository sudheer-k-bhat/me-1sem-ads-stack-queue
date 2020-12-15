#ifndef STACK_H
#define STACK_H
#include <stdint.h>

#ifndef STACK_CONTENT_TYPE
#define STACK_CONTENT_TYPE int32_t
#endif

typedef struct _node_ Node;
struct _node_
{
    STACK_CONTENT_TYPE data;
    Node *next;
};

typedef struct _stack_ Stack;
struct _stack_
{
    Node *top;
    uint32_t length;
};

typedef enum {
    STACK_OK,
    STACK_EMPTY,
    STACK_FULL
}STACK_STATUS;

typedef struct {
    STACK_CONTENT_TYPE data;
    STACK_STATUS status;
}StackResult;

Stack stack_new();
Stack* stack_push(Stack* stack, STACK_CONTENT_TYPE data, StackResult* result);
Stack* stack_pop(Stack* stack, StackResult* result);
Stack* stack_peek(Stack* stack, StackResult* result);
STACK_STATUS stack_empty(const Stack* stack);
#endif