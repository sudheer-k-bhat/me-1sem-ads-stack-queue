#include <assert.h>

#include "symbol-balancing.h"

void test_symbol_balancing(){
    char* expr1 = "a = (b + c)";
    char* expr2 = "a = (b + c) + (d + e)";
    char* expr3 = "a = (b + (c * d))";
    char* expr4 = "a = (b + ((c * d))";

    BalanceResult result;

    is_well_formed(expr1, &result);
    assert(result.status == BALANCED);

    is_well_formed(expr2, &result);
    assert(result.status == BALANCED);

    is_well_formed(expr3, &result);
    assert(result.status == BALANCED);

    is_well_formed(expr4, &result);
    assert(result.status == NOT_BALANCED);
}