#include <iostream>
#include <vector>

using namespace std;

int min_difficulty_for(vector<int>& jobs, int job, int days_left, vector<vector<int>>& min_difficulties) {
    // Base-Case: The last day

    // Performing all the remaining jobs if this is the last day
    if (days_left == 0) {
        int max_job_difficulty = -1;

        for (int j = job; j < jobs.size(); j++) max_job_difficulty = max(max_job_difficulty, jobs[j]);

        return max_job_difficulty;
    }

    // Recursive Case: There are more days ahead

    if (min_difficulties[days_left][job] == -1) {
        int current_day_max_difficulty = -1;

        int next_days_min_difficulty;

        int min_difficulty = INT_MAX;

        for (int j = job; j <= jobs.size() - 1 - days_left; j++) {
            current_day_max_difficulty = max(current_day_max_difficulty, jobs[j]);

            next_days_min_difficulty = min_difficulty_for(jobs, j + 1, days_left - 1, min_difficulties);

            min_difficulty = min(min_difficulty, current_day_max_difficulty + next_days_min_difficulty);
        }

        min_difficulties[days_left][job] = min_difficulty;
    }

    return min_difficulties[days_left][job];
}

int min_difficulty(vector<int>& jobs, int days) {
    const int total_jobs = jobs.size();

    if (total_jobs < days) return -1;

    vector<vector<int>> min_difficulties(days, vector<int>(total_jobs, -1));

    int result = min_difficulty_for(jobs, 0, days - 1, min_difficulties);

    return result;
}

int main() {
    // Input: jobDifficulty = [6,5,4,3,2,1], d = 2
    // Output: 7
    vector<int> difficulties1{6, 5, 4, 3, 2, 1};
    int days1 = 2;
    cout << min_difficulty(difficulties1, days1) << endl;

    // Input: jobDifficulty = [9,9,9], d = 4
    // Output: -1
    vector<int> difficulties2{9, 9, 9};
    int days2 = 4;
    cout << min_difficulty(difficulties2, days2) << endl;

    // Input: jobDifficulty = [11,111,22,222,33,333,44,444], d = 6
    // Output: 843
    // Explanation: 11 + 111 + 22 + 222 + 33 + 444
    vector<int> difficulties3{11, 111, 22, 222, 33, 333, 44, 444};
    int days3 = 6;
    cout << min_difficulty(difficulties3, days3) << endl;

    return 0;
}

