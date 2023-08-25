class Solution {
public:
    int strStr(string haystack, string needle) {
        string temp = "";
        int k = needle.size();
        int n = haystack.size();
        int ans = 1e5;
        if(n<k){
            return -1;
        }
        for(int i=n-1;i>=0;--i){
            if(i >= n-k){
                temp = haystack[i] + temp;
                if(temp == needle){
                    ans = min(ans, i);
                }
            }else{
                temp = haystack[i] + temp;
                temp.pop_back();
                if(temp == needle){
                ans = min(ans, i);
                }
            }
            
        }
        if(ans == 1e5){
            return -1;
        }
        return ans;
    }
};