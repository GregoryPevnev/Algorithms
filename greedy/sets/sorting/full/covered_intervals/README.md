## Covered Intervals Removal


Reference: https://leetcode.com/problems/remove-covered-intervals/

Tags: Greedy, Set, Sorting, Full

Complexity: O(NlogN) - Sorting and Iterating through with checking


### Reasoning

In order to check whether a specific interval is covered by another one,
the best solution is to keep track of the current covering interval and
check whether the successive covered intervals fall into it.

Covering Interval: The longest interval with a specific starting position

Covered Intervals: Shorter / equal intervals which have starting and
ending position between the start and end of the Covering Interval.

Overall, this means that the algorithm should continuously select
intervals that have the highest chances of being Covering Intervals and
checking whether the next intervals fall into it. The chances of being a
Covering Interval are maximized by having:
1. The Earliest Starting Time
2. The Longest Duration

**Important**: Duration can also be simply determined by the Ending Time,
which can be used for sorting / ordering instead.


### Approach

Sorting the Intervals by
1. Starting Time (Ascending) - Allows choosing the earliest Intervals.
2. Duration / Ending Time (Descending) - Allows choosing ghe the longest
   Intervals.
   
Checking:
1. Choosing the next candidate Covering Interval
2. Skipping all the next Intervals that fall into it - guaranteed to have
   1. Later starting time
   2. Smaller duration
3. Continuing

Counting: Only the candidate Covering-Intervals need to be counted -
same as excluding the Covered-Intervals.

**Important**: Duration can be completely replaced by the ending time
