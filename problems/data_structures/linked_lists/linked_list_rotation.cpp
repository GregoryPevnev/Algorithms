// Reference: https://leetcode.com/problems/rotate-list

#include <stdio.h>

// ---------------------------------------------------------------------------------------------------------------------
// Solution
// ---------------------------------------------------------------------------------------------------------------------

struct list_node {
    int val;
    struct list_node *next;
};

typedef struct list_node list_node_t;

// Rotation:
//   1. Detaching the New-Head from the prior / previous Node
//   2. Attaching the Old-Head to the Tail as the next Node
//   3. Returning the New-Head

list_node_t* rotate_right(list_node_t* head, int k){
    if (!head) return NULL;

    // Phase 1. Finding the size of the linked-list and the last / tail node

    int size = 0;

    list_node_t* tail;
    list_node_t* cur;

    for (cur = head; cur; cur = cur->next, size++) {
        if (!cur->next) {
            tail = cur;
        }
    }

    // Phase 2. Finding the ACTUAL number of rotations that need to be performed (Without looping)

    int r = k % size;

    if (r == 0) return head;

    // Phase 3. Finding the index of the Next-Head

    int new_head_idx = size - r; // Located exactly a the index of R places apart from the end
    list_node_t* new_head;

    // Phase 4. Iterating and finding a node that goes directly BEFORE the next-head

    cur = head;
    for (int idx = 0; idx < new_head_idx - 1; idx++, cur = cur->next);

    // Phase 5. Attaching and Detaching Nodes to perform the actual rotation

    // Step 1. Selecting the New-Head and detaching the previous node from it
    new_head = cur->next;
    cur->next = NULL;

    // Step 2. Attaching the Old-Head to the Tail as the next node
    tail->next = head;

    // Step 3. Returning the New-Head to represent the Linked-List
    return new_head;
}

// ---------------------------------------------------------------------------------------------------------------------
// Tester
// ---------------------------------------------------------------------------------------------------------------------

// Input: head = [1,2,3,4,5], k = 7
// Output: [4,5,1,2,3]

int main() {
    list_node_t one, two, three, four, five;

    one.val = 1;
    two.val = 2;
    three.val = 3;
    four.val = 4;
    five.val = 5;

    one.next = &two;
    two.next = &three;
    three.next = &four;
    four.next = &five;
    five.next = NULL;

    list_node_t* head = rotate_right(&one, 7);

    for (list_node_t* cur = head; cur; cur = cur->next) {
        printf("%d ", cur->val);
    }
    printf("\n");

    return 0;
}
