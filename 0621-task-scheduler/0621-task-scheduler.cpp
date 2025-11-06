class Solution {
public:
int leastInterval(vector<char>& tasks, int n) {
    unordered_map<char, int> occ;
    for (auto x : tasks) {
        occ[x]++;
    }
    int sizeOfTask = tasks.size(), ans = 0;
    while (sizeOfTask > 0) {
        int cycleSize = 0;
        unordered_set<char> used;
        bool areAllUsed = false;
        while (!areAllUsed){
            char toUse;
            int maxOcc = 0;
            areAllUsed = true;
            for (int i = 0; i < 26; i++) {
                if (occ['A'+i]) areAllUsed &= used.count('A'+i);
                if (used.count('A'+i)){
                    continue;
                }
                if (occ['A'+i] > maxOcc){
                    maxOcc = occ['A'+i];
                    toUse = 'A'+i;
                }
            }
            if (areAllUsed){
                break;
            }
            sizeOfTask--;
            occ[toUse]--;
            used.insert(toUse);
            ans++;
            cycleSize++;
            if (cycleSize == n + 1) {
                break;
            }
        }
        if (sizeOfTask == 0)
            break;
        ans += (n + 1 - cycleSize);
    }
    return ans;
}
};