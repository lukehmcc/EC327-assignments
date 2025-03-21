#!/bin/bash

# Compile the .cpp file into an executable
g++ -std=c++17 -lgtest -lgtest_main -pthread -o main *.cpp
# Check if compilation was successful
if [[ $? -eq 0 ]]; then
  echo "Running main..."
  ./"main"
  echo ""
else
  echo "Compilation of main failed."
fi
