## Search in Linked-Lists

Common patterns used for searching through the Linked-List and finding
nodes according to specific positions or values include:
* Using Two-Pointers for comparing / checking.
  * Fast and Slow pointers for detecting cycles (**Floyd's Algorithm**).
  * Pointers with a Gap K distance apart for covering distance and
    checking for the end more efficiently.
  * Keeping multiple pointers for each Linked-List.
* Using an additional data-structure for keeping track of positions (When
  it is allowed)
  * Using Stack for going back by a certain number of positions.
  * Using Map / Set for performing lookups / checks.
* Iterating / Traversing the Linked-List beforehand in order to determine
  the size.
* Trying to make assumptions / decisions based on
  mathematical properties, calculated from distances / gaps / etc.
  
**Important**: When Two-Pointers technique is used, it does NOT matter
that only 2 pointers need to be used (Floyd / Cycle-Finding).
