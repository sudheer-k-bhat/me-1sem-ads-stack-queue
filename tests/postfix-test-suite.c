#include <assert.h>

#include "postfix-test-suite.h"
#include "postfix.h"

void test_postfix1(){
    char* expression = "1+2";
    PostFixResult result;
    eval_postfix(expression, &result);
    assert(result.result == 3);
}

void test_postfix2(){
    char* expression = "10 + 22";
    PostFixResult result;
    eval_postfix(expression, &result);
    assert(result.result == 32);
}

void test_postfix3(){
    char* expression = "10 + 22";
    PostFixResult result;
    eval_postfix(expression, &result);
    assert(result.result == 32);

    expression = "22 - 12";
    eval_postfix(expression, &result);
    assert(result.result == 10);

    expression = "2 * 12";
    eval_postfix(expression, &result);
    assert(result.result == 24);

    expression = "22 / 11";
    eval_postfix(expression, &result);
    assert(result.result == 2);
}

void test_postfix(){
    test_postfix1();
    test_postfix2();
    test_postfix3();
}