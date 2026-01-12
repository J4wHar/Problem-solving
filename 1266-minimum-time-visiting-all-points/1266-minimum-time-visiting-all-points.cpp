class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;
        int n = points.size();
        for (int i = 1; i < n; ++i) {
            vector<int> curPoint = points[i];
            vector<int> prevPoint = points[i - 1];
            int distX = abs(curPoint[0] - prevPoint[0]);
            int distY = abs(curPoint[1] - prevPoint[1]);
            int path1 = distX + distY;
            int path2 = min(distX, distY) + abs(distX - distY);
            ans += min(path1, path2);
        }

        return ans;
    }
};