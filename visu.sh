#!/bin/bash
# the arg has to be like "0..5" or "-100..100"
python3 pyviz.py `ruby -e "puts ($1).to_a.shuffle.join(' ')"`