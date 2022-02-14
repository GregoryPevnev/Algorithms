// Reference: https://leetcode.com/problems/word-ladder/
// Guide: https://leetcode.com/problems/word-ladder/discuss/40707/C%2B%2B-BFS

#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

int min_word_ladder(vector<string>& words, string begin_word, string end_word) {
    const int word_length = words[0].size();

    unordered_set<string> available_words(words.begin(), words.end());
    available_words.erase(begin_word); // Note: For safety - Begin-Word could or could NOT be included in the words set

    queue<string> next_words;
    next_words.push(begin_word);

    int words_count = 0;

    string current_word, next_word;
    int level_size;

    while (!next_words.empty()) {
        level_size = next_words.size();

        words_count++;

        while (level_size--) {
            current_word = next_words.front();
            next_words.pop();

            if (current_word == end_word) {
                return words_count;
            }

            for (int pos = 0; pos < word_length; pos++) {
                next_word = current_word;

                for (char ch = 'a'; ch <= 'z'; ch++) {
                    next_word[pos] = ch;

                    if (available_words.find(next_word) != available_words.end()) {
                        available_words.erase(next_word);

                        next_words.push(next_word);
                    }
                }
            }
        }
    }

    return 0; // No ladder found
}

int main() {
    // Input: words = ["hot","dot","dog","lot","log","cog"], begin_word = "hit", end_word = "cog"
    // Output: 5
    vector<string> words{"hot", "dot", "dog", "lot", "log", "cog"};
    string begin_word = "hit";
    string end_word = "cog";
    cout << min_word_ladder(words, begin_word, end_word) << endl;

    return 0;
}
