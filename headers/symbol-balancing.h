#ifndef SYMBOL_BALANCING_H
#define SYMBOL_BALANCING_H

typedef enum {
    BALANCED,
    NOT_BALANCED
}BalancingStatus;

typedef struct{
    BalancingStatus status;
    char* message;
}BalanceResult;

void is_well_formed(char* expression, BalanceResult* result);
#endif