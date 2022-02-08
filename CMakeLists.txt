cmake_minimum_required(VERSION 3.19)
project(Algorithms)

set(CMAKE_CXX_STANDARD 14)

# ----------------------------------------------------------------------------------------------------------------------
# PROBLEMS
# ----------------------------------------------------------------------------------------------------------------------

# ----------------------------------------------------------------------------------------------------------------------
# Data-Structures
# ----------------------------------------------------------------------------------------------------------------------

# Linked-Lists

add_executable(LinkedListRotation problems/data_structures/linked_lists/linked_list_rotation.cpp)

# ----------------------------------------------------------------------------------------------------------------------
# Dynamic Programming
# ----------------------------------------------------------------------------------------------------------------------

add_executable(FourSumsCount problems/dynamic_programming/four_sums_count.cpp)

add_executable(PowerSum problems/dynamic_programming/power_sum.cpp)

# ----------------------------------------------------------------------------------------------------------------------
# Graphs
# ----------------------------------------------------------------------------------------------------------------------

add_executable(KHighestRankedItems problems/graphs/k_highest_ranked_items.cpp)

# ----------------------------------------------------------------------------------------------------------------------
# Greedy
# ----------------------------------------------------------------------------------------------------------------------

# Activities
add_executable(CourseSchedule problems/greedy/activities/course_schedule.cpp)
add_executable(MaxNonOverlappingIntervals problems/greedy/activities/max_non_overlapping_intervals.cpp)
add_executable(MinArrowsToBurstBalloons problems/greedy/activities/min_arrows_to_burst_balloons.cpp)
add_executable(MinRemovedOverlappingIntervals problems/greedy/activities/min_removed_overlapping_intervals.cpp)

# Anagrams
add_executable(CheckAnagram problems/greedy/anagrams/check_anagram.cpp)
add_executable(FindAllAnagrams problems/greedy/anagrams/find_all_anagrams.cpp)
add_executable(FindAllAnagramsSimple problems/greedy/anagrams/find_all_anagrams_simple.cpp)

# Daily Temperatures
add_executable(DailyTemperaturesBackward problems/greedy/daily_temperatures/daily_temperatures_backward.cpp)
add_executable(DailyTemperaturesForward problems/greedy/daily_temperatures/daily_temperatures_forward.cpp)

# Divide Array Sequences
add_executable(DivideArraySequences problems/greedy/divide_array_sequences/divide_array_sequences.cpp)
add_executable(DivideArraySequencesOptimal problems/greedy/divide_array_sequences/divide_array_sequences_optimal.cpp)

# Duplicate Letters
add_executable(DuplicateLetters problems/greedy/duplicate_letters/duplicate_letters.cpp)
add_executable(DuplicateLettersFast problems/greedy/duplicate_letters/duplicate_letters_fast.cpp)

# Jump Game
add_executable(JumpGameCanJump problems/greedy/jumping/can_jump.cpp)
add_executable(JumpGameMinJumps problems/greedy/jumping/min_jumps.cpp)

# Largest Histogram
add_executable(LargestHistogram problems/greedy/largest_histogram/largest_histogram.cpp)
add_executable(LargestHistogramCustom problems/greedy/largest_histogram/largest_histogram_custom.cpp)
add_executable(LargestHistogramFast problems/greedy/largest_histogram/largest_histogram_fast.cpp)

# Largest Number
add_executable(LargestNumber problems/greedy/largest_number/largest_number.cpp)
add_executable(LargestNumberCustom problems/greedy/largest_number/largest_number_custom.cpp)

# Longest Substring with Unique Characters
add_executable(LongestUniqueSubstring problems/greedy/longest_unique_substring/longest_unique_substring.cpp)
add_executable(LongestUniqueSubstringFast problems/greedy/longest_unique_substring/longest_unique_substring_fast.cpp)

# Rearrange String
add_executable(RearrangeString problems/greedy/rearrange_string/rearrange_string.cpp)
add_executable(RearrangeStringKDistance problems/greedy/rearrange_string/rearrange_string_k_distance.cpp)

# Subarray Sums
add_executable(SubarraySums problems/greedy/subarray_sums/subarray_sums.cpp)
add_executable(ContinuousSubarraySums problems/greedy/subarray_sums/continuous_subarray_sums.cpp)

# Task Scheduler
add_executable(TaskScheduler problems/greedy/task_scheduler/task_scheduler.cpp)
add_executable(TaskSchedulerFast problems/greedy/task_scheduler/task_scheduler_fast.cpp)

# Buying Stocks
add_executable(BuyingStocks problems/greedy/buying_stocks.cpp)

# Continuous Subarray
add_executable(ContinuousSubarray problems/greedy/continuous_subarray.cpp)

# Dedupe Array
add_executable(DeduplicateArray problems/greedy/deduplicate_array.cpp)

# Intervals
add_executable(IntervalDistances problems/greedy/interval_distances.cpp)

# Minimum Sums Difference
add_executable(MinimumSumsDifference problems/greedy/min_sums_difference.cpp)

# Queue Reconstruction
add_executable(QueueReconstruction problems/greedy/queue_reconstruction.cpp)

# Removing K Digits
add_executable(RemoveKDigits problems/greedy/remove_k_digits.cpp)

# Split Array Sequences
add_executable(SplitArraySequences problems/greedy/split_array_sequences.cpp)

# Playing
add_executable(VitoFamily problems/greedy/vito.c)

# ----------------------------------------------------------------------------------------------------------------------
# Sorting
# ----------------------------------------------------------------------------------------------------------------------

# Merge K Sorted
add_executable(MergeKSorted problems/sorting/merge_k_sorted.cpp)

# ----------------------------------------------------------------------------------------------------------------------
# Special
# ----------------------------------------------------------------------------------------------------------------------

# Brute Force

# Cooking Timer
add_executable(CookingTimer problems/special/brute_force/cooking_timer.cpp)

# Numerical

# String to Int
add_executable(StringToInt problems/special/numerical/string_to_int.cpp)

# Sums
add_executable(FourSum problems/special/sums/four_sums.cpp)
add_executable(KSum problems/special/sums/k_sum.cpp)
add_executable(ThreeSum problems/special/sums/three_sums.cpp)
add_executable(TwoSum problems/special/sums/two_sum.cpp)