// Reference: https://leetcode.com/problems/task-scheduler/
// Guide: https://leetcode.com/problems/task-scheduler/discuss/104500/Java-O(n)-time-O(1)-space-1-pass-no-sorting-solution-with-detailed-explanation

#include <iostream>
#include <vector>

#define ALPHABET_SIZE 26

using namespace std;

// ---------------------------------------------------------------------------------------------------------------------
// Solution
// ---------------------------------------------------------------------------------------------------------------------

// The total time is essentially 1) Total number of Tasks 2) Total number of IDLEs -> Sum

// Reasoning: IDLEs only come from the Most-Frequent Task(s) in Cooldown-Intervals between them
// Example ['A', 'A', 'A', 'B', 'C'] -> A,?,?,A,?,?,A => A,B,C,A,-,-,A (2 Idles)

// Approach:
//    1. Calculating the total POSSIBLE number of IDLEs that can be found between the most frequent Task(s) in Intervals
//    2. Calculating the number of AVAILABLE Tasks that can fill in instead of the possible IDLEs
//    3. Finding the number of ACTUAL Idles

int schedule_tasks(vector<char>& tasks, int cooldown) {
    // Step 1. Counting frequencies of each Task and the total number of Tasks

    vector<int> tasks_count(ALPHABET_SIZE, 0);
    int total_tasks_count = 0;

    for (char const &task : tasks) {
        tasks_count[task - 'A']++;
        total_tasks_count++;
    }

    // Step 2. Finding the most frequent Task and the number of the most frequent Tasks

    int max_frequency = 0, max_count = 0;

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (tasks_count[i] > max_frequency) {
            max_frequency = tasks_count[i];
            max_count = 1;
        } else if (tasks_count[i] == max_frequency) {
            max_count++;
        }
    }

    // Step 3. Calculating the number of actual IDLEs

    // 1) Number of the activities of IDLEs - Depends on the frequency of the Max-Task (Cooldown after each processing)
    //   -> Not counting the last time (Does NOT need Cooldown after the final processing)
    int possible_idles_intervals = (max_frequency - 1);

    // 2) Length of the activities of IDLEs - Decreased by 1 for each Task with the same Max-Frequency
    //    Ex1. A,?,?,A,?,?,A (2) -> A,B,?,A,B,?,A,B (1)
    //    Ex2. A,?,?,?,A,?,?,?,A (3) -> A,B,C,?,A,B,C,?,A,B,C (1)
    int possible_idles_interval_length = cooldown - (max_count - 1);

    // 3) Total number of Possible IDLEs (All IDLEs in ALL Intervals)
    int possible_idles = possible_idles_intervals * possible_idles_interval_length;

    // 4) Number of Tasks that can fill in instead of the IDLEs - NOT counting the Most-Frequent ones (Already included)
    int available_tasks = total_tasks_count - (max_frequency * max_count);

    // 5) Finding the ACTUAL Number of IDLEs
    int actual_idles = max(0, possible_idles - available_tasks);

    // Step 4. Result

    return total_tasks_count + actual_idles;
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
