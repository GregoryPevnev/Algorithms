// Reference: https://leetcode.com/problems/task-scheduler/

#include <iostream>
#include <vector>
#include <queue>

#define ALPHABET_SIZE 26

using namespace std;

// ---------------------------------------------------------------------------------------------------------------------
// Solution
// ---------------------------------------------------------------------------------------------------------------------

// Just a specialized version of "Rearrange String K Distance Apart" Problem
//    -> See it for more information

typedef priority_queue<int, vector<int>, less<int>> task_pq;

int schedule_tasks(vector<char>& tasks, int cooldown) {
    const int interval_length = cooldown + 1;

    task_pq pq;

    int time = 0;

    int count[ALPHABET_SIZE];
    for (int i = 0; i < ALPHABET_SIZE; i++) count[i] = 0;
    for (char const &task : tasks) count[task - 'A']++;

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (count[i] > 0) {
            pq.push(count[i]);
        }
    }

    int interval_tasks_count;
    vector<int> interval_tasks(interval_length);

    while (!pq.empty()) {
        interval_tasks_count = 0;

        while (!pq.empty() && interval_tasks_count < interval_length) {
            interval_tasks[interval_tasks_count++] = pq.top();
            pq.pop();
        }

        for (int i = 0; i < interval_tasks_count; i++) {
            if (interval_tasks[i] > 1) {
                pq.push(--interval_tasks[i]);
            }
        }

        time += interval_length;
    }

    // Important: Taking int account the fact that the last interval count half ended with consecutive IDLEs
    time -= (interval_length - interval_tasks_count);

    return time;
}

// ---------------------------------------------------------------------------------------------------------------------
// Tester
// ---------------------------------------------------------------------------------------------------------------------

int main() {
    // Input: tasks = ["A","A","A","A","A","A","B","C","D","E","F","G"], n = 2
    // Output: 16
    vector<char> tasks{'A', 'A', 'A', 'A', 'A', 'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    int cooldown = 2;
    cout << schedule_tasks(tasks, cooldown) << endl;

    return 0;
}
