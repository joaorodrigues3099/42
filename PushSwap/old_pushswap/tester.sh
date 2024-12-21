#!/bin/bash

# Check if the correct number of arguments are provided
if [ "$#" -ne 2 ]; then
    echo "Usage: ./tester <amount of tests> <with amount of numbers>"
    exit 1
fi

# Use the arguments as the number of tests and the number of random numbers per test
num_tests=$1
num_numbers=$2

# Initialize variables to track the max, min, and total line count
max_lines=0
min_lines=-1
total_lines=0

# Define the function to test the program
function test_program() {
    input=$1

    # Run the program with the input
    output=$(./push_swap "$input")

    # Count the number of lines in the output
    line_count=$(echo "$output" | wc -l)

    # Update the max, min, and total line count
    if (( line_count > max_lines )); then
        max_lines=$line_count
    fi
    if (( min_lines == -1 || line_count < min_lines )); then
        min_lines=$line_count
    fi
    total_lines=$((total_lines + line_count))
}

# Get the start time
start_time=$(date +%s)

# Generate random input numbers
for i in $(seq 1 "$num_tests")
do
    input=""
    for ((j=1; j<=num_numbers; j++))
    do
        while true; do
            # Generate a random number between -10000 and 10000
            num=$((RANDOM % 20001 - 10000))

            # Check if the number is already in the input string
            if [[ ! $input =~ $num ]]; then
                # If it's not, add it to the input string and break the loop
                input="$input $num"
                break
            fi
        done
    done
    test_program "$input"
done

# Get the end time
end_time=$(date +%s)

# Calculate the elapsed time
elapsed_time=$((end_time - start_time))

# Calculate the average line count
average_lines=$((total_lines / num_tests))

# Print the max, min, and average line count
echo "Max lines: $max_lines"
echo "Min lines: $min_lines"
echo "Average lines: $average_lines"
echo "Total lines: $total_lines"
echo "Elapsed time: $elapsed_time seconds"
