#!/bin/sh
rm -rf bin/out
gcc -I headers/ \
sources/stack.c \
sources/symbol-balancing.c sources/symbol-balancing-test-suite.c \
sources/postfix.c sources/postfix-test-suite.c \
sources/main.c \
-o bin/out

bin/out