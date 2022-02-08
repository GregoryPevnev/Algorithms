// Reference: https://leetcode.com/problems/k-highest-ranked-items-within-a-price-range/
//  + https://leetcode.com/problems/k-highest-ranked-items-within-a-price-range/discuss/1709742/C%2B%2B-priority-queue-%2B-BFS-O(nmlog(k))-Solution

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// ---------------------------------------------------------------------------------------------------------------------
// Solution
// ---------------------------------------------------------------------------------------------------------------------

struct ranked_item {
    int distance;
    int price;
    int row, column;
};

// Returning true if item1 is ranked higher than item2
bool compare_ranked_items(const ranked_item& item1, const ranked_item& item2) {
    if (item1.distance != item2.distance) return (item2.distance - item1.distance) > 0; // Shorter distance -> Higher
    if (item1.price != item2.price) return (item2.price - item1.price) > 0; // Lower price -> Higher
    if (item1.row != item2.row) return (item2.row - item1.row) > 0; // Lower row -> Higher
    return (item2.column - item1.column) > 0; // Lower column -> Higher
}

// Ordering ranked items in ascending order -> Min-Heap (Lowest Priority is the Top)
//    -> Can substitute / check / replace with a Higher Priority item
//    => PQ which contains K highest-priority items and shows the one with the LOWEST priority
struct ranked_item_cmp {
    bool operator()(const ranked_item& item1, const ranked_item& item2) {
        return compare_ranked_items(item1, item2);
    }
};

// Min Priority-Queue -> The top item is the item with the lowest Rank => Check for replacing
typedef priority_queue<ranked_item, vector<ranked_item>, ranked_item_cmp> ranked_items_pq;

// Grid of all items (2D Matrix)
typedef vector<vector<int>> items_grid;

// Coordinates (Row and Column)
typedef pair<int, int> coord;

// Directions for checking adjacent cells
const vector<coord> DIRS = {
        coord(-1, 0),
        coord(1, 0),
        coord(0, -1),
        coord(0, 1)
};

// Checking whether a set of coordinates goes outside of the Grid
bool check_coord(coord& c, const int rows, const int columns) {
    return c.first >= 0 && c.first < rows && c.second >= 0 && c.second < columns;
}

// BFS with Levels
vector<vector<int>> find_k_highest_ranked_items(items_grid& grid, vector<int>& pricing, vector<int>& start, int k) {
    // Setup: Initializing constants

    const int rows = grid.size();
    const int columns = grid[0].size();

    const int low = pricing[0];
    const int high = pricing[1];

    queue<coord> coord_queue;
    ranked_items_pq items_pq;
    vector<vector<bool>> visited(rows, vector<bool>(columns, false)); // Initializing an empty visited table
    int distance = 0; // Distance from the start - Increases with EACH BFS Level

    coord cur_coord;
    coord next_coord;

    int price;
    ranked_item item;
    int size;

    coord_queue.push(coord(start[0], start[1]));

    while(!coord_queue.empty()) {
        size = coord_queue.size();

        while(size--) {
            cur_coord = coord_queue.front();
            coord_queue.pop();

            if (visited[cur_coord.first][cur_coord.second]) continue;

            visited[cur_coord.first][cur_coord.second] = true;

            price = grid[cur_coord.first][cur_coord.second];

            if (price == 0) continue; // Wall -> NOT adding adjacent coordinates

            for(int di = 0; di < DIRS.size(); di++) {
                next_coord = coord(cur_coord.first + DIRS[di].first, cur_coord.second + DIRS[di].second);

                if (check_coord(next_coord, rows, columns)) {
                    coord_queue.push(next_coord);
                }
            }

            if ((price > high) || (price < low)) continue;

            item = ranked_item{distance, price, cur_coord.first, cur_coord.second};

            if (items_pq.size() < k) {
                items_pq.push(item);
            } else if (compare_ranked_items(item, items_pq.top())) {
                items_pq.pop();
                items_pq.push(item);
            }
        }

        distance++;
    }

    vector<vector<int>> results;

    while(!items_pq.empty()) {
        results.push_back(vector<int>{items_pq.top().row, items_pq.top().column});

        items_pq.pop();
    }

    reverse(results.begin(), results.end());

    return results;
}

// ---------------------------------------------------------------------------------------------------------------------
// Tester
// ---------------------------------------------------------------------------------------------------------------------

// Input: grid = [[1,1,1],[0,0,1],[2,3,4]], pricing = [2,3], start = [0,0], k = 3
// Output: [[2,1],[2,0]]

int main() {
    vector<vector<int>> grid = {
            {1, 1, 1},
            {0, 0, 1},
            {2, 3, 4},
    };
    vector<int> pricing = {2,3};
    vector<int> start = {0,0};
    int k = 3;

    vector<vector<int>> results = find_k_highest_ranked_items(grid, pricing, start, k);

    for (vector<vector<int>>::iterator it = results.begin(); it != results.end(); it++) {
        cout << "(" << (*it)[0] << ", " << (*it)[1] << ")" << endl;
    }

    return 0;
}
