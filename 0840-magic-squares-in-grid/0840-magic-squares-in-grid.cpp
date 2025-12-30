class Solution {
public:
    int n, m;
    bool isValid(unordered_set<int>& numbers) {
        for (int i = 1; i <= 9; ++i) {
            if (!numbers.count(i)) {
                return false;
            }
        }

        return true;
    }
    bool isMagic(int x, int y, vector<vector<int>>& grid) {
        if (x + 2 >= n || y + 2 >= m) {
            return false;
        }
        unordered_set<int> sums, numbers;
        for (int i = 0; i < 3; ++i) {
            int sum = 0;
            for (int j = 0; j < 3; ++j) {
                sum += grid[x + i][y + j];
                numbers.insert(grid[x + i][y + j]);
            }
            sums.insert(sum);
            if (sums.size() > 1) {
                return false;
            }
        }

        if (!isValid(numbers)) {
            return false;
        }

        for (int i = 0; i < 3; ++i) {
            int sum = 0;
            for (int j = 0; j < 3; ++j) {
                sum += grid[x + j][y + i];
            }
            sums.insert(sum);
            if (sums.size() > 1) {
                return false;
            }
        }
        int diag1 = 0;
        int diag2 = 0;
        for (int i = 0; i < 3; ++i) {
            diag1 += grid[x + i][y + i];
            diag2 += grid[x + i][y + 2 - i];
        }
        sums.insert(diag1);
        sums.insert(diag2);

        return sums.size() == 1;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ans += isMagic(i, j, grid);
            }
        }

        return ans;
    }
};