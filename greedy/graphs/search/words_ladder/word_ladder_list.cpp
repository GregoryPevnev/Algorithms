// Reference: https://leetcode.com/problems/word-ladder-ii/
// Guides:
//    - https://leetcode.com/problems/word-ladder-ii/discuss/40475/My-concise-JAVA-solution-based-on-BFS-and-DFS
//    - https://leetcode.com/problems/word-ladder-ii/discuss/40434/C%2B%2B-solution-using-standard-BFS-method-no-DFS-or-backtracking
//    - https://leetcode.com/problems/word-ladder-ii/discuss/269012/Python-BFS%2BBacktrack-Greatly-Improved-by-bi-directional-BFS
// Important: This is a makeshift solution - Should really be solved with either
//    1) BFS -> DFS
//    2) BFS -> Backtracking

#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;

void build_ladders(
    unordered_map<string, vector<string>> transitions,
    string current_word,
    string begin_word,
    int min_length,
    vector<string>& current_ladder,
    vector<vector<string>>& ladders
) {
    // NOT the shortest ladder
    if (current_ladder.size() == min_length && current_word != begin_word) return;

    if (current_word == begin_word) {
        vector<string> ladder(current_ladder);

        ladder.push_back(begin_word);

        reverse(ladder.begin(), ladder.end());

        ladders.push_back(ladder);

        return;
    }

    current_ladder.push_back(current_word);

    for (string const &next_word : transitions[current_word]) {
        build_ladders(transitions, next_word, begin_word, min_length, current_ladder, ladders);
    }

    current_ladder.pop_back();
}

vector<vector<string>> find_min_word_ladders(vector<string>& words, string begin_word, string end_word) {
    const int word_length = words[0].size();

    unordered_set<string> available_words(words.begin(), words.end());

    if (available_words.find(end_word) == available_words.end()) {
        return vector<vector<string>>(); // EDGE-CASE
    }

    unordered_set<string> processed_words;

    unordered_map<string, vector<string>> transitions; // Multiple parents are possible
    transitions[begin_word] = vector<string>(); // NO PARENTS

    queue<string> next_words;
    next_words.push(begin_word);

    vector<string> final_words;

    int min_length = 0;

    string current_word, next_word;
    int level_size;

    while (!next_words.empty() && final_words.empty()) {
        level_size = next_words.size();

        min_length++;

        while (level_size--) {
            current_word = next_words.front();
            next_words.pop();

            if (processed_words.find(current_word) != processed_words.end()) continue;

            processed_words.insert(current_word);

            for (int pos = 0; pos < word_length; pos++) {
                next_word = current_word;

                for (char ch = 'a'; ch <= 'z'; ch++) {
                    next_word[pos] = ch;

                    if (next_word == current_word) continue;

                    if (next_word == end_word) {
                        final_words.push_back(current_word);

                        continue;
                    }

                    if (available_words.find(next_word) != available_words.end() && processed_words.find(next_word) == processed_words.end()) {
                        transitions[next_word].push_back(current_word);

                        next_words.push(next_word);
                    }
                }
            }
        }
    }

    vector<vector<string>> ladders;
    vector<string> ladder {end_word};

    for (string const &final_word : final_words) {
        build_ladders(transitions, final_word, begin_word, min_length, ladder, ladders);
    }

    return ladders;
}

void print_ladder(vector<string> ladder) {
    const int ladder_size = ladder.size();

    for (int i = 0; i < ladder_size; i++) {
        cout << ladder[i];

        if (i + 1 != ladder_size) cout << " -> ";
    }

    cout << endl;
}

int main() {
    // Input: words = ["hot","dot","dog","lot","log","cog"], begin_word = "hit", end_word = "cog"
    // Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]

    vector<string> words1{"hot", "dot", "dog", "lot", "log", "cog"};
    string begin_word1 = "hit";
    string end_word1 = "cog";

    vector<vector<string>> ladders1 = find_min_word_ladders(words1, begin_word1, end_word1);

    for (vector<string> const &ladder : ladders1) print_ladder(ladder);

    // Input: words = ["hot","dog","dot"], begin_word = "hot", end_word = "dog"
    // Output: [["hot", "dot", "dog"]]

    vector<string> words2{"hot", "dog", "dot"};
    string begin_word2 = "hot";
    string end_word2 = "dog";

    vector<vector<string>> ladders2 = find_min_word_ladders(words2, begin_word2, end_word2);

    for (vector<string> const &ladder : ladders2) print_ladder(ladder);

    // Input: words = ["ted","tex","red","tax","tad","den","rex","pee"], begin_word = "red", end_word = "tax"
    // Output: [["red","ted","tad","tax"],["red","ted","tex","tax"],["red","rex","tex","tax"]]
    vector<string> words3{"ted","tex","red","tax","tad","den","rex","pee"};
    string begin_word3 = "red";
    string end_word3 = "tax";

    vector<vector<string>> ladders3 = find_min_word_ladders(words3, begin_word3, end_word3);

    for (vector<string> const &ladder : ladders3) print_ladder(ladder);

    return 0;
}
