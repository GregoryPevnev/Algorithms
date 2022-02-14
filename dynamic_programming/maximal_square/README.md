## Maximal Square

Reference: https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/

Guide: https://leetcode.com/problems/maximal-square/solution/

Time Complexity: O([Rows] * [Columns]), where [Rows] and [Columns] describe the input matrix dimensions.

Space Complexity: O([Columns]), where [Columns] describes the input matrix dimension.
The number of the actual numbers does NOT matter.

Important: The solution for this problem can be optimized by only storing
square sizes for the previous and the current rows instead of all, since
only the current and the previous row are accessed at a time.