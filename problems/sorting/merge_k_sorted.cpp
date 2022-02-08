// Reference: https://leetcode.com/problems/merge-k-sorted-lists/
// Tags: Sorting, Priority Queue, External Merge Sort

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// ---------------------------------------------------------------------------------------------------------------------
// Definitions
// ---------------------------------------------------------------------------------------------------------------------

struct list_node {
    int val;
    list_node *next;

    list_node(int x) : val(x), next(nullptr) {}
};

list_node* build_list(vector<int>& vals) {
    list_node* head = nullptr;
    list_node* tail = nullptr;
    list_node* cur;

    for (int const &val : vals) {
        cur = new list_node(val);

        if (head == nullptr || tail == nullptr) {
            head = cur;
            tail = head;
        } else {
            tail->next = cur;
            tail = cur;
        }
    }

    return head;
}

void print_list(list_node* l) {
    cout << "[ ";
    while(l != nullptr) {
        cout << l->val << " ";
        l = l->next;
    }
    cout << "]" << endl;
}

// ---------------------------------------------------------------------------------------------------------------------
// Solution
// ---------------------------------------------------------------------------------------------------------------------

struct cmp_list_node {
    bool operator()(list_node* n1, list_node* n2) {
        return n1->val > n2->val;
    }
};

typedef priority_queue<list_node*, vector<list_node*>, cmp_list_node> list_pq;

list_node* merge_k_sorted(vector<list_node*>& lists) {
    if (lists.size() == 0) return nullptr;

    list_pq pq;

    for (list_node* node : lists) {
        if (node) {
            pq.push(node);
        }
    }

    list_node* head = nullptr;
    list_node* tail = nullptr;
    list_node* cur;

    while (!pq.empty()) {
        cur = pq.top(); pq.pop();

        if (cur->next) {
            pq.push(cur->next);

            cur->next = nullptr;
        }

        if (head == nullptr) {
            head = cur;
            tail = head;
        } else {
            tail->next = cur;
            tail = cur;
        }
    }

    return head;
}

// ---------------------------------------------------------------------------------------------------------------------
// Tester
// ---------------------------------------------------------------------------------------------------------------------

int main() {
    // Input: lists = [[1,4,5],[1,3,4],[2,6]]
    // Output: [1,1,2,3,4,4,5,6]

    vector<int> vals1{1, 4, 5};
    vector<int> vals2{1, 3, 4};
    vector<int> vals3{2, 6};
    vector<list_node*> lists{build_list(vals1), build_list(vals2), build_list(vals3)};

    list_node* sorted_list = merge_k_sorted(lists);

    print_list(sorted_list);

    return 0;
}
