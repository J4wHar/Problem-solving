class Solution {
public:
    int countCollisions(string directions) {
        stack<char> s;
        int ans = 0;
        for (auto& x : directions) {
            if (s.empty()) {
                s.push(x);
            } else {
                if (s.top() == 'S') {
                    if (x == 'L') {
                        ++ans;
                    } else {
                        s.push(x);
                    }
                } else if (s.top() == 'L') {
                    s.push(x);
                } else {
                    if (x == 'L') {
                        ans += 2;
                        s.pop();
                        while (!s.empty() && s.top() == 'R') {
                            ++ans;
                            s.pop();
                        }
                        s.push('S');
                    } else if (x == 'S') {
                        while (!s.empty() && s.top() == 'R') {
                            ++ans;
                            s.pop();
                        }
                        s.push('S');
                    } else {
                        s.push(x);
                    }
                }
            }
        }

        return ans;
    }
};