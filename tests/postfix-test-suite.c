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

void test_postfix(){
    test_postfix1();
    test_postfix2();
}