#include <assert.h>

#include "symbol-balancing.h"

void test_symbol_balancing1(){
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

void test_symbol_balancing2(){

    char* expr1 = "a = [b + c]";
    char* expr2 = "a = [b + c] + [d + e]";
    char* expr3 = "a = [b + [c * d]]";
    char* expr4 = "a = [b + [[c * d]]";

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

void test_symbol_balancing3(){

    char* expr1 = "a = {b + c}";
    char* expr2 = "a = {b + c} + {d + e}";
    char* expr3 = "a = {b + {c * d}}";
    char* expr4 = "a = {b + {{c * d}}";

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

void test_symbol_balancing4(){

    char* expr1 = "a = (b + {[c * d]})";
    char* expr2 = "a = (b + c) + {d + e}";
    char* expr3 = "a = [b + {c * d}]";
    char* expr4 = "a = {b + {[c * d]}";

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

void test_symbol_balancing(){
    test_symbol_balancing1();
    test_symbol_balancing2();
    test_symbol_balancing3();
    test_symbol_balancing4();
}