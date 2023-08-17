class Solution {
public:
    int n,m;
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    bool safe(int x , int y){
        return x>=0 && x<n && y>=0 && y<m;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        n=mat.size();
        m=mat[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(mat[i][j]==0){
                    q.push(make_pair(i,j));
                }else{
                    mat[i][j]=1e6;
                }
            }
        }
        while(!q.empty()){
            pair<int, int> p = q.front();
            q.pop();
            for(int i=0;i<4;++i){
                int x = p.first + dx[i];
                int y = p.second + dy[i];
                if(safe(x, y) && mat[x][y]>1+mat[p.first][p.second]){
                    q.push(make_pair(x, y));
                    mat[x][y] = 1+mat[p.first][p.second];
                }
            }
        }
        return mat;
    }
};