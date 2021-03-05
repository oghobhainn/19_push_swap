#!/bin/bash
gcc srcs_checker/*.c shared/*.c -o checker
chmod +x checker
gcc srcs_push_swap/*.c shared/*.c -o push_swap
chmod +x push_swap
ARG=$1
./push_swap $ARG | ./checker $ARG