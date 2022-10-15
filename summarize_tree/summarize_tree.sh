#! /usr/bin/env bash


find $1 -type d | wc -l | xargs printf "There were %d directories.\n"
find $1 -type f | wc -l | xargs printf "There were %d regular files.\n"
