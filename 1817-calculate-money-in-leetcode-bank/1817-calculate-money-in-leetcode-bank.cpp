class Solution {
public:
int totalMoney(int n) {
    int sum = 0;
    int monday = 0;
    int cur = 0;
    for (int i=1;i<=n;++i){
        if (i%7 == 1){
            cur = ++monday;
            sum += monday;
        }else{
            sum += ++cur;
        }
    }

    return sum;
}
};