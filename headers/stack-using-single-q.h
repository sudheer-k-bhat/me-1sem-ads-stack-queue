#include "queue.h"
#include "stack.h"

Queue stack1q_new();
Queue* stack1q_push(Queue* stack, STACK_CONTENT_TYPE data, StackResult* result);
Queue* stack1q_pop(Queue* stack, StackResult* result);
Queue* stack1q_peek(Queue* stack, StackResult* result);
STACK_STATUS stack1q_empty(const Queue* stack);
STACK_STATUS stack1q_full(const Queue* stack);