class Solution {
public:
    static bool compare(vector<string>& x, vector<string>& y) {
        if (stoi(x[1]) == stoi(y[1])){
            if (x[0] == "OFFLINE"){
                return true;
            }
            return false;
        }
        return stoi(x[1]) < stoi(y[1]);
    }
    vector<int> getIds(string& s) {
        vector<int> ans;
        string cur = "";
        for (auto& x : s) {
            if (x == ' ') {
                ans.push_back(stoi(cur));
                cur = "";
            } else if (x == 'i' || x == 'd') {
                continue;
            } else {
                cur += x;
            }
        }
        if (!cur.empty()) {
            ans.push_back(stoi(cur));
        }

        return ans;
    }
    vector<int> getActiveUsers(unordered_map<int, int>& onlineStartingAt,
                               int numberOfUsers, string timestamp) {
        vector<int> ans;
        int time = stoi(timestamp);
        for (int i = 0; i < numberOfUsers; ++i) {
            if (onlineStartingAt[i] <= time) {
                ans.push_back(i);
            }
        }

        return ans;
    }
    vector<int> countMentions(int numberOfUsers,
                              vector<vector<string>>& events) {
        unordered_map<int, int> onlineStartingAt;
        sort(events.begin(), events.end(), compare);
        vector<int> ans(numberOfUsers, 0);
        for (auto& x : events) {
            if (x[0] == "MESSAGE") {
                if (x[2] == "HERE") {
                    vector<int> ids =
                        getActiveUsers(onlineStartingAt, numberOfUsers, x[1]);
                    for (auto& id : ids) {
                        ans[id]++;
                    }
                } else if (x[2] == "ALL") {
                    for (int i = 0; i < numberOfUsers; ++i) {
                        ans[i]++;
                    }
                } else {
                    vector<int> ids = getIds(x[2]);
                    for (auto& id : ids) {
                        ans[id]++;
                    }
                }
            } else {
                onlineStartingAt[stoi(x[2])] = stoi(x[1]) + 60;
            }
        }

        return ans;
    }
};