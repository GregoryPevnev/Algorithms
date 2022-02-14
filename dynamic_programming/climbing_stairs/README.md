## Climbing Stairs

Complexity: O(N), where N is the number of steps on the stairs

Reference: https://leetcode.com/problems/min-cost-climbing-stairs/


### State

#### Variables

The only relevant state is the current step

Single variable: current step - Initialized to
either first (index=0) or second (index=1) step

#### Table

One-Dimensional table is required for
the single state-variable (current-step)

Input: Current step

Output: Minimum cost from the specified current step (Including it)


### Logic

#### Function

Finding the minimum cost of reaching the top when starting from a
specific step / current-step

#### Relation

The minimum cost for reaching the top can be reached through either
1. The step one position ahead (One step is made)
2. The step two positions ahead (Two steps are made)

In both cases, the cost of the current step is included

#### Base-Cases

There is only a single base-case - the top is reached, which happens
when the index is out of bounds of the stairs

Alternatively: The last two steps have their own cost
(The top can be reached from them in a single step or two steps)
