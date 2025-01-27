#!/bin/bash

# Test valid inputs
echo "Testing valid inputs..."
ARG="42"; ./push_swap $ARG | ./checker $ARG
ARG="2 1"; ./push_swap $ARG | ./checker $ARG
ARG="1 3 2"; ./push_swap $ARG | ./checker $ARG
ARG="5 3 1 4 2"; ./push_swap $ARG | ./checker $ARG
ARG="1 2 3 4 5"; ./push_swap $ARG | ./checker $ARG
ARG="5 4 3 2 1"; ./push_swap $ARG | ./checker $ARG
ARG="-1 -3 -2"; ./push_swap $ARG | ./checker $ARG
ARG="-2147483648 2147483647"; ./push_swap $ARG | ./checker $ARG

# Test invalid inputs
echo "Testing invalid inputs..."
ARG="1 2 abc 4"; ./push_swap $ARG | ./checker $ARG
ARG="1 2 3 2"; ./push_swap $ARG | ./checker $ARG
ARG=""; ./push_swap $ARG | ./checker $ARG
ARG="   "; ./push_swap $ARG | ./checker $ARG
ARG="2147483648"; ./push_swap $ARG | ./checker $ARG
ARG="-2147483649"; ./push_swap $ARG | ./checker $ARG
ARG="1 2 three 4"; ./push_swap $ARG | ./checker $ARG

# Test performance
echo "Testing performance..."
ARG=$(shuf -i 1-100 -n 100 | tr '\n' ' '); ./push_swap $ARG | ./checker $ARG
ARG=$(shuf -i 1-500 -n 500 | tr '\n' ' '); ./push_swap $ARG | ./checker $ARG
ARG=$(seq 1 100 | tr '\n' ' '); ./push_swap $ARG | ./checker $ARG
ARG=$(seq 100 -1 1 | tr '\n' ' '); ./push_swap $ARG | ./checker $ARG

echo "All tests completed."
