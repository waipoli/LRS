#!/bin/bash
for file in *; do
  if [[ "$file" == *.* ]]; then
    echo ""
  else
    rm "$file" - rf
  fi

done
