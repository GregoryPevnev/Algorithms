cmake_minimum_required(VERSION 3.19)
project(Sorting)

set(CMAKE_CXX_STANDARD 14)


# ----------------------------------------------------------------------------------------------------------------------
# Kth Largest
# ----------------------------------------------------------------------------------------------------------------------

# ----------------------------------------------------------------------------------------------------------------------
# Merge K Sorted
# ----------------------------------------------------------------------------------------------------------------------

add_executable(MergeKSortedKWay merge_k_sorted/merge_k_sorted_k_way.cpp)

# ----------------------------------------------------------------------------------------------------------------------
# Top K Largest
# ----------------------------------------------------------------------------------------------------------------------

add_executable(TopKLargestMaxHeap top_k_largest/top_k_largest_max_heap.cpp)
add_executable(TopKLargestQuickSelectQuickSort top_k_largest/top_k_largest_quick_select_quick_sort.cpp)
add_executable(TopKLargestRunningMinHeap top_k_largest/top_k_largest_running_min_heap.cpp)

# ----------------------------------------------------------------------------------------------------------------------
# Two-Pointers
# ----------------------------------------------------------------------------------------------------------------------

add_executable(SortByParity two_pointers/sort_by_parity.cpp)

add_executable(SortedSquares two_pointers/sorted_squares.cpp)
