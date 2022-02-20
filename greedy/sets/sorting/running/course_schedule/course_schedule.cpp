// Reference: https://leetcode.com/problems/course-schedule-iii/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// ---------------------------------------------------------------------------------------------------------------------
// Solution
// ---------------------------------------------------------------------------------------------------------------------

// Rational: Should be trying to be Dropping / Swapping Courses that have the LONGEST DURATION
//    - A single LONG Course can be Swapped for a number of SHORT Courses
//    -> Have the least priority in the Priority-Queue of Taken-Courses

// Sorting Courses in ascending order by their Duration so that the TOP courses have the highest duration
//      -> Pointing at the TOP-Courses that have the lowest priority (Can be exchanged for multiple other courses)
//      => Used for finding and changing Top / Min in the Priority-Queue of TAKEN Courses
struct course_duration_time_cmp {
    bool operator()(const vector<int>& course1, const vector<int>& course2) {
        return course1[0] < course2[0];
    }
};

// Priority-Queue which points to Courses with the highest Duration (Top)
typedef priority_queue<vector<int>, vector<vector<int>>, course_duration_time_cmp> courses_pq;

// Sorting Courses in ascending order by their End-Times
//      -> Ensures that End-Time constraints remain valid after swapping
//      => Used for ordering in order to iterate safely
// Additional: Sorting by Duration to start with the smallest
bool course_end_time_cmp(const vector<int>& course1, const vector<int>& course2) {
    return course1[1] < course2[1];
}

int max_course_schedule(vector<vector<int>>& courses) {
    // Initializing the running subset of Courses that are CURRENTLY taken (Change on the way)
    int current_end_time = 0; // The current finishing-time of all the CURRENTLY taken Courses (Current Schedule End-Time)
    courses_pq taken_courses_pq; // PQ of all the CURRENTLY taken Courses / Current Schedule
    //  -> The Top-Course is the Course with the LONGEST Duration => HIGHEST PRIORITY FOR DROPPING

    // Sorting the courses by their End-Time -> Makes swapping safe (Prior Courses are NOT going to be affected)
    //    => If a Course with an EARLIER End-Time was dropped, all the later ones should still be fine
    sort(courses.begin(), courses.end(), course_end_time_cmp);

    // Checking whether each Course can be added to the current Schedule
    for (vector<int> const &course : courses) {
        if (current_end_time + course[0] <= course[1]) {
            // Case A. If the current Course can be added to the Current Schedule - Can be finished if it is started now
            //   -> 1) Changing the Current End-Time to the time AFTER the course was taken
            //      2) Adding the Course to the current Schedule / PQ of the taken Courses
            current_end_time += course[0];
            taken_courses_pq.push(course);
        } else if (!taken_courses_pq.empty() && taken_courses_pq.top()[0] > course[0]) {
            // Case B. If
            //   1) The current Course cannot be added - CANNOT be finished by the required time if starting now
            //   2) The current Course has HIGHER Priority than a taken Course with the Lowest-Priority
            //        - Same as the fact that the current Course is SHORTER than the LONGEST taken Course
            //        -> Makes sense to SWAP them (Drop the prior one and take the current one)
            //        => SAFE DUE TO THE ORDERING

            // Dropping a taken Course with the Lowest-Priority (The longest one / The one with the longest Duration)
            current_end_time -= taken_courses_pq.top()[0];
            taken_courses_pq.pop();

            // Changing the Current End-Time and Adding the current Course to the Schedule
            current_end_time += course[0];
            taken_courses_pq.push(course);
        }
    }

    // Returning the number of all the taken Courses in the Schedule
    return taken_courses_pq.size();
}

// ---------------------------------------------------------------------------------------------------------------------
// Tester
// ---------------------------------------------------------------------------------------------------------------------

int main() {
    // Input: [[5,5],[4,6],[2,6]]
    // Output: 2
    vector<vector<int>> courses{{5, 5}, {4, 6}, {2, 6}};

    courses_pq pq;

    for (vector<int> const &course : courses) pq.push(course);

    cout << pq.top()[0] << " " << pq.top()[1] << endl;

    cout << max_course_schedule(courses) << endl;

    return 0;
}
