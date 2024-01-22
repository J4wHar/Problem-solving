public class Solution {
    public int[] FindErrorNums(int[] nums) {
        Dictionary<int, int> occ = new Dictionary<int, int>();
        int[] ans = new int[2];
        int n = nums.Length;
        foreach(int num in nums)
        {
            if(occ.ContainsKey(num))
            {
                occ[num]++;
            }
            else
            {
                occ.Add(num, 1);
            }
        }
        for(int i=1;i<=n;++i)
        {
            if(!occ.ContainsKey(i))
            {
                ans[1] = i;
            }
            else if(occ[i] == 2)
            {
                ans[0] = i;
            }
        }
        return ans;
    }
}