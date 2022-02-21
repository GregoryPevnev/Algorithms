#include <iostream>

using namespace std;

struct linked_list_node {
    int val;
    linked_list_node* next;

    linked_list_node(): val(0), next(nullptr) {}
    linked_list_node(int val): val(val), next(nullptr) {}
};

class singly_linked_list {
private:
    // Head and Tail pointers
    linked_list_node* head;
    linked_list_node* tail;

    // Keeping track of the number of elements
    // Important: Extremely important, it enables
    //    - Validating index-queries right away for getting, adding and deleting (Bounds and size)
    //    - Checking whether adding / deleting is directed at the Tail
    int size;

    // Special node used specifically for "find_node_at_index" operation
    //   -> Allows returning a node which points at the Head
    //   => Serving retrieval of Node located at the Index "-1"
    linked_list_node dummy;

    // Returning a Node located at a specific index - Including the node previous to the Head
    //    -> Serving "-1" index retrieval with a Dummy-Node (Used for deletions)
    // Performance: O(N)
    linked_list_node* find_node_at_index(int index) {
        // Checking Bounds - Allowing "-1" Index (Node previous to the Head)
        if (index >= size || index < -1) return nullptr;

        // Initializing the current Node to the Dummy-Node -> Allows returning the Node PREVIOUS to the Head
        linked_list_node* cur = &dummy;
        cur->next = head;

        // Important: Iterating when the Index is 0 - Allows moving to the Head from the Dummy
        //   - Otherwise 0th index remains on the Dummy-Node
        while (index-- >= 0) cur = cur->next;

        return cur;
    }
public:
    singly_linked_list(): head(nullptr), tail(nullptr), size(0) {}

    // Getting / Retrieving

    // Retrieving the value from the Head
    int get_at_head() {
        if (size == 0) throw "The list is empty";

        return head->val;
    }

    // Retrieving the value from the Tail
    int get_at_tail() {
        if (size == 0) throw "The list is empty";

        return tail->val;
    }

    // Retrieving a node at the specific index and returning the value
    // Performance: O(N)
    int get(int index) {
        linked_list_node* cur = find_node_at_index(index);

        if (cur == nullptr) throw "Invalid index";

        return cur->val;
    }

    // Inserting / Adding

    // Prepending the Node to the current Head
    // Performance: O(1)
    void add_at_head(int val) {
        linked_list_node* tmp = head;

        head = new linked_list_node(val);

        head->next = tmp;

        // Setting the Tail-Node in case the List is empty
        if (size == 0) tail = head;

        size++;
    }

    // Appending the Node to the current Tail
    // Performance: O(1)
    void add_at_tail(int val) {
        linked_list_node* tmp = new linked_list_node(val);

        if (size == 0) {
            // Case 1. The list is empty -> Initializing the Head and Tail
            head = tail = tmp;
        } else {
            // Case 2. The list is NOT empty -> Actually prepending the Node
            tail->next = tmp;
            tail = tmp;
        }

        size++;
    }

    // Performance: O(N)
    // Note: Allows inserting to the index after the current element - Equivalent to inserting at the tail
    void add_at_index(int index, int val) {
        // Check: Out of bounds (EXCLUDING the successive index) -> Returning
        if (index > size || index < 0) return;

        // Case 1: Inserting at head
        if (index == 0) return add_at_head(val);

        // Case 2: Inserting at tail - Specified by the index AFTER the last index
        if (index == size) return add_at_tail(val);

        // Case 3: Inserting at an arbitrary position -> Finding a previous position to re-chain the nodes

        // Step 1. Locating the Node previous to the desired index -> Getting the next Node as well
        linked_list_node *prev = find_node_at_index(index - 1);
        linked_list_node *next = prev->next;

        // Step 2. Re-Chaining the Nodes
        linked_list_node *cur = new linked_list_node(val);
        prev->next = cur;
        cur->next = next;

        // Step 3. Increasing the size
        size++;
    }

    // Deleting

    // Deleting the Node at the current Head
    // Performance: O(1)
    void delete_at_head() {
        delete_at_index(0);
    }

    // Deleting the Node at the current Tail
    // Performance: O(1)
    void delete_at_tail() {
        delete_at_index(size - 1);
    }

    // Performance: O(N)
    // Note: Cannot delete an element with an index out of bounds - Thw tail must be specified by the exact index
    void delete_at_index(int index) {
        // Check: Out of bounds (INCLUDING the successive index) -> Returning
        if (index >= size || index < 0) return;

        // Step 1. Retrieving the Node previous to the Node designated to be deleted
        //  -> Saving the Previous, Current and Next Nodes
        linked_list_node* prev = find_node_at_index(index - 1);
        linked_list_node* cur = prev->next;
        linked_list_node* next = cur->next;

        // Step 2. Re-Chaining in order to skip / avoid the deleting Node
        prev->next = next;

        // Step 3. Performing additional operations according for special cases
        if (size == 1) {
            // Case 1: The List only has a single Node -> Clearing completely
            head = tail = nullptr;
        } else if (index == 0) {
            // Case 2: Deleting the Head-Node -> Changing the Head-Pointer (To the NEXT Node)
            head = next;
        } else if (index == size - 1) {
            // Case 3: Deleting the Tail-Node -> Changing the Tail-Pointer (To the PREVIOUS Node)
            tail = prev;
        }

        // Step 4. Deleting and decreasing the size
        delete cur;
        size--;
    }

    inline const int length() {
        return size;
    }
};

int main() {
    singly_linked_list list;

    list.add_at_head(1);
    list.add_at_tail(3);
    list.add_at_index(1, 2);

    cout << list.get(1) << endl; // 2

    list.delete_at_index(1);

    cout << list.get(1) << endl; // 3

    return 0;
}
