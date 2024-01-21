public class Solution {
    int[] memo = new int[103];
    private int Solve(int i, int[] nums)
    {
        if(i >= nums.Length)
        {
            return 0;
        }
        if(memo[i] != -1)
        {
            return memo[i];
        }
        return memo[i] = Math.Max(nums[i] + Solve(i+2, nums), 
                                 Solve(i+1, nums));
    }
    public int Rob(int[] nums) {
        int n = nums.Length;
        for(int i=0;i<=n;i++)
        {
            memo[i] = -1;
        }
        return Solve(0, nums);
    }
}