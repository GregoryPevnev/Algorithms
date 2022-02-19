## Duplicating Zeroes

Reference: https://leetcode.com/problems/duplicate-zeros/

Tags: Greedy, Sequence, Array, Two Pointers


### Approach

Keeping two pointers moving in the same direction from the beginning:
1. Deduplicated-Pointer - Points to the head of the deduplicated
   sub-array, which only stores the deduplicated numbers.
2. Original-Pointer - Points and iterates over the actual array and
   inspects values, comparing them to the head-value / current-value of
   the Deduplicated-Pointer.
   
#### Iteration

Moving the Original-Pointer until it reaches the new distinct numbers,
before copying it and moving on.


### Patterns

TODO: Removing items / left-shifting

Array-Modification: Performing in-place changes with shifting, moving,
copying for deletions efficiently using
* Forwards iteration
* Two pointers (from the front)

Array-Deletion: Copying / Moving values from front to back in order
to perform left-shifting for all the elements of interest,
and not just one by one.

Two-Pointers:
1. Copying to the destination - **Capacity**.
2. Copying from the source - **Logical-End / Length**.
