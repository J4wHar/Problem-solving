class Solution {
public:
    deque<int> d;
    void prepareDeque(vector<vector<int>>& matrix, int l, int r){
        for(int i=r;i>=l;--i){
            d.push_back(matrix[i][l]);
        }
        for(int i=l;i<=r;++i){
            d.push_back(matrix[l][i]);
        }
        for(int i=l;i<=r;++i){
            d.push_back(matrix[i][r]);
        }
        for(int i=r;i>=l;--i){
            d.push_back(matrix[r][i]);
        }
    }
    void transformMatrix(vector<vector<int>>& matrix, int l, int r){
        for(int i=l;i<=r;++i){
            matrix[l][i] = d.front();
            d.pop_front();
        }
        for(int i=l;i<=r;++i){
            matrix[i][r] = d.front();
            d.pop_front();
        }
        for(int i=r;i>=l;--i){
            matrix[r][i] = d.front();
            d.pop_front();
        }
        for(int i=r;i>=l;--i){
            matrix[i][l] = d.front();
            d.pop_front();
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        int l = 0;
        int n = matrix.size();
        int r = n-1;
        while(l < r){
            prepareDeque(matrix, l, r);
            transformMatrix(matrix, l, r);
            ++l;
            --r;
        }
    }
};