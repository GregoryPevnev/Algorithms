## Minimum Deviation

Reference: https://leetcode.com/problems/minimize-deviation-in-array/

Guide: https://leetcode.com/problems/minimize-deviation-in-array/discuss/1781709/C%2B%2B-oror-Easy-oror-2-Approaches-oror-Priority-Queue-oror-Set

Observations:
* Checking as long the max-number is EVEN - Exhausted all possibilities
  otherwise.
* All ODD numbers can be turned into EVEN numbers during the preparation.

Solutions: Solve with BOTH
1. Tree-Set
2. Priority-Queue

Patterns:
* Using Priority-Queue or Tree-Set for keeping track of the
  minimum and maximum numbers in a running / changing set.
  * Priority-Queue: Using Max-Heap and keeping track of the minimum
    number **manually** - this is a very valid solution.
  * Tree-Set: Accessing and Modifying minimum and maximum values.
* Reducing the total number of cases to work with (Turning ODD into EVEN).

**Important**: Priority-Queue can be used for keeping track of BOTH
minimum and maximum numbers simultaneously by having a Min-Heap for the
minimum number and tracking the maximum number manually, or the opposite
(having a Max-Heap for the maximum number and tracking the minimum
number manually).

