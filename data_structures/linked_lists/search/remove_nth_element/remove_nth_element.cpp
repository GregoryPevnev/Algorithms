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

linked_node* remove_nth_node(linked_node* head, int n) {
    // Step 1. Moving the first Pointer until it is distance of N from the start

    linked_node* end_pointer = head;

    while (n-- > 0 && end_pointer != nullptr) end_pointer = end_pointer->next;

    // Step 2. Checking whether the end was reached -> Deleting the very first / Head element
    //   - Special case

    if (end_pointer == nullptr) {
        linked_node* new_head = head->next;

        delete head;

        return new_head;
    }

    // Step 3. Keeping two running Pointers with the distance of N + 1 nodes apart
    //   - Such that by the time Pointer 1 reaches the end, Pointer 2 reaches the element that is N+1 nodes from the end
    //   -> Element that is previous to the element that should be deleted

    // Moving the End-Pointer by 1
    end_pointer = end_pointer->next;

    // Initializing the Deletion-Pointer / Pointer 2
    linked_node* del_pointer = head;

    // Moving the Pointers until the End-Pointer reaches the end
    while (end_pointer != nullptr) {
        end_pointer = end_pointer->next;
        del_pointer = del_pointer->next;
    }

    // Step 4. Deleting the designated note

    linked_node* del_node = del_pointer->next;

    del_pointer->next = del_node->next;

    delete del_node;

    return head;
}

// ---------------------------------------------------------------------------------------------------------------------
// Helpers
// ---------------------------------------------------------------------------------------------------------------------

linked_node* build_linked_list(vector<int>& vals) {
    linked_node* head = new linked_node(vals[0]);

    linked_node* cur = head;

    for (int i = 1; i < vals.size(); i++) {
        cur->next = new linked_node(vals[i]);
        cur = cur->next;
    }

    return head;
}

void print_list(linked_node* head) {
    while (head != nullptr) {
        cout << head->val << endl;

        head = head->next;
    }
}

// ---------------------------------------------------------------------------------------------------------------------
// Testing
// ---------------------------------------------------------------------------------------------------------------------

int main() {
    // Deleting the 2nd element form the end
    vector<int> vals{1, 2, 3, 4, 5};
    int n = 2;
    linked_node* list = build_linked_list(vals);

    linked_node* new_head = remove_nth_node(list, n);

    print_list(new_head);

    return 0;
}
