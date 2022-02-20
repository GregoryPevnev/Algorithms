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
# Numbers
# ----------------------------------------------------------------------------------------------------------------------

add_executable(Addition numbers/addition/addition.cpp)

add_executable(NumberLength numbers/number_length/number_length.cpp)

add_executable(StringToInt numbers/string_to_int/string_to_int.cpp)
