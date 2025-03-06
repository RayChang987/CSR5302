#!/bin/bash

echo "Your $(grep "Answer" ./outputs/case07_out)"
echo "Expected $(head -n 1 ./cases/case07_ans)"
if [[ "$(grep "Answer" ./outputs/case07_out)" != "$(head -n 1 ./cases/case07_ans)" ]]; then
  echo "Error: grep output does not match the first line of file2.txt"
  exit 1
else
  echo "Test 07 passed!"
fi
