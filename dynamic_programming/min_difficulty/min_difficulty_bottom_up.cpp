#include <iostream>
#include <vector>

using namespace std;

int min_difficulty(vector<int>& jobs, int days) {
    const int total_jobs = jobs.size();

    if (total_jobs < days) return -1;

    // Day -> Starting Job
    vector<vector<int>> min_difficulties(days + 1, vector<int>(total_jobs, INT_MAX));

    // Base-Case: Computing all possibilities for the Last-Day
    //   -> Trying out all possible starting points
    //   => From: There is just one job for the last day
    //      To: There is only 1 job for all the days except the last one - Subtracting 1 to exclude the last one
    // Super-Important: Counting in reverse order to find Max-Difficulty - ALL JOBS ARE GOING TO BE PERFORMED AFTER ALL

    int max_current_day_difficulty = -1;

    for (int job = total_jobs - 1; job >= days - 1; job--) {
        max_current_day_difficulty = max(max_current_day_difficulty, jobs[job]);

        min_difficulties[days][job] = max_current_day_difficulty;
    }

    // Iteration with Tabulation
    //   1. Checking all preceding days one by one
    //   2. Trying out all possible final jobs for each day
    //  -> Going from the back to have all the successive jobs and remaining-days pre-computed

    int min_following_days_difficulty;

    for (int day = days - 1; day >= 1; day--) {
        // From: All previous days only had one job assigned to them => # of Jobs = # of days before
        // To: Al following days have only one job assigned to them => # of the remaining days
        for (int start_job = day - 1; start_job <= total_jobs - 1 - (days - day); start_job++) {
            max_current_day_difficulty = -1;

            for (int job = start_job; job <= total_jobs - 1 - (days - day); job++) {
                max_current_day_difficulty = max(max_current_day_difficulty, jobs[job]);

                min_following_days_difficulty = min_difficulties[day + 1][job + 1];

                min_difficulties[day][start_job] = min(
                        min_difficulties[day][start_job],
                        max_current_day_difficulty + min_following_days_difficulty
                );
            }
        }
    }

    return min_difficulties[1][0];
}

int main() {
    // Input: jobs = [6,5,4,3,2,1], days = 2
    // Output: 7
    vector<int> difficulties1{6, 5, 4, 3, 2, 1};
    int days1 = 2;
    cout << min_difficulty(difficulties1, days1) << endl;

    // Input: jobs = [11,111,22,222,33,333,44,444], days = 6
    // Output: 843
    vector<int> difficulties2{11, 111, 22, 222, 33, 333, 44, 444};
    int days2 = 6;
    cout << min_difficulty(difficulties2, days2) << endl;

    // Input: jobs = [186,398,479,206,885,423,805,112,925,656,16,932,740,292,671,360], days = 4
    // Output: 1803
    vector<int> difficulties3{186,398,479,206,885,423,805,112,925,656,16,932,740,292,671,360};
    int days3 = 4;
    cout << min_difficulty(difficulties3, days3) << endl;

    return 0;
}

