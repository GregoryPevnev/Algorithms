cmake_minimum_required(VERSION 3.19)
project(Greedy)

set(CMAKE_CXX_STANDARD 14)

# ----------------------------------------------------------------------------------------------------------------------
# Graphs
# ----------------------------------------------------------------------------------------------------------------------

# Search

add_executable(WordLadder graphs/search/words_ladder/word_ladder.cpp)
add_executable(WordLadderList graphs/search/words_ladder/word_ladder_list.cpp)

add_executable(KHighestRankedItems graphs/search/k_highest_ranked_items.cpp)

add_executable(MinJumps graphs/search/min_jumps.cpp)

# ----------------------------------------------------------------------------------------------------------------------
# Sequences
# ----------------------------------------------------------------------------------------------------------------------

# Monotonic Stack

add_executable(DailyTemperaturesBackward sequences/monotonic_stack/daily_temperatures/daily_temperatures_backward.cpp)
add_executable(DailyTemperaturesForward sequences/monotonic_stack/daily_temperatures/daily_temperatures_forward.cpp)

add_executable(DuplicateLetters sequences/monotonic_stack/duplicate_letters/duplicate_letters.cpp)
add_executable(DuplicateLettersOptimized sequences/monotonic_stack/duplicate_letters/duplicate_letters_optimized.cpp)

add_executable(LargestHistogram sequences/monotonic_stack/largest_histogram/largest_histogram.cpp)
add_executable(LargestHistogramCustom sequences/monotonic_stack/largest_histogram/largest_histogram_custom.cpp)
add_executable(LargestHistogramFast sequences/monotonic_stack/largest_histogram/largest_histogram_fast.cpp)

add_executable(RemoveKDigits sequences/monotonic_stack/remove_k_digits.cpp)

# Prefix-Suffix Sum

add_executable(SubarraySums sequences/prefix_suffix_sums/subarray_sums/subarray_sums.cpp)
add_executable(ContinuousSubarraySums sequences/prefix_suffix_sums/subarray_sums/continuous_subarray_sums.cpp)

add_executable(ContinuousSubarray sequences/prefix_suffix_sums/continuous_subarray.cpp)

add_executable(IntervalDistances sequences/prefix_suffix_sums/interval_distances.cpp)

add_executable(MinimumSumsDifference sequences/prefix_suffix_sums/min_sums_difference.cpp)

# Sliding Window

add_executable(CheckAnagram sequences/sliding_window/anagrams/check_anagram.cpp)
add_executable(FindAllAnagrams sequences/sliding_window/anagrams/find_all_anagrams.cpp)
add_executable(FindAllAnagramsSimple sequences/sliding_window/anagrams/find_all_anagrams_simple.cpp)

add_executable(LongestUniqueSubstring sequences/sliding_window/longest_unique_substring/longest_unique_substring.cpp)
add_executable(LongestUniqueSubstringFast sequences/sliding_window/longest_unique_substring/longest_unique_substring_fast.cpp)

# Two Pointers

add_executable(BuyingStocks sequences/two_pointers/buying_stocks/buying_stocks.cpp)

add_executable(CanJump sequences/two_pointers/can_jump/can_jump.cpp)

add_executable(DeduplicateArray sequences/two_pointers/deduplicate_array/deduplicate_array.cpp)

add_executable(DuplicateZeroes sequences/two_pointers/duplicate_zeroes/duplicate_zeroes.cpp)

# ----------------------------------------------------------------------------------------------------------------------
# Sets
# ----------------------------------------------------------------------------------------------------------------------

# Counting: With Ordering

add_executable(DivideArraySequences sets/counting/ordered/divide_array_sequences/divide_array_sequences.cpp)
add_executable(DivideArraySequencesOptimal sets/counting/ordered/divide_array_sequences/divide_array_sequences_optimal.cpp)

# Counting: Without Ordering

add_executable(SplitArraySequences sets/counting/unordered/split_array_sequences.cpp)

# Sorting: Full

add_executable(LargestNumber sets/sorting/full/largest_number/largest_number.cpp)
add_executable(LargestNumberCustom sets/sorting/full/largest_number/largest_number_custom.cpp)

add_executable(MaxNonOverlappingIntervals sets/sorting/full/non_overlapping_intervals/max_non_overlapping_intervals.cpp)
add_executable(MinRemovedOverlappingIntervals sets/sorting/full/non_overlapping_intervals/min_removed_overlapping_intervals.cpp)

add_executable(MinArrowsToBurstBalloons sets/sorting/full/min_arrows_to_burst_balloons.cpp)

add_executable(QueueReconstruction sets/sorting/full/queue_reconstruction.cpp)

# Sorting: Running

add_executable(RearrangeString sets/sorting/running/rearrange_string/rearrange_string.cpp)
add_executable(RearrangeStringKDistance sets/sorting/running/rearrange_string/rearrange_string_k_distance.cpp)

add_executable(CourseSchedule sets/sorting/running/course_schedule.cpp)

add_executable(TaskScheduler sets/sorting/running/task_scheduler.cpp)
