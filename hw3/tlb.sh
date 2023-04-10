#!/bin/bash

# compile the tlb program
gcc tlb.c -o tlb_measure

# iterate over the number of pages accessed
for pages in 1 2 4 8 16 32 64 128 256 512 1024 2048 4096 8192 16384
do
    # iterate over the number of trials
    for trials in 5, 10, 15, 20, 25, 30
    do
        # run the tlb_measure program and print the result to a file
        ./tlb_measure $pages $trials >> tlb_results.txt
        echo "-----------------------------------------" >> tlb_results.txt
    done
done