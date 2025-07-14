#!/bin/bash


cd 'Task-4/tests'
pwd
g++ ./algorithms-KGood.cpp -o KGood.exe

for ((i=1; i<=3; i++)); do
    test_input=$(head -n 2 "test-${i}.txt")
    expected_output=$(tail -n 1 "test-${i}.txt")
    actual_output=$(echo -e "$test_input" | ./KGood.exe)
    
    if [ "$actual_output" = "$expected_output" ]; then
        echo
        echo "Test-${i}: success"
        echo "Input:"
        echo "$test_input"
        echo "Output: $actual_output"
        
    else 
        echo
        echo "Test-${i}: fail"
        echo "Output: $actual_output"
        echo "Expected output: $expected_output"
        break
    fi
done
