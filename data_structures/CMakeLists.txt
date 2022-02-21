cmake_minimum_required(VERSION 3.19)
project(DataStructures)

set(CMAKE_CXX_STANDARD 14)

# ----------------------------------------------------------------------------------------------------------------------
# Array
# ----------------------------------------------------------------------------------------------------------------------

# Modifications

# Reversing Strings
add_executable(ReverseString arrays/modifications/reverse_string/reverse_string.cpp)
add_executable(ReverseStringWords arrays/modifications/reverse_string/reverse_string_words.cpp)
add_executable(ReverseStringWordsOrder arrays/modifications/reverse_string/reverse_string_words_order.cpp)

# Traversal

# Diagonal Traversal
add_executable(
        DiagonalTraversalEvenSimulation
        arrays/traversal/diagonal_traversal/even/even_diagonal_traversal_simulation.cpp
)
add_executable(
        DiagonalTraversalEvenMatching
        arrays/traversal/diagonal_traversal/even/even_diagonal_traversal_matching.cpp
)
add_executable(
        DiagonalTraversalUneven
        arrays/traversal/diagonal_traversal/uneven/uneven_diagonal_traversal.cpp
)

# Spiral Matrix
add_executable(
        SpiralMatrixOrder
        arrays/traversal/spiral_matrix/find_spiral_matrix_order.cpp
)
add_executable(
        SpiralMatrixGeneration
        arrays/traversal/spiral_matrix/generate_spiral_matrix.cpp
)

# ----------------------------------------------------------------------------------------------------------------------
# Linked-Lists
# ----------------------------------------------------------------------------------------------------------------------

# TODO: Moving implementations to "Resources" at one point

# Linked-List Implementations

add_executable(SinglyLinkedList linked_lists/linked_list/singly_linked_list/singly_linked_list.cpp)

# Search

add_executable(LinkedListCycle linked_lists/search/cycle_finding/cycle_finding.cpp)

add_executable(RemoveNthElement linked_lists/search/remove_nth_element/remove_nth_element.cpp)

# Modifications

add_executable(LinkedListRotation linked_lists/modifications/rotation/linked_list_rotation.cpp)
