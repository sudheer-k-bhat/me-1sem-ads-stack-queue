#include <assert.h>

#include "postfix-test-suite.h"
#include "postfix.h"

void test_postfix(){
    char* expression = "1+2";
    PostFixResult result;
    eval_postfix(expression, &result);
    assert(result.result == '3');
}