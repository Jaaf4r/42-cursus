#!/bin/bash

# Test valid inputs
echo "Testing valid inputs..."
./push_swap 42
./push_swap 2 1
./push_swap 1 3 2
./push_swap 5 3 1 4 2
./push_swap 1 2 3 4 5
./push_swap 5 4 3 2 1
./push_swap -1 -3 -2
./push_swap -2147483648 2147483647

# Test invalid inputs
echo "Testing invalid inputs..."
./push_swap 1 2 abc 4
./push_swap 1 2 3 2
./push_swap ""
./push_swap "   "
./push_swap 2147483648
./push_swap -2147483649
./push_swap 1 2 three 4

# Test performance
echo "Testing performance..."
ARG=$(shuf -i 1-100 -n 100 | tr '\n' ' '); ./push_swap $ARG | wc -l
ARG=$(shuf -i 1-500 -n 500 | tr '\n' ' '); ./push_swap $ARG | wc -l
ARG=$(seq 1 100 | tr '\n' ' '); ./push_swap $ARG | wc -l
ARG=$(seq 100 -1 1 | tr '\n' ' '); ./push_swap $ARG | wc -l

echo "All tests completed."
