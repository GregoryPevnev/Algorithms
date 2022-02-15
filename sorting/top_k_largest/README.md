## Merging K Sorted



### Approach 1. Full Max-Heap

#### Complexity

Time: O(N + KlogN)
1. Building a Max-Heap with the entire dataset
   of N elements (Heapify) -> O(N)
2. Popping K elements of the Heap of size N -> O(KlogN)

Space: O(N) - Storing the entire dataset of N elements

#### Properties

Time: Highest time-cost is associated with building the Max-Heap
initially - the approach could be viable if the Max-Heap
is already pre-built before running the algorithm.

Memory: Requires storing the entire dataset in the heap -
could be impossible due to the memory constraints.

Application: Only makes sense to use when the Max-Heap is present.


### Approach 2. Running Min-Heap

#### Complexity

Time: O(K + (N-K)logK)
1. Building a Min-Heap with the first K elements (Heapify) -> K
2. Performing comparisons and replacements in a Heap with K elements
   (N-K) times at worst -> (N-K)logK
   
Space: O(K) - Only storing the running top K elements (Largest)

#### Properties

Time: Even though the worst-case is not likely, performing replacements
for possibly every element is expensive (no optimizations though).

Memory: Extremely efficient usage - Only storing a small portion that
is needed for making decisions at the runtime.

Application: Generic algorithm for finding top K elements
when the memory is limited and the dataset cannot fit into it


### Approach 3. Quick-Select with Quick-Sort

#### Complexity

Time: O(N + KlogK)
1. Performing Quick-Select on the dataset of N elements
2. Performing Quick-Sort on the sub-dataset of K elements

Space: O(N) - Storing and operating on the entire dataset of N elements

#### Properties

Time: Achieves the best possible performance at the cost of memory

Memory: The algorithm only works when the entire dataset can be fit
into memory and operated on it without swaps

Application: Optimized algorithm for finding top K elements on
small dataset which can fit into memory as a whole
