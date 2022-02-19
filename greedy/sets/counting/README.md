## Counting

Solving Set-based problems using Counting - Recording information
about the dataset / items in a data-structure:
* Frequencies
* Sums
* Positions

The data-structures that are most commonly used for counting / recording
the state are:
1. Counters / Numbers / Variables
2. Maps
3. Sets

**Important**: The state can be recorded / built and accessed / used
both beforehand and at the runtime (Could be different pieces).


### Characteristics

#### Access

Determines how fast can items be accessed and modified at runtime
* Arrays have the best performance with absolute constant time.
* Hash-Tables are almost identical in terms of speed with amortization.
* Trees are not as performance and should only be used with ordering.

#### Ordering

Determines whether the ordering of the recorded results / values /
counters is needed:
* Unordered - Can access the collected / recorded values in any order
  for achieving the solution / proper results.
* Ordered - The collected results need to be iterated / traversed /
  accessed in a specific order for producing the results.

#### Range

Specifies the nature and range / bounds of the values that need to be
stored and accommodated by the data-structure.
* Bounded - The range of values is extremely small (~10K).
* Unbounded - The range of values is unspecified or is large (>10K).


### Implementations

The data structure odf use depends on all the aforementioned properties.

#### Numerical Arrays

Providing both counting / recording and sorting / ordering capabilities
with absolute efficiency - only works when the range of values is
bounded and is extremely small.

Logic: Using Counting-Sort for sorting in order to populate a new
array, or using the frequencies / results in a subroutine.

Properties:
* Access: Fast (No constraints).
* Ordering: Provided (By the range of numerical values).
* Range: Bounded (Can only accommodate small space).

Important: Should NOT be used with the unbounded range - wastes a lot
of memory and requires additional time for allocating all of it.

#### Hash-Table

Providing extremely good performance for accessing and modifying the
counters / state of each item, BUT it does not provide any
ordering guarantees.

Properties:
* Access: Fast (No constraints).
* Ordering: None (Should NOT be needed).
* Range: Unbounded (Any value is good).

**Important**: Sorting the values and using a Hash-Table does NOT make any
sense, since the performance is worse.


#### Tree

Providing mediocre performance for access and modification, but
provides ordering out-of-the-box when iterating over the counters.

Properties:
* Access: Medium (NOT to be used for linear-time).
* Ordering: Provided for Iteration (ASC / DESC).
* Range: Unbounded (Any value is good).

### Comparison

#### Counting and Ordering

**Numerical Array**: O(N + N + N), where N is the dataset size

1. Counting (Numerical Array) - N
2. Sorting (Using Counting-Sort) - N
3. Iterating (Numerical Array / Frequencies / Populated Array) - N

Performance: The best when the range is bounded.

**Tree**: O(NlogM + M), where N is the dataset size

and M is the # of unique items.
1. Counting and Sorting (Inserting into the Tree) - NlogM
2. Iterating (The tree in the order) - M

Performance: The best when the range is unbounded.

**Hash-Table + Sorting**: O(N + NlogN + N), where N is the dataset

1. Counting (Hash-Table) - N
2. Sorting (Array) - NlogN
3. Iterating (Array + Hash-Table) - N

Performance: The worst (not to be used).