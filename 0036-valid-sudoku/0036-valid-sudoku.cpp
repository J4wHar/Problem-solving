class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //loop over rows
        for(int i=0;i<9;++i){
            set<char> s;
            int cnt = 0;
            for(int j=0;j<9;++j){
                if(board[i][j] != '.'){
                    s.insert(board[i][j]);
                    ++cnt;
                }
            }
            if(s.size() != cnt){
                return false;
            }
        }
        //loop over columns
        for(int j=0;j<9;++j){
            set<char> s;
            int cnt = 0;
            for(int i=0;i<9;++i){
                if(board[i][j] != '.'){
                    s.insert(board[i][j]);
                    ++cnt;
                }
            }
            if(s.size() != cnt){
                return false;
            }
        }
        //loop over 3x3 sub-boxes
        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){
                set<char> s;
                int cnt = 0;
                for(int x=i;x<i+3;++x){
                    for(int y=j;y<j+3;++y){
                        if(board[x][y] != '.'){
                            s.insert(board[x][y]);
                            ++cnt;
                        }
                    }
                }
                if(s.size() != cnt){
                    return false;
                }
            }
        }
        return true;
    }
};