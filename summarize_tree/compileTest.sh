#! /usr/bin/env bash


g++ -Wall -g -o $(basename $1 .c)_test $(basename $1 .c).c $(basename $1 .c)_test.cpp -lgtest -pthread -std=c++0x
