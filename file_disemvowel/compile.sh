#! /usr/bin/env bash


gcc -g -Wall -o $(basename $1 .c) $1
