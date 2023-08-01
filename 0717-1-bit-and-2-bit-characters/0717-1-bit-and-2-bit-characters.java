class Solution {
    public boolean isOneBitCharacter(int[] bits) {
        int n = bits.length;
        int i = 0;
        int lastAdded=0;
        while(i < n){
            if(bits[i] == 1){
                lastAdded = 2;
            }else{
                lastAdded = 1;
            }
            i += lastAdded;
        }
        return lastAdded==1;
    }
}