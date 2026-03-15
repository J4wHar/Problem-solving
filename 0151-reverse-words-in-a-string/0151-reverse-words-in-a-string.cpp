class Solution {
public:
    string reverseWords(string s) {
        deque<string> words;
        string word = "";
        for (char c : s) {
            if (c == ' ' && !word.empty()) {
                words.push_front(word);
                word = "";
            } else {
                if (c != ' ') {
                    word += c;
                }
            }
        }
        if (!word.empty()) {
            words.push_front(word);
        }
        string ans = "";
        for (string w : words) {
            ans += w + " ";
        }
        ans.pop_back();

        return ans;
    }
};