## Delete and Earn

Reference: https://leetcode.com/problems/delete-and-earn/

Complexity: O(N + M), where
* N is the number of all numbers 
* M is the number of distinct numbers


### Approach

Including a single digit does not make sense - either including
all occurrences of the digit, or not including all of them at all.
Which is why it makes no sense to consider individual digits for
inclusion - total sums of all their occurrences should be considered
instead.

Afterwards, we are checking for the maximum possible earnings that can
be made when starting earning / deleting from a specific number as a
starting point.

#### Step 1

Counting the total sums of all occurrences of specific digits to work
with their totals, instead of their instances

##### Step 2

Using Dynamic Programming for checking for the maximal earnings.


### State

#### Variables

The only state variable is the starting number / current number from
which the earnings are considered.

Initially, it is initialized to either 1 or the maximum number and from
there it is moved forwards / backwards until the maximum number or 1
is reached (having a starting point from which all other numbers were
considered for inclusion / deletion / earning).

#### Table

Has just a single dimension for representing the position of
the starting number from which th earning is going to begin.

Input: Starting number from which to start earning.

Output: Maximum earnings that can be made with the specified number
as the starting point (NOT necessarily included).


### Logic

#### Function

Providing the total earnings that can be made when starting
from a certain number (NOT necessarily including / deleting).

This allows finding out what is the maximum earnings that can be made
from all numbers that are before / after the current one.

#### Relation

When considering how to maximize the earnings, we have two cases:
1. Deleting and earning the number and going to number+2
2. Skipping the number and going to number+1 directly

The maximum for a given starting position takes the fact that the very
starting house could be skipped - represents the maximum just for being
included into the total sequence of robberies considerations.

Important: This just follows the simplified Delete-And-Earn logic

#### Base-Cases

The last number: The only way to maximize the earnings is to just
delete it / include it - Setting the maximum to its own amount.

The number before the very last one: Can either be
1. Included, and the last number be skipped
2. Excluded, and the last number be deleted and earned

Choosing the most optimal option for the house before the last one
based on the total amount that can be robbed - choosing the maximum
between the two.
