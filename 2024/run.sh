#!/bin/bash

# Check if the parameter is provided
if [ -z "$1" ]; then
  echo "Usage: $0 <day_number>"
  exit 1
fi

# Extract the parameter
PARAM=$1

# Compile the files
g++ -o out "$PARAM/$PARAM.cpp" main.cpp

