## House Robber

Reference: https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/

Complexity: O(M^2), where M is the number of Multipliers.
The number of the actual numbers does NOT matter.

Important: This problem is tricking into
* Using too many State-Variables: 3 could be replaced by 2 (Inferred).
* Using ranges that are too large: Could be using smaller sub-ranges.


### State

#### Variables

Any sub-problem for finding any specific max-score can be described by
1. Start-Pointer - Points to the start of the considered sub-array.
2. End-Pointer - Points to the end of the considered sub-array.
3. Counter - Total count of numbers and multipliers calculated so far.

Inferring: Time and space complexity can be optimized by inferring
End-Pointer from the Start-Pointer and the Counter, instead of keeping
it as a distinct State-Variable.
````

End-Index = Size - 1

End-Pointer-Index = End-Index - # of times End-Pointer was moved

# of times End-Pointer was moved = # of times Start-Pointer was NOT

# of times Start-Pointer was NOT moved = Counter - Start-Pointer-Index
   - Should have been identical otherwise (If it WAS moved every time)
   
End-Pointer-Index = Size - 1 - (Counter - Start-Pointer-Index)

````

#### Table

Having only 2 dimensions instead of 3 by inferring End-Pointer-Index:
1. Start-Pointer-Index
2. Counter

Range: Both dimensions can have the size of the # of Multipliers,
since the Start-Pointer can never exceed the # of Multipliers
(one to one at most).

Size: Depends entirely on the number of Multipliers


### Logic

#### Function

Finding the maximum score that can be calculated from specific
numbers and multipliers where
* Numbers are described as a sub-array of numbers with Start-Pointer and
End-Pointer.
* Multipliers are described by a sub-sequence that starts from
the Counter (already had a certain number of multipliers used).

#### Relation

There are two possible ways a sub-array can have its Score maximized:
1. Multiplying the Start-Pointer and moving the Start-Pointer-Index
2. Multiplying the End-Pointer and moving the End-Pointer-Index

The best possible score is chosen from both cases

#### Base-Cases

There is just one Base-Case: All multipliers were used up - meaning
that the Score can no longer be increased
