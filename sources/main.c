#include "symbol-balancing-test-suite.h"
#include "postfix-test-suite.h"
#include "stack-using-single-q-test-suite.h"

int main()
{
    test_symbol_balancing();
    test_postfix();
    test_stack_using_single_q();
    return 0;
}