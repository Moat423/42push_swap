import subprocess
import random

def generate_random_numbers(count):
    return ' '.join(map(str, random.sample(range(-1000000, 1000000), count)))

def run_command(arg):
    push_swap = subprocess.run(f"./push_swap {arg}", shell=True, capture_output=True, text=True)
    checker = subprocess.run(f"./checker_linux {arg}", input=push_swap.stdout, shell=True, capture_output=True, text=True)
    line_count = push_swap.stdout.count('\n')
    return checker.stdout.strip(), line_count

def run_tests(num_count):
    min_count = float('inf')
    max_count = 0
    total_count = 0

    for i in range(50):
        arg = generate_random_numbers(num_count)
        checker_output, line_count = run_command(arg)
        
        min_count = min(min_count, line_count)
        max_count = max(max_count, line_count)
        total_count += line_count
        
        print(f"Run {i+1}: Checker output: {checker_output}, Line count: {line_count}")

    avg_count = total_count / 50

    print(f"\nResults for {num_count} numbers:")
    print(f"Minimum line count: {min_count}")
    print(f"Maximum line count: {max_count}")
    print(f"Average line count: {avg_count:.2f}")

print("Testing with 100 numbers:")
run_tests(100)

print("\n" + "="*50 + "\n")

print("Testing with 500 numbers:")
run_tests(500)

