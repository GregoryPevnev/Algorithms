## In-Place Modifications


Using the very input array as
* Output array for operating on the data (inserting / deleting /
  reversing).
* Table / state for counting / recording the encountered values.

Approaches:
* Two-Pointers
    * Inserting: Iterating both pointers from the end in order to
      perform shifting to the right effectively.
    * Deleting: Iterating both pointers from the beginning in order to
      perform shifting to the right effectively.
    * Swapping: Iterating from the beginning and end in the opposite
      directions and exchanging items between the positions.


**Important**: The input data-structure / arrays do NOT need to be
changed - can simply be used to reduce the memory usage (passing them
by value instead of passing them by reference).