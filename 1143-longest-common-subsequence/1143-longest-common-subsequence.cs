public class Solution {
    private int[,] memo = new int[1001, 1001];
    private int Solve(int i, int j, ref string text1, ref string text2)
    {
        if(i>=text1.Length || j>=text2.Length)
        {
            return 0;
        }
        if(memo[i, j] != -1)
        {
            return memo[i, j];
        }
        if(text1[i] == text2[j])
        {
            return memo[i, j] = 1 + Solve(i+1, j+1, ref text1, ref text2);
        }
        return memo[i, j] = Math.Max(Solve(i+1, j, ref text1, ref text2), 
                                    Solve(i, j+1, ref text1, ref text2));
    }
    public int LongestCommonSubsequence(string text1, string text2) {
        int n = text1.Length;
        int m = text2.Length;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                memo[i,j] = -1;
            }
        }
        return Solve(0, 0, ref text1, ref text2);
    }
}