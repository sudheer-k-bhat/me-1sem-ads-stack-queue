#!/bin/sh
rm -rf bin/out
gcc -I headers/ \
lib/stack/stack.c \
lib/queue/queue.c \
sources/symbol-balancing.c tests/symbol-balancing-test-suite.c \
sources/postfix.c tests/postfix-test-suite.c \
sources/stack-using-single-q.c tests/stack-using-single-q-test-suite.c \
sources/main.c \
-o bin/out

bin/out