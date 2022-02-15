## Duplicating Zeroes

Reference: https://leetcode.com/problems/duplicate-zeros/

Tags: Greedy, Sequence, Array, Two Pointers


### Approach

Calculating the shifting of numbers to the right, that is going to be
caused by the duplication of zeroes and shifting the numbers to the
right in corresponding manner

1. Regular numbers just get copied over the shift
2. Zeroes get copied twice

The shift / gap between the numbers gets smaller with each duplicated
zero - keeping two pointers to track the location for copying numbers
to and from.

#### Step 1. Calculating the number of zeroes and non-zeroes

Iterating over the array and calculating all the encountered zero
and non-zero numbers.

Iteration: Taking the shifting factor / gap into account in order to
ensure that only the numbers that ACTUALLY get copied are included.

Edge-Case: Returning if there are no zeroes (no actions required).

#### Step 2. Calculating the copying pointers

Copy-To-Pointer: Pointing to the end of the array of numbers with
duplicates taken into account.
**It can be out of range which means that the last zero got cut
off midway through duplication (should be taken into consideration).**

Copy-From-Pointer: Points to the last number that is going to get copied
into the new version of the array with duplication considered.

#### Step 3. Copying the numbers

Edge-Case: If the [Copy-To-Pointer] is out of range, it means that
the last value is a 0, which got cut off midway through duplication.
**This means that it should just be copied once,
like a non-zero number.**

Iteration: Performing the copying with the gap / shift reducing between
the pointers (copying to and from).

### Patterns

Array-Insertion: Copying / Moving values from back to front in order
to perform shifting for all the elements of interest - not one by one.

Two-Pointers:
1. Copying to the destination / copying to (physical end).
2. Copying from the source / copying from (logical end).
