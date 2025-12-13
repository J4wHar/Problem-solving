class Solution {
public:
    void sortVector(vector<string>& v) { sort(v.begin(), v.end()); }
    vector<string> fillAns(vector<vector<string>> v) {
        vector<string> ans;
        for (auto& x : v) {
            for (auto& y : x) {
                ans.push_back(y);
            }
        }

        return ans;
    }
    bool isValidCode(string& s) {
        if (s.size() == 0) {
            return false;
        }
        for (auto& x : s) {
            if (!isalpha(x) && ((x - '0' < 0) || (x - '0' > 9)) && (x != '_')) {
                return false;
            }
        }

        return true;
    }
    bool isValidBusisnessLine(string& s) {
        return s == "electronics" || s == "grocery" || s == "pharmacy" ||
               s == "restaurant";
    }
    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {
        vector<string> electronics, grocery, pharmacy, restaurant;
        int n = code.size();
        for (int i = 0; i < n; ++i) {
            if (isValidCode(code[i]) && isValidBusisnessLine(businessLine[i]) &&
                isActive[i]) {
                if (businessLine[i] == "electronics") {
                    electronics.push_back(code[i]);
                } else if (businessLine[i] == "grocery") {
                    grocery.push_back(code[i]);
                } else if (businessLine[i] == "pharmacy") {
                    pharmacy.push_back(code[i]);
                } else if (businessLine[i] == "restaurant") {
                    restaurant.push_back(code[i]);
                }
            }
        }

        sortVector(electronics);
        sortVector(grocery);
        sortVector(pharmacy);
        sortVector(restaurant);

        return fillAns({electronics, grocery, pharmacy, restaurant});
    }
};