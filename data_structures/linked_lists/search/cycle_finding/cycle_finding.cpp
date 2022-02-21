#include <iostream>
#include <vector>

using namespace std;

// ---------------------------------------------------------------------------------------------------------------------
// Definition
// ---------------------------------------------------------------------------------------------------------------------

struct linked_node {
    linked_node* next;
    int val;

    linked_node(): next(nullptr), val(0) {}
    linked_node(int val): next(nullptr), val(val) {}
};

// ---------------------------------------------------------------------------------------------------------------------
// Solution
// ---------------------------------------------------------------------------------------------------------------------

linked_node* find_cycle_start(linked_node* head) {
    linked_node* slow = head; // Slow Pointer
    linked_node* fast = head; // Fast Pointer

    // Lengths:
    //   L1 - Distance from the start of the List to the start of the Cycle
    //   L2 - Distance from the start of the Cycle to the Meeting-Point

    bool cycle_found = false;

    while (slow != nullptr && fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        // Meeting at location L1 + L2
        // Pointer 1 (Slow) Distance: L1 + L2 + Cycles (Not counting)
        // Pointer 2 (Fast) Distance: L1 + L2 + Last-Cycle + Other Cycles (Not Counting)
        //   -> L1 + L2 + L2 + Distance-To-The-End-Of-Cycle
        //   => L1 + 2L2 + X
        //  - Having one L2 from the last cycle and one L2 for reaching the meeting position
        if (slow == fast) {
            cycle_found = true;

            break;
        }
    }

    // Meeting Position not found -> No cycle
    if (!cycle_found) return nullptr;

    // Distances: Distance(P1) is TWICE LESS thn the Distance(P2) by definition
    //   -> Distance(P1) * 2 = Distance(P2)
    //   => 2 * (L1 + L2) = L1 + 2L2 + X
    //   => 2L1 * 2L2 = L1 + 2L2 + X
    //   => L1 = X
    //  - Means that the distance required to reach the beginning of the cycle is the same
    //    as the distance required to finish the cycle (The pointers meet)
    linked_node* start = head;

    // Reaching the Beginning of the Cycle by both pointers at the same time
    //   Pointer 1 (Slow) - Moving from the Meeting-Point to the Begnning of the cycle
    //     -> Covering Distance X (Equal to L1)
    //   Pointer 3 (Start) - Moving from the List-Start to the Beginning of the Cycle
    //     -> Covering Distance L1 (Equal to X)
    // Note: Pointer 2 (Fast) could be used instead - Does NOT matter (Just the position)
    while (start != slow) {
        start = start->next;
        slow = slow->next;
    }

    return start;
}

// ---------------------------------------------------------------------------------------------------------------------
// Helpers
// ---------------------------------------------------------------------------------------------------------------------

linked_node* build_linked_list(vector<int>& vals, const int cycle_start_pos) {
    linked_node* head = new linked_node(vals[0]);

    linked_node* cur = head;

    linked_node* cycle_start;

    for (int i = 1; i < vals.size(); i++) {
        cur->next = new linked_node(vals[i]);
        cur = cur->next;

        if (i == cycle_start_pos) {
            cycle_start = cur;
        }
    }

    cur->next = cycle_start;

    return head;
}

// ---------------------------------------------------------------------------------------------------------------------
// Testing
// ---------------------------------------------------------------------------------------------------------------------

int main() {
    // Starting a cycle at element "2"
    vector<int> vals{3, 2, 0, -4};
    const int cycle_start_pos = 1;
    linked_node* list = build_linked_list(vals, cycle_start_pos);

    linked_node* cycle_start = find_cycle_start(list);

    cout << (cycle_start == nullptr ? -1 : cycle_start->val) << endl;

    return 0;
}
