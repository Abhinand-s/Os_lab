#!/bin/bash

addition() {
    echo "Enter 2 numbers"
    read a b
    result=$((a + b))
    echo "Result: $result"
}

subtraction() {
    echo "Enter 2 numbers"
    read a b
    result=$((a - b))
    echo "Result: $result"
}

multiplication() {
    echo "Enter 2 numbers"
    read a b
    result=$((a * b))
    echo "Result: $result"
}

division() {
    echo "Enter 2 numbers"
    read a b
    result=$((a / b))
    echo "Result: $result"
}

while true; do
    echo "Select an option:"
    echo "1. Add"
    echo "2. Subtract"
    echo "3. Multiply"
    echo "4. Divide"
    echo "5. Exit"
    
    read choice
    
    case $choice in
        1)
            addition
            ;;
        2)
            subtraction
            ;;
        3)
            multiplication
            ;;
        4)
            division
            ;;
        5)
            exit 0
            ;;
        *)
            echo "Invalid option"
            ;;
    esac
done
