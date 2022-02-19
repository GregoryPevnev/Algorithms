## Finding sums from arrays

Reference: https://leetcode.com/problems/4sum-ii/

Tags: Greedy, Set, Counting, Unordered, Combinations.

### Complexity

#### Time

Approach 1: O(A * B * C + D), reduced to O(N^3 + N) - where N is the
length of all the arrays.

Approach 2: O(A * B + C * D), reduced to O(N^2 * 2) - where N is the
length of all the arrays.

#### Memory

Approach 1: O(N^3) in order to store all possible combinations of
**A**, **B** and **C**.

Approach 2: O(N^2) in order to store all possible combinations of
**A** and **B**.

### Approach

Approach: The only approach is to try all the possible sums of arrays
**A**, **B**, **C** and **D**, which can be done in the following ways:
1. Matching every possible item in **D** to a corresponding sum of
   **A**, **B** and **C** (arrays are chosen arbitrarily). Complexity is
   O(A * B * C + D), which gives O(N^3 + N) since all arrays are equal.
2. Matching every possible sum of **A** and **B** to every possible sum
   of **C** and **D** (chosen arbitrarily). Complexity is
   O(A * B + C * D), which gives O(N^2 * 2) since all arrays are equal.
   
Obviously, the second approach gives better performance and should be
used instead.
