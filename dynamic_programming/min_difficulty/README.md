## Minimum Difficulty

Reference: https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/

Guide: https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/discuss/944828/Short-DP-solution-with-highly-detailed-step-by-step-explanation

Time Complexity: O([Days] * ([Jobs] - [Days])^2), where [Days] and [Jobs] describe the input.

Space Complexity: O([Days] * [Jobs]), where [Days] and [Jobs] describe the input.

Important: The number of recurrences for each state is NOT Static, but
Dynamic (depends on the day and remaining jobs), which in turn results in
* Adding an extra loop inside the bottom-up solution, resulting in 3 Loops
  * Loop for the State-Variable of the current Day
  * Loop for the State-Variable of the current Job
  * Loop for iterating and checking the subsequent days
* Increasing complexity by the size of the loop - More than just trying
all possible states, since each sub-state performs a loop of recurrences