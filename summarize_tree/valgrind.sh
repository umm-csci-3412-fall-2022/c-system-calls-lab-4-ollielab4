#! /usr/bin/env bash

./compileTest.sh $(basename $1 .c)
valgrind --leak-check=full ./$(basename $1 .c)_test
