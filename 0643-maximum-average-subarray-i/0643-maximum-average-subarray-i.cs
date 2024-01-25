public class Solution {
    public double FindMaxAverage(int[] nums, int k) {
        double sum = 0;
        double ans = -1000000;
        int n = nums.Length;
        for(int i=0;i<n;i++)
        {
            if(i < k)
            {
                sum += nums[i];
                if(i == k-1)
                {
                    ans = sum;
                }
            }
            else
            {
                sum += nums[i];
                sum -= nums[i-k];
                ans = Math.Max(ans, sum);
            }
        }
        return ans/k;
    }
}