## Diagonal Traversal of an Uneven 2D Array

Reference: https://leetcode.com/problems/diagonal-traverse-ii

Tags: Array, Traversal, Matching


### Approach

Impossible to solve with a **Simulation / Walk Pattern**, due to the rows
having different sizes one from another (impossible to make predictions
and move the pointers properly).

Instead, the problem is solved by **Matching Diagonals** in order to
make sets of items by their diagonal-positions and outputting all of them.
