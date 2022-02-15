cmake_minimum_required(VERSION 3.19)
project(Special)

set(CMAKE_CXX_STANDARD 14)

# ----------------------------------------------------------------------------------------------------------------------
# Bitwise
# ----------------------------------------------------------------------------------------------------------------------

add_executable(SingleNumberBitwise bitwise/single_number.cpp)

# ----------------------------------------------------------------------------------------------------------------------
# Brute Force
# ----------------------------------------------------------------------------------------------------------------------

add_executable(BuildAllSubsets brute_force/build_all_subsets/build_all_subsets.cpp)

add_executable(CookingTimer brute_force/cooking_timer.cpp)

# ----------------------------------------------------------------------------------------------------------------------
# Casting
# ----------------------------------------------------------------------------------------------------------------------

add_executable(StringToInt casting/string_to_int.cpp)

# ----------------------------------------------------------------------------------------------------------------------
# Numerical
# ----------------------------------------------------------------------------------------------------------------------

add_executable(KDiffHashing numerical/k_diff/k_diff_hashing.cpp)
add_executable(KDiffSorting numerical/k_diff/k_diff_sorting.cpp)

add_executable(NumberLength numerical/number_length/number_length.cpp)

add_executable(SortedSquares numerical/sorted_squares/sorted_squares.cpp)

add_executable(FourSum numerical/sums/four_sums.cpp)
add_executable(FourSumsCount numerical/sums/four_sums_count.cpp)
add_executable(KSum numerical/sums/k_sum.cpp)
add_executable(ThreeSum numerical/sums/three_sums.cpp)
add_executable(TwoSum numerical/sums/two_sum.cpp)