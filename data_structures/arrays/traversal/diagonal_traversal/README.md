## Diagonal Traversal

Traversing the matrix diagonal-by-diagonal in a specific order and
outputting the traversed elements in the process.


### Approaches

The traversal can be achieved through
1. Simulation - Iterating / Traversing through the matrix in the same
   manner as required for the result and outputting each item in the
   process. Requires coming up with a proper **walking patten** in order
   to visit all cells in the correct order.
2. Matching - Using the diagonal-properties in order to determine which
   diagonal each item belongs to and then output the items based on
   which diagonals they belong to.

   
### Simulation

Performing the simulation of the walking by traversing the items in
the exact same order. This is NOT flexible and depends on too many
factors, which can change:
1. Direction to move along the diagonals.
2. Number of columns in each row (does NOT work for uneven rows).
3. Additional logic and constraints.

**Important**: This makes simulation / walking pattern solutions
hard to reuse and implement.


### Matching

Remains the same across all kinds of traversals required and can be
reused as much as possible - works perfectly for all kinds of traversals
and sizes of rows / columns.

#### Properties

Diagonals in a 2D-Array have the following characteristics:
- The total number of diagonals equal to ```Rows + Columns - 1```.
  This allows calculating the total number of diagonals to traverse.
- All positions / cells located on the same diagonal have the same
  sum of Row-Number and Column-Number. With this in mind, the number
  of Diagonal, which an item at a specific position belongs
  to can be calculated through the following formula:
  ```Diagonal-Number = Row-Number + Column-Number```.
- Depending on the ordering of items within a diagonal, the order in
  which the items are added to a specific diagonal set is either direct
  or reverse:
  - Top-Right: The ordering is direct (first rows come first).
  - Bottom-Left: The ordering is reverse (last rows come first).

#### Traversal

The order in which the positions in the incoming 2D-Array are
iterated through / traversed depends on the desired ordering within
the diagonals - Top-Right or Bottom-Left.

However, it is NOT that important, since the diagonal-sets can be
reversed for the output specifically if needed.
