## House Robber

Reference: https://leetcode.com/problems/house-robber/

Complexity: O(N), where N is the number of houses


### State

#### Variables

The state depends entirely on the position of the starting house
that is being considered for robbing (not necessary going to be robbed).

#### Table

Has just a single dimension for representing the position of
the starting house from which the robbing is going to begin.

Input: Starting house from which to start robbing

Output: Total amount that can be robbed when
starting from the given house


### Logic

#### Function

Providing the total amount that can be robbed when starting
from a certain house (considering - NOT necessarily robbing).

This allows finding out what is the maximum amount that can be robbed
from all houses, when starting from the very first one.

#### Relation

When considering how to maximize the amount robbed, we have two cases:
1. Robbing the current house and going to the one after the next
2. Skipping the current house and going to the next

The maximum for a given starting position takes the fact that the very
starting house could be skipped - represents the maximum just for being
included into the total sequence of robberies considerations.

#### Base-Cases

The last house: The only way to maximize the robbed amount is to just
rob it - Setting the maximum to its own amount.

The house before the very last one: Can either be
1. Included, and the last house be skipped
2. Excluded, and the last house be robbed

Choosing the most optimal option for the house before the last one
based on the total amount that can be robbed - choosing the maximum
between the two.
