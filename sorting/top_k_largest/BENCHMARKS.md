## Benchmarks of Top K Largest



N = 100000000
K = 2000

Max-Heap:
Time: N + K*logN =>
Space: N

Min-Heap:
Time: K + (N-K)*logK*2 =>
Space: K

Quick-Select + Quick-Sort:
Time: 2N + KlogK


### Complexity

#### Approach 1. Full Max-Heap

#### Approach 2. Running Min-Heap

#### Approach 3.  Quick-Select with Quick-Sort



### Performance

#### Approach 1. Full Max-Heap

#### Approach 2. Running Min-Heap

#### Approach 3.  Quick-Select with Quick-Sort