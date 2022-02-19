## Diagonal Traversal of an Even 2D Array

Reference: https://leetcode.com/problems/diagonal-traverse

Tags: Array, Traversal, Simulation, Matching


### Approach

Can be solved BOTH with
1. Finding an appropriate **Simulation / Walk Pattern**
   in order to traverse all the positions in rows and columns
   in a correct order, due to the fact that the 2D-Array forms a matrix -
   the number of columns in each row is equal.
2. Collecting the items into appropriate sets with **Matching Diagonals**
   and then populating the output based on the diagonal-ordering, which
   can be either Top-Right or Bottom-Left.
