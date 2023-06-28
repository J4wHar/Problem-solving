class Solution {
public:
    int splitNum(int num) {
        string s = to_string(num);
        vector<char> v;
        for(auto x:s){
            v.push_back(x);
        }
        sort(v.begin() , v.end());
        string n1="" , n2="";
        for(int i=0;i<v.size();++i){
            if(i&1){
                n2 += v[i];
            }else{
                n1 += v[i];
            }
        }
        return stoi(n1) + stoi(n2);
    }
};