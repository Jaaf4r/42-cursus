#!/usr/bin/env python3
import random
import subprocess
import os
from datetime import datetime

def generate_unique_numbers():
    numbers = random.sample(range(-2147483648, 2147483647), 500)
    return numbers

def test_push_swap(numbers):
    input_str = ' '.join(map(str, numbers))
    
    try:
        process = subprocess.Popen(['./push_swap'] + list(map(str, numbers)), 
                                 stdout=subprocess.PIPE,
                                 stderr=subprocess.PIPE)
        output, error = process.communicate()
        
        moves = len(output.decode().strip().split('\n'))
        return moves
    except Exception as e:
        print(f"Error running push_swap: {e}")
        return None

def save_failing_case(numbers, moves, test_number):
    if not os.path.exists('failing_cases'):
        os.makedirs('failing_cases')
    filename = f'failing_cases/fail_case_{test_number}_{moves}_moves.txt'
    with open(filename, 'w') as f:
        f.write(f"Number of moves: {moves}\n")
        f.write(f"Numbers: {' '.join(map(str, numbers))}\n")
    return filename

def main():
    print("Starting push_swap testing...")
    total_tests = 500
    failing_cases = 0
    max_moves_seen = 0
    
    for i in range(total_tests):
        numbers = generate_unique_numbers()
        moves = test_push_swap(numbers)
        
        if moves is None:
            print(f"Test {i+1} failed to execute")
            continue
            
        max_moves_seen = max(max_moves_seen, moves)
        
        print(f"Test {i+1}/{total_tests}: {moves} moves", end='\r')
        
        if moves > 5500:
            failing_cases += 1
            filename = save_failing_case(numbers, moves, i+1)
            print(f"\nTest {i+1} exceeded 5500 moves ({moves} moves)")
            print(f"Failing case saved to: {filename}")
    
    print("\n\nTesting completed!")
    print(f"Total tests run: {total_tests}")
    print(f"Number of cases exceeding 5500 moves: {failing_cases}")
    print(f"Maximum moves seen: {max_moves_seen}")

if __name__ == "__main__":
    main()