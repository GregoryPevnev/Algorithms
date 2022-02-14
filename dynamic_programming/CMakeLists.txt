cmake_minimum_required(VERSION 3.19)
project(DynamicProgramming)

set(CMAKE_CXX_STANDARD 14)

# Climbing Stairs
add_executable(ClimbingStairsTopDown climbing_stairs/climbing_stairs_top_down.cpp)
add_executable(ClimbingStairsBottomUp climbing_stairs/climbing_stairs_bottom_up.cpp)

# Delete and Earn
add_executable(DeleteAndEarnTopDown delete_and_earn/delete_and_earn_top_down.cpp)
add_executable(DeleteAndEarnBottomUp delete_and_earn/delete_and_earn_bottom_up.cpp)

# House Robber
add_executable(HouseRobberTopDown house_robber/house_robber_top_down.cpp)
add_executable(HouseRobberBottomUp house_robber/house_robber_bottom_up.cpp)

# Longest Common Subsequence
add_executable(LCSTopDown longest_common_subsequence/lcs_bottom_up.cpp)
add_executable(LCSBottomUp longest_common_subsequence/lcs_top_down.cpp)

# Max Score
add_executable(MaxScoreTopDown max_score/max_scope_top_down.cpp)
add_executable(MaxScoreBottomUp max_score/max_scope_bottom_up.cpp)

# Maximal Square
add_executable(MaximalSquare maximal_square/maximal_square.cpp)
add_executable(MaximalSquareOptimized maximal_square/maximal_square_optimized.cpp)

# Min Difficulty
add_executable(MinDifficultyBottomUp min_difficulty/min_difficulty_bottom_up.cpp)
add_executable(MinDifficultyTopDown min_difficulty/min_difficulty_top_down.cpp)
