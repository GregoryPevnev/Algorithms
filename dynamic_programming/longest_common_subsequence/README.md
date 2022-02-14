## House Robber

Reference: https://leetcode.com/problems/longest-common-subsequence/

Complexity: O(N * M), where N and M are the lengths of two strings.


### State

#### Variables

The state can be represented by the starting-position / current-position
within each corresponding string.

#### Table

Having 2 dimensions, one for each position of the corresponding string:
1. Position within the first string (starting / current)
2. Position within the second string (starting / current)

Range: Both positions and their respective dimensions depend on the
length of their respective strings.


### Logic

#### Function

Finding the LCS of two substrings which start in the given original
strings at the specified positions - positions of starts of strings.
One for each string in addition to strings themselves.

#### Relation

There are two possible cases when considering the two substrings
that got received from the starting-positions of the original
strings:
1. Their first characters match: The length of LCS is increased and both
positions are moved by one.
2. Their first characters do NOT match: Having to consider two
possibilities and choose the one that produces the longest subsequence
   1. A match is going to be found when a character from the first
      string is skipped - Moving the position of the first string
   2. A match is going to be found when a character from the second
      string is skipped - Moving the position of the second string

#### Base-Cases

There is just one Base-Case: Either of the positions have gone out of
bounds - there cannot be any common characters
