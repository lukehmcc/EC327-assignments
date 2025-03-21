#!/bin/bash

# Compile the code
g++ -o main *.cpp

# Check if compilation was successful
if [ $? -eq 0 ]; then
  # Run the compiled program
  ./main
else
  echo "Compilation failed."
fi
