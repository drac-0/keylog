#!/usr/bin/env bash
a=$(ls -lh /dev/input/by-path/ | grep kbd)
i=0
while true; do
  echo $a | grep -o event$i
  if [[ $? -eq 0 ]]; then
    sudo ./kl /dev/input/event$i
    clear
    exit 0
  fi
  ((i++))
done
