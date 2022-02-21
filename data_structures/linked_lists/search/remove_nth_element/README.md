## Remove Nth Element


Reference: https://leetcode.com/problems/remove-nth-node-from-end-of-list/

Tags: Linked-List, Two-Pointers

Complexity: O(N) - Single Pass

### Approach

Keeping Two Pointers in order to have one pointer reach the ```Nth + 1```
element, by keeping the distance between two pointers ```Nth + 1```.

* Pointer-1: Reaching the end - Moving ```Nth + 1``` from the end.
* Pointer-2: Reaching the ```Nth + 1``` element.

Special-Case: Deleting the Head / First element - happens when the
Pointer-1 reaches the end in ```N``` iterations.
