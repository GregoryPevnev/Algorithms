## Minimum Size Subarray Sum

Reference: https://leetcode.com/problems/minimum-size-subarray-sum/

Tags: Greedy, Sequence, Sliding Window, Sum

Complexity: O(N) - Single Pass

Approach:
* **Sliding-Window** only works here due to the fact that the sequence
  does NOT contain negative values, which makes it possible to make
  predictions / assumptions:
  * The sum is going to keep increasing monotonically
  * Adding an element always increases the current sum
  * Removing an element always decreases the current sum
* **Prefix-Sum** does not work here due to the fact that we are NOT
  searching for EXACT sums (could be greater).
